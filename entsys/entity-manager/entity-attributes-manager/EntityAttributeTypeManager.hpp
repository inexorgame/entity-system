// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER

#include <string>
#include <unordered_map>

#include "entity-attribute-type\EntityAttributeType.hpp"
#include "../../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entsys {
    
    // By using these type definitions we can make later definitions shorter.
    typedef std::unordered_map<std::string, EntityAttributeType> ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP;
    typedef ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP::const_iterator     ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP;


    class EntityAttributeTypeManager
    {
        private:

            // In this unordered map all available types of entity attributes will be stored.
            ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP map_of_entity_attribute_types;
            
            // TODO: Debug!
            const ENTSYS_RETURN_CODE search(std::string&) const;
            
        protected:

            // Make this protected so this class can only 
            // be instanced by inheritance as base class.
            EntityAttributeTypeManager();

        public:

            ~EntityAttributeTypeManager();

            // This method adds new types of attributes of entities.
            // Entity attribute type instances can only be created from existing valid 
            // entity attribute types by the entity attribute instance manager.
            const ENTSYS_RETURN_CODE add(const EntityAttributeType&);

            // This method returns the number of existing types of entity attributes available in the entity system.
            const size_t count() const;
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
