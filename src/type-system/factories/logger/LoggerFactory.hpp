#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/logger/LoggerEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using namespace std;

namespace inexor {
namespace logging {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class LoggerFactory
    /// @brief Management of the loggers.
	class LoggerFactory
	{
		public:

			/// Constructor.
			LoggerFactory(
				shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider,
				shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory,
				shared_ptr<EntityInstanceManager> entity_instance_manager
			);

			/// Destructor.
			~LoggerFactory();

			/// Initialization of the loggers
			EntityInstancePtrOpt create_instance();

			/// Creates an instance and sets the given name
			EntityInstancePtrOpt create_instance(string logger_name);

			/// Creates an instance and sets the given name
			EntityInstancePtrOpt create_instance(string logger_name, spdlog::level::level_enum log_level);

			/// Creates multiple instances
			vector<ENT_INST> create_instances(int count);

		private:

			/// The entity type provider
			shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory;

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

	};


};
};