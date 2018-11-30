// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <unordered_map>

#include "../../entity-attribute-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../../../templates/TypeVector.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entities.
	// This class needs to implement a data validation method!
	class EntityType : public TypeBase, public TypeVector<EntityAttributeType>
    {
        public:

			// 
			EntityType(const std::string&);

			// 
            ~EntityType();

			// Check if an entity attribute type is already linked to this entity type.
			bool has_attribute_type(const std::string&);
			bool has_attribute_type(const ENT_ATTR_TYPE&);
        
			// Link an entity attribute type to this entity type.
			ENTSYS_RESULT link_attribute_type(const ENT_ATTR_TYPE&);
	
			// Return the number of entity attribute types which are linked to this entity type.
			std::size_t get_linked_attributes_count() const;

			// Return a vector of entity attribute types which are linked to this entity type.
			const std::vector<ENT_ATTR_TYPE> get_linked_attribute_types() const;

			// Delete all entity attribute types which are linked to this entity type.
			void reset_linked_attribute_types();

			// The data validation method of this class.
			// This is required because EntityType inherits from DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };


};
};