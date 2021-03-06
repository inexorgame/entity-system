#pragma once

namespace inexor::entity_system::type_system {

class GreaterThanFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "GREATER_THAN_FLOAT";

    /// The name of the input attribute greater_than_float_input_1.
    inline static const std::string INPUT_1 = "greater_than_float_input_1";

    /// The name of the input attribute greater_than_float_input_2.
    inline static const std::string INPUT_2 = "greater_than_float_input_2";

    /// The name of the output attribute greater_than_float_result.
    inline static const std::string RESULT = "greater_than_float_result";
};

} // namespace inexor::entity_system::type_system
