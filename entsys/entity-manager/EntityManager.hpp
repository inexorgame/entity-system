// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER

#include <vector>

// Entity system debugging.
#include "../../entsys/tests/EntitySystemDebugging.hpp"

// Entity types and instances of those.
#include "entity-types-manager\EntityTypeManager.hpp"
#include "entity-types-manager\EntityTypeInstanceManager.hpp"

// Entity attribute types and instances of those.
#include "entity-attributes-manager\EntityAttributeTypeManager.hpp"
#include "entity-attributes-manager\EntityAttributeTypeInstanceManager.hpp"

// Entity relation types and instances of those.
#include "entity-relations-manager\EntityRelationTypeManager.hpp"
#include "entity-relations-manager\EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    // The entity manager class is responsible for adding, modifying and removing entity types,
    // entity attributes, entity relations and instances of these.
    class EntityManager : public EntityTypeManager,
                          public EntityTypeInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeTypeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationTypeInstanceManager
    {

        protected:
        
			//
            EntityManager();

			//
            ~EntityManager();

		public:
			
			// TODO: implement!

			// 
            ENTSYS_RETURN_CODE link_attribute_type_to_entity_type(const EntityType&, const EntityAttributeType&);
            
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
