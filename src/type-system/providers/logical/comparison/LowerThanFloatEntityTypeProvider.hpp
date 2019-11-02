#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class LowerThanFloatEntityTypeProvider
/// @brief Provides an entity type "LOWER_THAN_FLOAT".
class LowerThanFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type LOWER_THAN_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit LowerThanFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{LOWER_THAN_FLOAT_INPUT_1, {DataType::FLOAT, Features::INPUT}}, {LOWER_THAN_FLOAT_INPUT_2, {DataType::FLOAT, Features::INPUT}}, {LOWER_THAN_FLOAT_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~LowerThanFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "LOWER_THAN_FLOAT";

    /// The name of the attribute lower_than_float_input_1.
    static constexpr char LOWER_THAN_FLOAT_INPUT_1[] = "lower_than_float_input_1";

    /// The name of the attribute lower_than_float_input_1.
    static constexpr char LOWER_THAN_FLOAT_INPUT_2[] = "lower_than_float_input_2";

    /// The name of the attribute lower_than_float_result.
    static constexpr char LOWER_THAN_FLOAT_RESULT[] = "lower_than_float_result";
};

} // namespace inexor::entity_system::type_system
