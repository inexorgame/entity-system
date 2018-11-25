// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../entity-type-manager/entity-type/EntityType.hpp"
#include "../../templates/TypeManager.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for entity types.
	class EntityTypeManager : public TypeManager<EntityType>
	{
		private:

			// This error entity type will be returned when a method fails.
			// Use C++11 class member initialisation instead of constructor.
			const ENT_TYPE entity_type_error = std::make_shared<EntityType>("ERROR");

		protected:

			// 
			EntityTypeManager();

			// 
			~EntityTypeManager();
		
		public:

			// Check if an entity type does already exist.
			bool does_entity_type_exist(const std::string&);
			bool does_entity_type_exist(const ENT_TYPE&);
			// TODO: Check by UUID!

			// Create a new entity type.
			ENT_TYPE create_entity_type(const std::string&);

			// Get the number of existing entity types.
			std::size_t get_entity_types_count() const;
			
			// Delete an entity type.
			void delete_entity_type(const std::string&);
			void delete_entity_type(const ENT_TYPE&);
			// TODO: Delete by UUID.

			// Remove all entity types.
			void delete_all_entity_types();

	};


};
};
