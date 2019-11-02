#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class IntToFloatEntityTypeProvider
/// @brief Provides an entity type "INT_TO_FLOAT" which converts int values to float values.
class IntToFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the INT_TO_FLOAT entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit IntToFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{INT_TO_FLOAT_INPUT, {DataType::INT, Features::INPUT}}, {INT_TO_FLOAT_VALUE, {DataType::FLOAT, Features::OUTPUT}}}){};

    /// Destructor.
    ~IntToFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "INT_TO_FLOAT";

    /// The name of the input attribute int_to_float_input.
    static constexpr char INT_TO_FLOAT_INPUT[] = "int_to_float_input";

    /// The name of the output attribute int_to_float_value.
    static constexpr char INT_TO_FLOAT_VALUE[] = "int_to_float_value";
};

} // namespace inexor::entity_system::type_system
