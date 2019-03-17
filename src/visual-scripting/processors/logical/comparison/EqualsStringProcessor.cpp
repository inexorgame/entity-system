#include "EqualsStringProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	EqualsStringProcessor::EqualsStringProcessor(
		EqualsStringEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	EqualsStringProcessor::~EqualsStringProcessor()
	{
	}

	void EqualsStringProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void EqualsStringProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void EqualsStringProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void EqualsStringProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor EQUALS_STRING for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		auto o_equals_string_input_1 = entity_instance->get_attribute_instance(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_1);
		auto o_equals_string_input_2 = entity_instance->get_attribute_instance(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_2);
		auto o_equals_string_result = entity_instance->get_attribute_instance(EqualsStringEntityTypeProvider::EQUALS_STRING_RESULT);
		if (o_equals_string_input_1.has_value() && o_equals_string_input_2.has_value() && o_equals_string_result.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_equals_string_input_1.value()->value,
					o_equals_string_input_2.value()->value
				),
				[] (DataValue equals_string_input_1, DataValue equals_string_input_2)
				{
					return DataValue(std::get<DataType::STRING>(equals_string_input_1) == std::get<DataType::STRING>(equals_string_input_2));
				}
			);
			o_equals_string_result.value()->value = signals[entity_instance->get_GUID()];
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_1, EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_2, EqualsStringEntityTypeProvider::EQUALS_STRING_RESULT);
		}
	}

}
}