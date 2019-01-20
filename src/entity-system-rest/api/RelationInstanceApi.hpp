/**
 * Inexor Entity System
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * OpenAPI spec version: 3.0.0
 * Contact: info@inexor.org
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.0.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#pragma once

#include <memory>
#include <crossguid/guid.hpp>
#include <string>
#include <restbed>

#include "spdlog/spdlog.h"

#include "../model/EntitySystemMessage.hpp"
#include "../model/RelationInstance.hpp"

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"

using namespace inexor::entity_system::rest::model;
using namespace restbed;

namespace inexor {
namespace entity_system {
namespace rest {
namespace api {

// Forward declarations
class RelationInstanceApiRelationsInstancesRelation_instance_uuidResource;
class RelationInstanceApiRelationsInstancesResource;
class RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource;
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource;

class  RelationInstanceApi
{
	public:
		RelationInstanceApi(
			std::shared_ptr<RelationInstanceApiRelationsInstancesRelation_instance_uuidResource> spRelationInstanceApiRelationsInstancesRelation_instance_uuidResource,
			std::shared_ptr<RelationInstanceApiRelationsInstancesResource> spRelationInstanceApiRelationsInstancesResource,
			std::shared_ptr<RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource> spRelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource,
			std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource
		);
		~RelationInstanceApi();
		void publish_resources(std::shared_ptr<Service> service);
	private:
		std::shared_ptr<RelationInstanceApiRelationsInstancesRelation_instance_uuidResource> spRelationInstanceApiRelationsInstancesRelation_instance_uuidResource;
		std::shared_ptr<RelationInstanceApiRelationsInstancesResource> spRelationInstanceApiRelationsInstancesResource;
		std::shared_ptr<RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource> spRelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource;
		std::shared_ptr<RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource> spRelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource;
};


/// <summary>
/// Creates (or updates if already exists) a relation instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiRelationsInstancesRelation_instance_uuidResource: public restbed::Resource
{
	public:
		RelationInstanceApiRelationsInstancesRelation_instance_uuidResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiRelationsInstancesRelation_instance_uuidResource();
		void POST_method_handler(const std::shared_ptr<restbed::Session> session);
		void DELETE_method_handler(const std::shared_ptr<restbed::Session> session);
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Creates a relation instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiRelationsInstancesResource: public restbed::Resource
{
	public:
		RelationInstanceApiRelationsInstancesResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiRelationsInstancesResource();
		void POST_method_handler(const std::shared_ptr<restbed::Session> session);
		void DELETE_method_handler(const std::shared_ptr<restbed::Session> session);
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Deletes all relations instances between a start entity instance and an end entity instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource: public restbed::Resource
{
	public:
		RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource();
		void DELETE_method_handler(const std::shared_ptr<restbed::Session> session);
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all incoming and outgoing relation instances of a certain relation type
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all incoming and outgoing relation instances of the entity instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all incoming and outgoing relation instances of a certain relation type
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all incoming relation instances of the entity instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all incoming and outgoing relation instances of a certain relation type
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};

/// <summary>
/// Returns all outgoing relation instances of the entity instance
/// </summary>
/// <remarks>
/// 
/// </remarks>
class RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource: public restbed::Resource
{
	public:
		RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource(
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager
		);
		virtual ~RelationInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource();
		void GET_method_handler(const std::shared_ptr<restbed::Session> session);
	private:
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager;
};


}
}
}
}
