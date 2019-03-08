#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "STRING_CONSTANT" which is a pure string constant variable.
	class StringConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the STRING_CONSTANT entity type
			StringConstantEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ STRING_CONSTANT_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ STRING_CONSTANT_VALUE, { DataType::STRING, 1 << Feature::OUTPUT } }
				}
			) {};

			~StringConstantEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "STRING_CONSTANT";

			/// The name of the output attribute string_constant_name
			static constexpr char STRING_CONSTANT_NAME[] = "string_constant_name";

			/// The name of the output attribute string_constant_value
			static constexpr char STRING_CONSTANT_VALUE[] = "string_constant_value";

	};

}
}
}
