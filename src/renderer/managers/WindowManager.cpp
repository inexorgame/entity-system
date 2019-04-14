#include "WindowManager.hpp"

#include <Magnum/Platform/GLContext.h>

#include <GLFW/glfw3.h>

#include "react/Observer.h"
#include "react/Signal.h"

#include "spdlog/spdlog.h"

#include <utility>

namespace inexor {
namespace renderer {

	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstanceOpt = std::optional<EntityAttributeInstancePtr>;

	WindowManager::WindowManager(
		WindowFactoryPtr window_factory,
		KeyboardInputManagerPtr keyboard_input_manager,
		MouseInputManagerPtr mouse_input_manager,
		EntityInstanceManagerPtr entity_instance_manager,
		ConnectorManagerPtr connector_manager,
		WorldRendererPtr world_renderer,
		UserInterfaceRendererPtr user_interface_renderer,
		LogManagerPtr log_manager
	) {
		this->window_factory = window_factory;
		this->keyboard_input_manager = keyboard_input_manager;
		this->mouse_input_manager = mouse_input_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->connector_manager = connector_manager;
		this->world_renderer = world_renderer;
		this->user_interface_renderer = user_interface_renderer;
		this->log_manager = log_manager;
		this->window_count = 0;
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		// Initialize the world renderer
		world_renderer->init();

		// TODO: Initialize the user interface renderer
		user_interface_renderer->init();

		create_window("Test 1", 0, 0, 300, 300);
		create_window("Test 2", 300, 0, 300, 300);
		create_window("Test 3", 0, 300, 300, 300);
		create_window("Test 4", 300, 300, 300, 300);
//		create_window("Test 5", 0, 0, 300, 300);
//		create_window("Test 6", 300, 0, 300, 300);
//		create_window("Test 7", 0, 300, 300, 300);
//		create_window("Test 8", 300, 300, 300, 300);
//		create_window("Test 9", 0, 0, 300, 300);
//		create_window("Test 10", 300, 0, 300, 300);
//		create_window("Test 11", 0, 300, 300, 300);
//		create_window("Test 12", 300, 300, 300, 300);
	}

	void WindowManager::shutdown()
	{
		spdlog::info("Shutting down {} open windows", windows.size());
		for (auto& kv : windows) {
			spdlog::info("shutting down window {}", std::get<DataType::STRING>(kv.first->get_attribute_instance(WindowEntityTypeProvider::WINDOW_TITLE).value()->own_value.Value()));
			destroy_window(kv.first);
		}

		user_interface_renderer->shutdown();
		world_renderer->shutdown();
	}

	/// @brief Creates a new window with the given title, position and dimensions.
	/// @param window The GLFWwindow instance.
	EntityInstancePtr WindowManager::create_window(std::string title, int x, int y, int width, int height)
	{
		return create_window(title, x, y, width, height, 1.0f);
	}

	/// @brief Creates a new window with the given title, position and dimensions.
	/// @param window The GLFWwindow instance.
	EntityInstancePtr WindowManager::create_window(std::string title, int x, int y, int width, int height, float opacity)
	{

		spdlog::get(WindowManager::LOGGER_NAME)->info("Creating window: '{}' ({}, {}) ({}x{})", title, x, y, width, height);

		// Create a windowed mode window and its OpenGL context.
		// Unlike SDL2, GLFW requires at least version 3.2 to be able to request a core profile.

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		GLFWwindow* const glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (glfw_window)
		{
			glfwSetWindowPos(glfw_window, x, y);

			EntityInstancePtrOpt o_window = window_factory->create_instance(title, x, y, width, height, opacity);
			if (o_window.has_value())
			{
				EntityInstancePtr window = o_window.value();

				std::thread window_thread(&renderer::WindowManager::start_window_thread, this, window);
				window_thread.detach();

				// Track the glfw window and the entity instance.
				windows[window] = std::make_pair(glfw_window, std::move(window_thread));
				window_entities[glfw_window] = window;
				// window_position_changed[window] = std::make_pair(x, y);

				// Set the window's user pointer to the window manager
				glfwSetWindowUserPointer(glfw_window, this);

				// Register the close callback
				glfwSetWindowCloseCallback(glfw_window, [] (GLFWwindow* _glfw_window) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_closed(_glfw_window);
				});

				// Register the focus callback
				glfwSetWindowFocusCallback(glfw_window, [] (GLFWwindow* _glfw_window, int has_focus) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_focused(_glfw_window, has_focus == GLFW_TRUE);
				});

				// Register the iconify callback
				glfwSetWindowIconifyCallback(glfw_window, [] (GLFWwindow* _glfw_window, int is_iconified) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_iconified(_glfw_window, is_iconified == GLFW_TRUE);
				});

