#pragma once

#include "entity-system/managers/EntityManager.hpp"
#include "entity-system/managers/RelationManager.hpp"
#include "entity-system/managers/BuilderFactoryManager.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace entity_system {

	/// @class EntitySystemModule
	/// @brief The entity system module.
	class EntitySystemModule
	{
		public:

			using EntityManagerPtr = std::shared_ptr<EntityManager>;
			using RelationManagerPtr = std::shared_ptr<RelationManager>;
			using BuilderFactoryManagerPtr = std::shared_ptr<BuilderFactoryManager>;
			using LogManagerPtr = std::shared_ptr<logging::LogManager>;

			/// @brief Constructs the entity system module.
			/// @note The dependencies of this class will be injected automatically.
			/// @param entity_manager The manager for entity types and entity instances.
			/// @param relation_manager The manager for relation types and relation instances.
			/// @param builder_factory_manager The manager for the builder factories.
			/// @param log_manager The log manager.
			EntitySystemModule(
				EntityManagerPtr entity_manager,
				RelationManagerPtr relation_manager,
				BuilderFactoryManagerPtr builder_factory_manager,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~EntitySystemModule();

			/// @brief Resets the entire entity system.
			/// @note Order of destruction:
			/// <ul>
			///   <li> Relations
			///   <li> Entities
			/// </ul>
			void reset_entity_system();

		private:

			/// The manager for entity types and entity instances.
			EntityManagerPtr entity_manager;

			/// The manager for relation types and relation instances.
			RelationManagerPtr relation_manager;

			/// The manager for the builder factories.
			BuilderFactoryManagerPtr builder_factory_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.entsys";

	};

}
}
