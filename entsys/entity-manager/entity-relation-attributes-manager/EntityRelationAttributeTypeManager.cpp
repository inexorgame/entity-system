// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {

	
	EntityRelationAttributeTypeManager::EntityRelationAttributeTypeManager()
	{
	}
	
	
	EntityRelationAttributeTypeManager::~EntityRelationAttributeTypeManager()
	{
	}


	std::shared_ptr<EntityRelationAttributeType>
		EntityRelationAttributeTypeManager::create_entity_relation_attribute_type(
			const std::string& ent_rel_attr_type_name, const ENTSYS_DATA_TYPE& ent_rel_attr_data_type)
	{
		std::shared_ptr<EntityRelationAttributeType> new_ent_rel_attr_type
			= std::make_shared<EntityRelationAttributeType>(ent_rel_attr_type_name, ent_rel_attr_data_type);

		add_type_to_map(ent_rel_attr_type_name, new_ent_rel_attr_type);

		return new_ent_rel_attr_type;
	}


	std::size_t EntityRelationAttributeTypeManager::get_entity_relation_attribute_type_count() const
	{
		// Call base class method.
		return get_type_count();
	}


	void EntityRelationAttributeTypeManager::delete_all_entity_relation_attribute_types()
	{
		// Call base class method.
		delete_all_types();
	}


};
};
