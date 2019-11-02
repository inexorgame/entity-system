#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class InRangeFloatEntityTypeProvider
/// @brief Provides an entity type "IN_RANGE_FLOAT".
class InRangeFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type IN_RANGE_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit InRangeFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{IN_RANGE_FLOAT_INPUT, {DataType::FLOAT, Features::INPUT}},
                              {IN_RANGE_FLOAT_MIN, {DataType::FLOAT, Features::INPUT}},
                              {IN_RANGE_FLOAT_MAX, {DataType::FLOAT, Features::INPUT}},
                              {IN_RANGE_FLOAT_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~InRangeFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "IN_RANGE_FLOAT";

    /// The name of the attribute in_range_float_input.
    static constexpr char IN_RANGE_FLOAT_INPUT[] = "in_range_float_input";

    /// The name of the attribute in_range_float_min.
    static constexpr char IN_RANGE_FLOAT_MIN[] = "in_range_float_min";

    /// The name of the attribute in_range_float_max.
    static constexpr char IN_RANGE_FLOAT_MAX[] = "in_range_float_max";

    /// The name of the attribute in_range_float_result.
    static constexpr char IN_RANGE_FLOAT_RESULT[] = "in_range_float_result";
};

} // namespace inexor::entity_system::type_system
