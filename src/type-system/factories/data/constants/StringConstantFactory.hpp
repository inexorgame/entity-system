#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/constants/StringConstantEntityTypeProvider.hpp"

#include <memory>
#include <optional>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using StringConstantEntityTypeProviderPtr = std::shared_ptr<StringConstantEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @class StringConstantFactory
    /// @brief Factory for creating entity instances of type STRING_CONSTANT.
	class StringConstantFactory
	{
		public:

			/// @brief Constructs a factory for creating entity instances of type STRING_CONSTANT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type STRING_CONSTANT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			StringConstantFactory(
				StringConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~StringConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values.
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an STRING_CONSTANT with the given constant name and the given value.
            /// @param name ?
            /// @param value ?
			EntityInstancePtrOpt create_instance(const std::string& name, const std::string& value);

		private:

			/// Provides the entity type STRING_CONSTANT.
			StringConstantEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