				// Register the maximize callback
				glfwSetWindowMaximizeCallback(glfw_window, [] (GLFWwindow* _glfw_window, int is_maximized) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_maximized(_glfw_window, is_maximized == GLFW_TRUE);
				});

				// Register the window size callback
				glfwSetWindowPosCallback(glfw_window, [] (GLFWwindow* _glfw_window, int x, int y) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_position_changed(_glfw_window, x, y);
				});

				// Register the window size callback
				glfwSetWindowSizeCallback(glfw_window, [] (GLFWwindow* _glfw_window, int width, int height) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_size_changed(_glfw_window, width, height);
				});

				// Register the key callback
				glfwSetKeyCallback(glfw_window, [] (GLFWwindow* _glfw_window, int key, int scancode, int action, int mods) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_key_changed(_glfw_window, key, scancode, action, mods);
				});

				// Register the mouse position callback
				glfwSetCursorPosCallback(glfw_window, [] (GLFWwindow* _glfw_window, double xpos, double ypos) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_mouse_position_changed(_glfw_window, xpos, ypos);
				});

				// Register the mouse button callback
				glfwSetMouseButtonCallback(glfw_window, [] (GLFWwindow* _glfw_window, int button, int action, int mods) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_mouse_button_changed(_glfw_window, button, action, mods);
				});

				// Register the mouse scroll callback
				glfwSetScrollCallback(glfw_window, [] (GLFWwindow* _glfw_window, double xoffset, double yoffset) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_mouse_scroll_changed(_glfw_window, xoffset, yoffset);
				});

				///
				initialize_window_observers(window);

				// Set window opacity
				glfwSetWindowOpacity(glfw_window, opacity);

				glfwShowWindow(glfw_window);

				window_count++;
				spdlog::get(WindowManager::LOGGER_NAME)->info("Window count: {}", window_count);

				// TODO: return an std::optional!
				return window;

			} else {
				spdlog::get(WindowManager::LOGGER_NAME)->error("Failed to create entity instance!");
				// TODO: return an std::optional!
				return nullptr;
			}
		} else {
			spdlog::get(WindowManager::LOGGER_NAME)->error("Failed to create window!");
			// TODO: return an std::optional!
			return nullptr;
		}
	}

	/// @brief Destroys the given window.
	/// @param window The entity instance of type WINDOW.
	void WindowManager::destroy_window(EntityInstancePtr window)
	{
		std::thread window_thread = std::move(windows[window].second);
		GLFWwindow *glfw_window = windows[window].first;

		spdlog::info("Attempting to close window!");

		// Signal window to be closed
		if (glfw_window != nullptr)
		{
			glfwSetWindowShouldClose(glfw_window, GLFW_TRUE);

			// Wait for window thread state being released
			while(window_thread_state[window])
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}

			spdlog::info("Window thread state false!");
		} else {
			// TODO: kill window_thread !
		}
	}


	void WindowManager::close_window(EntityInstancePtr window)
	{
		glfwSetWindowShouldClose(windows[window].first, GLFW_TRUE);
	}

	void WindowManager::set_window_size(EntityInstancePtr window, int width, int height)
	{
		set_window_size(windows[window].first, width, height);
	}

	void WindowManager::set_window_size(GLFWwindow* glfw_window, int width, int height)
	{
		glfwSetWindowSize(glfw_window, width, height);
	}

	void WindowManager::initialize_window_observers(EntityInstancePtr window)
	{
		GLFWwindow *glfw_window = windows[window].first;

		Observe(
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_FULLSCREEN).value()->value,
			[glfw_window, window] (DataValue fullscreen) {
				spdlog::info("fullscreen {}", std::get<DataType::BOOL>(fullscreen) ? "true" : "false");
				if (std::get<DataType::BOOL>(fullscreen)) {
					GLFWmonitor* glfw_monitor = glfwGetPrimaryMonitor();
					const GLFWvidmode* glfw_mode = glfwGetVideoMode(glfw_monitor);
					glfwSetWindowMonitor(glfw_window, glfw_monitor, 0, 0, glfw_mode->width, glfw_mode->height, glfw_mode->refreshRate);
				} else {
					int x = std::get<DataType::INT>(window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_X).value()->value.Value());
					int y = std::get<DataType::INT>(window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_Y).value()->value.Value());
					int width = std::get<DataType::INT>(window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_X).value()->value.Value());
					int height = std::get<DataType::INT>(window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_Y).value()->value.Value());
					glfwSetWindowMonitor(glfw_window, nullptr, x, y, width, height, 0);
				}
			}
		);

		Observe(
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_ICONIFIED).value()->value,
			[glfw_window] (DataValue iconified) {
				spdlog::info("iconified {}", std::get<DataType::BOOL>(iconified) ? "true" : "false");
				if (std::get<DataType::BOOL>(iconified)) {
					glfwIconifyWindow(glfw_window);
				} else {
					glfwRestoreWindow(glfw_window);
				}
			}
		);

		Observe(
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_MAXIMIZED).value()->value,
			[glfw_window] (DataValue maximized) {
				spdlog::info("maximized {}", std::get<DataType::BOOL>(maximized) ? "true" : "false");
				if (std::get<DataType::BOOL>(maximized)) {
					glfwMaximizeWindow(glfw_window);
				} else {
					glfwRestoreWindow(glfw_window);
				}
			}
		);

		signal_position_changed[window] = MakeSignal<D>(
			With(
				window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_X).value()->value,
				window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_Y).value()->value
			),
			[glfw_window, this, window] (DataValue position_x, DataValue position_y) {
				spdlog::info("(1) position_x {} position_y {}", std::get<DataType::INT>(position_x), std::get<DataType::INT>(position_y));
				return std::make_pair(std::get<DataType::INT>(position_x), std::get<DataType::INT>(position_y));
			}
		);

		auto observer_position_changed = Observe(
			signal_position_changed[window],
			[glfw_window] (std::pair<int, int> position) {
				spdlog::info("(2) position_x {} position_y {}", position.first, position.second);
				glfwSetWindowPos(glfw_window, position.first, position.second);
			}
		);

		signal_size_changed[window] = MakeSignal<D>(
			With(
				window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_WIDTH).value()->value,
				window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_HEIGHT).value()->value
			),
			[glfw_window, this, window] (DataValue width, DataValue height) {
				spdlog::info("(1) width {} height {}", std::get<DataType::INT>(width), std::get<DataType::INT>(height));
				return std::make_pair(std::get<DataType::INT>(width), std::get<DataType::INT>(height));
			}
		);

		auto observer_size_changed = Observe(
			signal_size_changed[window],
			[glfw_window] (std::pair<int, int> size) {
				spdlog::info("(2) width {} height {}", size.first, size.second);
				glfwSetWindowSize(glfw_window, size.first, size.second);
			}
		);

		Observe(
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_OPACITY).value()->value,
			[glfw_window] (DataValue opacity) {
				glfwSetWindowOpacity(glfw_window, std::get<DataType::FLOAT>(opacity));
			}
		);
		// TODO:
		// WindowEntityTypeProvider::WINDOW_VISIBLE
	}

	void WindowManager::window_closed(GLFWwindow* glfw_window)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window closed!");
	}

	void WindowManager::window_focused(GLFWwindow* glfw_window, bool has_focus)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window focus changed: {}", has_focus);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_FOCUSED).value()->own_value.Set(has_focus);
	}

	void WindowManager::window_iconified(GLFWwindow* glfw_window, bool is_iconified)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window iconification state changed: {}", is_iconified);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_ICONIFIED).value()->own_value.Set(is_iconified);
	}

	void WindowManager::window_maximized(GLFWwindow* glfw_window, bool is_maximized)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window maximize state changed: {}", is_maximized);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_MAXIMIZED).value()->own_value.Set(is_maximized);
	}

	void WindowManager::window_position_changed(GLFWwindow* glfw_window, int x, int y)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window position changed: {}:{}", x, y);
		EntityInstancePtr window = window_entities[glfw_window];
		DoTransaction<D>([window, x, y] {
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_X).value()->own_value.Set(x);
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_Y).value()->own_value.Set(y);
		});
	}

	void WindowManager::window_size_changed(GLFWwindow* glfw_window, int width, int height)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window size changed: {}:{}", width, height);
		EntityInstancePtr window = window_entities[glfw_window];
		DoTransaction<D>([window, width, height] {
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_WIDTH).value()->own_value.Set(width);
			window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_HEIGHT).value()->own_value.Set(height);
		});
	}

	void WindowManager::window_key_changed(GLFWwindow* glfw_window, int key, int scancode, int action, int mods)
	{
		keyboard_input_manager->key_changed(window_entities[glfw_window], key, scancode, action, mods);
	}

	void WindowManager::window_mouse_position_changed(GLFWwindow* glfw_window, double xpos, double ypos)
	{
		mouse_input_manager->mouse_position_changed(window_entities[glfw_window], xpos, ypos);
	}

	void WindowManager::window_mouse_button_changed(GLFWwindow* glfw_window, int button, int action, int mods)
	{
		mouse_input_manager->mouse_button_changed(window_entities[glfw_window], button, action, mods);
	}

	void WindowManager::window_mouse_scroll_changed(GLFWwindow* glfw_window, double xoffset, double yoffset)
	{
		mouse_input_manager->mouse_scroll_changed(window_entities[glfw_window], xoffset, yoffset);
	}

	void WindowManager::start_window_thread(EntityInstancePtr window)
	{
		window_thread_state[window] = true;

		GLFWwindow *glfw_window = windows[window].first;

		// Make the window's context current.
		glfwMakeContextCurrent(glfw_window);

		// Create Magnum context in an isolated scope.
		Magnum::Platform::GLContext ctx{};

		// Loop until the user closes the window.
		while(!glfwWindowShouldClose(glfw_window))
		{
			// Render worlds
			world_renderer->render_worlds(window, glfw_window);

			// TODO: render user interfaces
			user_interface_renderer->render_user_interfaces(window, glfw_window);

			// Render custom on front
			for (std::function renderer_function : window_render_functions[window])
			{
				renderer_function(window, glfw_window);
			}

			// Swap front and back buffers.
			glfwSwapBuffers(glfw_window);

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}

		// Detach the window's current context.
		glfwMakeContextCurrent(nullptr);

		window_thread_state[window] = false;

		spdlog::get(WindowManager::LOGGER_NAME)->info("Window has been closed!");

		// Destroy the glfw window object
		glfwDestroyWindow(glfw_window);

		// Untrack the glfw window
		window_entities.erase(glfw_window);
		spdlog::info("window_entities count: {}", window_entities.size());

		// Untrack the window state change signals
		signal_position_changed.erase(window);
		signal_size_changed.erase(window);

		// Remove render functions
		window_render_functions.erase(window);
		spdlog::info("window_render_functions count: {}", window_render_functions.size());

		// Untrack the entity instance
		windows.erase(window);
		spdlog::info("windows count: {}", windows.size());

		// Untrack the thread state
		window_thread_state.erase(window);
		spdlog::info("window_thread_state count: {}", window_thread_state.size());

		// Delete entity instance
		entity_instance_manager->delete_entity_instance(window);

		window_count--;
		spdlog::get(WindowManager::LOGGER_NAME)->info("Window count: {}", window_count);

	}

	void WindowManager::make_current(EntityInstancePtr window)
	{
		glfwMakeContextCurrent(windows[window].first);
	}

	void WindowManager::register_render_function(EntityInstancePtr window, std::function<void(EntityInstancePtr, GLFWwindow*)> render_function)
	{
		window_render_functions[window].push_back(render_function);
	}

	int WindowManager::get_window_count()
	{
		return window_count;
	}

	GLFWwindow* WindowManager::get_window_handle(EntityInstancePtr window)
	{
		return windows[window].first;
	}

}
}
