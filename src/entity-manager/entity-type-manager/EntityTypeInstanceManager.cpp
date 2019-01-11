// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {

    
	EntityTypeInstanceManager::EntityTypeInstanceManager()
		: TypeInstanceManagerTemplate(entity_type_instance_error)
	{
		// TODO: Implement!
	}

	
	EntityTypeInstanceManager::~EntityTypeInstanceManager()
	{
		// TODO: Implement!
	}


	ENT_TYPE_INST EntityTypeInstanceManager::create_entity_type_instance(const ENT_TYPE& ent_type)
	{
		// Create a new entity type instance.
		ENT_TYPE_INST new_ent_type_instance = std::make_shared<EntityTypeInstance>(ent_type);
		
		// Call template base class method.
		add_instance_to_buffer(new_ent_type_instance->get_GUID(), new_ent_type_instance);
		
		return new_ent_type_instance;
	}


	const std::size_t EntityTypeInstanceManager::get_entity_type_instance_count() const
	{
		// Call template base class method.
		return get_type_instance_count();
	}


	void EntityTypeInstanceManager::delete_all_entity_type_instances()
	{
		// Call template base class method.
		delete_all_type_instances();
	}

	/*
	const std::size_t EntityTypeInstanceManager::get_entity_type_instances_count_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}


	const std::vector<ENT_TYPE_INST> EntityTypeInstanceManager::get_all_entity_type_instances() const
	{
		// Call template base class method.
	}


	const std::vector<ENT_TYPE_INST> EntityTypeInstanceManager::get_all_entity_type_instances_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}
	*/

};
};
