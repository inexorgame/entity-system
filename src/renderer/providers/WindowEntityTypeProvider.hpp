#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace renderer {

	using namespace inexor::entity_system;

	/// @class WindowEntityTypeProvider
	/// @brief Provides an entity type "WINDOW".
	class WindowEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type 'WINDOW'.
			/// @note The dependencies of this class will be injected automatically.
			WindowEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_factory
			) : EntityTypeProvider(
				entity_type_builder_factory,
				TYPE_NAME,
				{
					{ WINDOW_TITLE, { DataType::STRING, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_POSITION_X, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_POSITION_Y, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_WIDTH, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_HEIGHT, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_OPACITY, { DataType::FLOAT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_FULLSCREEN, { DataType::BOOL, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_ICONIFIED, { DataType::BOOL, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_MAXIMIZED, { DataType::BOOL, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ WINDOW_FOCUSED, { DataType::BOOL, 1 << Feature::INPUT | 1 << Feature::OUTPUT } }
				}
			) {};

			/// Destructor.
			~WindowEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "WINDOW";

			/// The name of the attribute window title.
			static constexpr char WINDOW_TITLE[] = "window_title";

			/// The name of the attribute window position x.
			static constexpr char WINDOW_POSITION_X[] = "window_position_x";

			/// The name of the attribute window position y.
			static constexpr char WINDOW_POSITION_Y[] = "window_position_y";

			/// The name of the attribute window width.
			static constexpr char WINDOW_WIDTH[] = "window_width";

			/// The name of the attribute window height.
			static constexpr char WINDOW_HEIGHT[] = "window_height";

			/// The name of the attribute window opacity.
			static constexpr char WINDOW_OPACITY[] = "window_opacity";

			/// The name of the attribute window fullscreen.
			static constexpr char WINDOW_FULLSCREEN[] = "window_fullscreen";

			/// The name of the attribute window iconified.
			static constexpr char WINDOW_ICONIFIED[] = "window_iconified";

			/// The name of the attribute window maximized.
			static constexpr char WINDOW_MAXIMIZED[] = "window_maximized";

			/// The name of the attribute window focused.
			static constexpr char WINDOW_FOCUSED[] = "window_focused";


	};

}
}