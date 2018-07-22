// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"

namespace inexor {
namespace entsys {


    EntityAttributeType::EntityAttributeType()
    {
    }


    EntityAttributeType::EntityAttributeType(const std::string& attr_type_name)
    {
        set_name(attr_type_name);
    }


    EntityAttributeType::EntityAttributeType(const ENTSYS_DATA_TYPE& attr_type_data_type)
    {
        set_data_type(attr_type_data_type);
    }


    EntityAttributeType::EntityAttributeType(const std::string& attr_type_name, const ENTSYS_DATA_TYPE& attr_type_data_type)
    {
        set_name(attr_type_name);
        set_data_type(attr_type_data_type);
    }


    EntityAttributeType::~EntityAttributeType()
    {
    }


    const ENTSYS_RETURN_CODE EntityAttributeType::set_name(const std::string& name)
    {
        if(name.length() > 0)
        {
            entity_attribute_type_name = name;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }


    const ENTSYS_RETURN_CODE EntityAttributeType::set_data_type(const ENTSYS_DATA_TYPE& type)
    {
        entity_attribute_data.set_data_type(type);
        return ENTSYS_RETURN_SUCCESS;
    }
    

    const ENTSYS_DATA_TYPE EntityAttributeType::get_data_type() const
    {
        return entity_attribute_data.get_data_type();
    }
    
    const std::string EntityAttributeType::get_name() const
    {
        return entity_attribute_type_name;
    }

};
};
