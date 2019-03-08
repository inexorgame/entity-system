#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace renderer {

	using namespace inexor::entity_system;

	/// Provides an entity type "RENDERER".
	class RendererEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the RENERER entity type
			RendererEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ RENDERER_X, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ RENDERER_Y, { DataType::FLOAT, 1 << Feature::INPUT } }
				}
			) {};

			~RendererEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "RENDERER";

			/// The name of the renderer x attribute value.
			static constexpr char RENDERER_X[] = "renderer_x";

			/// The name of the renderer y attribute value.
			static constexpr char RENDERER_Y[] = "renderer_y";

	};

}
}
