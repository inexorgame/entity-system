// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
		// TODO: Implement!
    }


    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
		// TODO: Implement!
    }

	
	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const std::string& param_entity_attribute_type_name)
	{
		// Returns false is entity attribute type does not already exist.
		return !(map_of_entity_attribute_types.end() == map_of_entity_attribute_types.find(param_entity_attribute_type_name.c_str()));
	}

	
	ENTSYS_RESULT EntityAttributeTypeManager::create_entity_attribute_type(const std::shared_ptr<EntityAttributeType>& param_new_entity_attribute_type)
	{
		return ENTSYS_SUCCESS;
	}

	
	std::size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
	{
		return map_of_entity_attribute_types.size();
	}


	ENTSYS_RESULT EntityAttributeTypeManager::delete_entity_attribute_type(const std::string& param_entity_attribute_type)
	{
		// TODO: [CRITICAL] Remove all instances of
		// this entity attribute type before removing
		// the entity attribute type itself!
		map_of_entity_attribute_types.erase(param_entity_attribute_type);
		return ENTSYS_SUCCESS;
	}


	ENTSYS_RESULT EntityAttributeTypeManager::delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
	{
		// TODO: [CRITICAL] Remove all instances of
		// this entity attribute type before removing
		// the entity attribute type itself!
		delete_entity_attribute_type(param_entity_attribute_type->get_entity_attribute_type_name());
		return ENTSYS_SUCCESS;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeTypeManager::validate_attribute_types(const std::vector<std::shared_ptr<EntityAttributeType>>& param_entity_attribute_types)
	{
		ENTSYS_DATA_VALIDATION_RESULT temp_data_validation;

		// Loop through all linked entity attribut types and validate their data.
		for(std::size_t i=0; i<param_entity_attribute_types.size(); i++)
		{		
			temp_data_validation = param_entity_attribute_types[i]->validate();
			if(ENTSYS_DATA_VALID != temp_data_validation) return temp_data_validation;
		}
		return ENTSYS_DATA_VALID;
	}


};
};
