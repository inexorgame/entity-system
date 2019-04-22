#include "MonitorManager.hpp"

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	MonitorManager::MonitorManager(
		MonitorFactoryPtr monitor_factory,
		LogManagerPtr log_manager
	) {
		this->monitor_factory = monitor_factory;
		this->log_manager = log_manager;
	}

	MonitorManager::~MonitorManager()
	{
	}

	void MonitorManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		detect_monitors();
	}

	void MonitorManager::shutdown()
	{
	}

	void MonitorManager::detect_monitors()
	{
		int count_monitors;
		GLFWmonitor** monitors = glfwGetMonitors(&count_monitors);
		for (int i = 0; i < count_monitors; i++)
		{
			EntityInstancePtrOpt o_monitor = create_monitor(monitors[i]);
		}
	}

	/// Detects the monitors.
	EntityInstancePtrOpt MonitorManager::create_monitor(GLFWmonitor* glfw_monitor)
	{
		std::string monitor_name = glfwGetMonitorName(glfw_monitor);
		const GLFWvidmode* mode = glfwGetVideoMode(glfw_monitor);
		int x;
		int y;
		glfwGetMonitorPos(glfw_monitor, &x, &y);
		EntityInstancePtrOpt o_monitor = monitor_factory->create_instance(monitor_name, x, y, mode->width, mode->height, is_primary(glfw_monitor));
		if (o_monitor.has_value())
		{
			EntityInstancePtr monitor = o_monitor.value();
			monitors[monitor] = glfw_monitor;
			spdlog::get(MonitorManager::LOGGER_NAME)->info("Created monitor {} ({}, {}) ({} x {}) {}", monitor_name, x, y, mode->width, mode->height, is_primary(glfw_monitor) ? "[primary]" : "");
			detect_video_modes(monitor);
		}
		return o_monitor;
	}

	void MonitorManager::destroy_monitor(EntityInstancePtr monitor)
	{
		monitors.erase(monitor);
	}

	std::optional<EntityInstancePtr> MonitorManager::get_primary()
	{
		for (auto monitor : monitors)
		{
			if (is_primary(monitor.second))
			{
				return monitor.first;
			}
		}
		return std::nullopt;
	}

	bool MonitorManager::is_primary(EntityInstancePtr monitor)
	{
		return is_primary(monitors[monitor]);
	}

	bool MonitorManager::is_primary(GLFWmonitor* glfw_monitor)
	{
		return glfw_monitor == glfwGetPrimaryMonitor();
	}

	void MonitorManager::detect_video_modes(EntityInstancePtr monitor)
	{
		int count_video_modes;
		const GLFWvidmode* video_modes = glfwGetVideoModes(monitors[monitor], &count_video_modes);
		for (int i = 0; i < count_video_modes; i++)
		{
			GLFWvidmode video_mode = video_modes[i];
			spdlog::get(MonitorManager::LOGGER_NAME)->info("  {} x {} @ {} Hz ({}x{}x{}) ", video_mode.width, video_mode.height, video_mode.refreshRate, video_mode.redBits, video_mode.greenBits, video_mode.blueBits);
		}
	}

	std::optional<Range2Di> MonitorManager::get_monitor_dimensions(EntityInstancePtr monitor)
	{
		return get_monitor_dimensions(monitors[monitor]);
	}

	std::optional<Range2Di> MonitorManager::get_monitor_dimensions(GLFWmonitor* glfw_monitor)
	{
		int x, y;
		glfwGetMonitorPos(glfw_monitor, &x, &y);
		GLFWvidmode *mode = (GLFWvidmode*) glfwGetVideoMode(glfw_monitor);

		if (mode == nullptr)
		{
			// Video mode is required for width and height, so skip this monitor
			return std::nullopt;
		} else {
			return Range2Di({x, y}, { x + mode->width, y+ mode->height});
		}
	}

	std::vector<MonitorRange> MonitorManager::get_all_monitors_and_dimensions()
	{
		std::vector<MonitorRange> monitor_dimensions;
		int monitors_length;
		GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
		if (monitors != nullptr)
		{
			for (int i = 0; i < monitors_length; i++)
			{
				auto monitor_dimension = get_monitor_dimensions(monitors[i]);
				if (monitor_dimension.has_value())
				{
					monitor_dimensions.push_back(std::make_pair(monitors[i], monitor_dimension.value()));
				}
			}
		}
		return monitor_dimensions;
	}

	std::optional<MonitorRange> MonitorManager::monitor_contains_window_center(Range2Di window_dimensions)
	{
		int monitors_length;
		GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
		if (monitors == nullptr) return std::nullopt;
		for (int i = 0; i < monitors_length; i++)
		{
			std::optional<Range2Di> monitor_range = get_monitor_dimensions(monitors[i]);
			// Check if monitor has video mode and the monitor range contains the window center
			if (monitor_range.has_value() && monitor_range->contains(window_dimensions.center()))
			{
				return std::make_pair(monitors[i], monitor_range.value());
			}
		}
		return std::nullopt;
	}

	std::optional<MonitorRange> MonitorManager::monitor_fully_contains_window(Range2Di window_dimensions)
	{
		int monitors_length;
		GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
		if (monitors == nullptr) return std::nullopt;
		for (int i = 0; i < monitors_length; i++)
		{
			std::optional<Range2Di> monitor_range = get_monitor_dimensions(monitors[i]);
			// Check if monitor has video mode and the monitor range contains the full window range
			if (monitor_range.has_value() && monitor_range->contains(window_dimensions))
			{
				return std::make_pair(monitors[i], monitor_range.value());
			}
		}
		return std::nullopt;
	}

	std::optional<EntityInstancePtr> MonitorManager::get_current_monitor_by_window_center(Range2Di window_dimensions)
	{
		int monitors_length;
		GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
		if (monitors == nullptr) return std::nullopt;
		for (int i = 0; i < monitors_length; i++)
		{
			std::optional<Range2Di> monitor_range = get_monitor_dimensions(monitors[i]);
			if (monitor_range.has_value() && monitor_range->contains(window_dimensions.center()))
			{
				return get_by_monitor_handle(monitors[i]);
			}
		}
		return std::nullopt;
	}

	std::optional<EntityInstancePtr> MonitorManager::get_monitor_on_left(EntityInstancePtr monitor)
	{
		std::optional<EntityInstancePtr> next_left = std::nullopt;
		Range2Di next_left_monitor_range;
		std::optional<Range2Di> monitor_range = get_monitor_dimensions(monitor);
		if (monitor_range.has_value())
		{
			int monitors_length;
			GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
			if (monitors == nullptr) return std::nullopt;
			for (int i = 0; i < monitors_length; i++)
			{
				std::optional<EntityInstancePtr> other_monitor = get_by_monitor_handle(monitors[i]);
				std::optional<Range2Di> other_monitor_range = get_monitor_dimensions(monitors[i]);
				if (other_monitor.has_value()
					&& other_monitor_range.has_value()
					&& other_monitor_range->left() < monitor_range->left())
				{
					// other_monitor is left of monitor
					if (!next_left.has_value() || next_left_monitor_range.left() < other_monitor_range->left())
					{
						// other_monitor more near to monitor than next_left_monitor
						next_left = get_by_monitor_handle(monitors[i]);
						next_left_monitor_range = other_monitor_range.value();
					}
				}
			}
		}
		return next_left;
	}

	std::optional<EntityInstancePtr> MonitorManager::get_monitor_on_right(EntityInstancePtr monitor)
	{
		std::optional<EntityInstancePtr> next_right = std::nullopt;
		Range2Di next_right_monitor_range;
		std::optional<Range2Di> monitor_range = get_monitor_dimensions(monitor);
		if (monitor_range.has_value())
		{
			int monitors_length;
			GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);
			if (monitors == nullptr) return std::nullopt;
			for (int i = 0; i < monitors_length; i++)
			{
				std::optional<EntityInstancePtr> other_monitor = get_by_monitor_handle(monitors[i]);
				std::optional<Range2Di> other_monitor_range = get_monitor_dimensions(monitors[i]);
				if (other_monitor.has_value()
					&& other_monitor_range.has_value()
					&& monitor_range->left() < other_monitor_range->left())
				{
					// other_monitor is right of monitor
					if (!next_right.has_value() || other_monitor_range->left() < next_right_monitor_range.left())
					{
						// other_monitor more near to monitor than next_right_monitor
						next_right = get_by_monitor_handle(monitors[i]);
						next_right_monitor_range = other_monitor_range.value();
					}
				}
			}
		}
		return next_right;
	}

	std::optional<MonitorRange> MonitorManager::get_monitor_range(EntityInstancePtr monitor)
	{
		if (monitors.find(monitor) != monitors.end())
		{
			GLFWmonitor* glfw_monitor = monitors[monitor];
			auto monitor_dimension = get_monitor_dimensions(glfw_monitor);
			if (monitor_dimension.has_value())
			{
				return std::make_pair(glfw_monitor, monitor_dimension.value());
			}
		}
		return std::nullopt;
	}

	GLFWmonitor* MonitorManager::get_monitor_handle(EntityInstancePtr monitor)
	{
		return monitors[monitor];
	}

	std::optional<EntityInstancePtr> MonitorManager::get_by_monitor_handle(GLFWmonitor* glfw_monitor)
	{
		for (auto kv : monitors)
		{
			if (kv.second == glfw_monitor) {
				return kv.first;
			}
		}
		return std::nullopt;
	}

}
}
