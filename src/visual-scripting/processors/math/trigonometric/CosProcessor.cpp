#include "CosProcessor.hpp"

#include <utility>

#include "spdlog/spdlog.h"

#include "type-system/types/math/trigonometric/Cos.hpp"

namespace inexor::visual_scripting {

using Cos = entity_system::type_system::Cos;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

CosProcessor::CosProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), LifeCycleComponent(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

CosProcessor::~CosProcessor() = default;

void CosProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void CosProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(Cos::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", Cos::TYPE_NAME);
    }
}

std::string CosProcessor::get_component_name()
{
    return "CosProcessor";
}

void CosProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void CosProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void CosProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor {} for newly created entity instance {} of type {}", std::string(Cos::TYPE_NAME), entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_cos_input = entity_instance->get_attribute_instance(Cos::INPUT);
    EntityAttributeInstancePtrOpt o_attr_cos_value = entity_instance->get_attribute_instance(Cos::VALUE);

    if (o_attr_cos_input.has_value() && o_attr_cos_value.has_value())
    {
        signals[entity_instance->get_GUID()] = MakeSignal(o_attr_cos_input.value()->value, [](DataValue cos_input) { return entity_system::DataValue(cosf(std::get<DataType::FLOAT>(cos_input))); });
        o_attr_cos_value.value()->signal_wrapper <<= signals[entity_instance->get_GUID()];
        // o_attr_cos_value.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    Cos::INPUT, Cos::VALUE);
    }
}

} // namespace inexor::visual_scripting
