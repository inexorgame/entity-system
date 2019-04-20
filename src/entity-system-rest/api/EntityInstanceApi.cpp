#include "EntityInstanceApi.hpp"

namespace inexor {
namespace entity_system {
namespace rest {
namespace api {

using namespace inexor::entity_system::rest::model;
using namespace xg;
using namespace restbed;
using namespace std;

using EntityInstancePtr = std::shared_ptr<inexor::entity_system::EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityAttributeTypePtr = std::shared_ptr<inexor::entity_system::EntityAttributeType>;
using EntityAttributeInstancePtr = std::shared_ptr<inexor::entity_system::EntityAttributeInstance>;

EntityInstanceApi::EntityInstanceApi(
	shared_ptr<EntityInstanceApiEntitiesInstancesResource> spEntityInstanceApiEntitiesInstancesResource,
	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidResource,
	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource,
	shared_ptr<EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource> spEntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource,
	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource,
	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource,
	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource
//	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource,
//	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource,
//	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource,
//	shared_ptr<EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource> spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource
)
{
	this->spEntityInstanceApiEntitiesInstancesResource = spEntityInstanceApiEntitiesInstancesResource;
	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidResource;
	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource;
	this->spEntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource = spEntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource;
	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource;
	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource;
	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource;
//	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource;
//	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource;
//	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource;
//	this->spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource = spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource;
}

EntityInstanceApi::~EntityInstanceApi() {}

void EntityInstanceApi::publish_resources(shared_ptr<Service> service) {
	service->publish(spEntityInstanceApiEntitiesInstancesResource);
	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidResource);
	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource);
	service->publish(spEntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource);
	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource);
	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource);
	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource);
//	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource);
//	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource);
//	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource);
//	service->publish(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource);
}

void EntityInstanceApi::suppress_resources(shared_ptr<Service> service) {
	service->suppress(spEntityInstanceApiEntitiesInstancesResource);
	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidResource);
	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource);
	service->suppress(spEntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource);
	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource);
	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource);
	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource);
//	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource);
//	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource);
//	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource);
//	service->suppress(spEntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource);
}

EntityInstanceApiEntitiesInstancesResource::EntityInstanceApiEntitiesInstancesResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/");
	this->set_method_handler("POST", bind(&EntityInstanceApiEntitiesInstancesResource::POST_method_handler, this, placeholders::_1));
	this->set_method_handler("DELETE", bind(&EntityInstanceApiEntitiesInstancesResource::DELETE_method_handler, this, placeholders::_1));
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesResource::~EntityInstanceApiEntitiesInstancesResource()
{
}

void EntityInstanceApiEntitiesInstancesResource::POST_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
	// Body params are present, therefore we have to fetch them
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const shared_ptr<Session> session, const Bytes & body )
		{

			const auto request = session->get_request();
			string requestBody = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			/**
			 * Get body params or form params here from the requestBody string
			 */
			
			

			
			// Change the value of this variable to the appropriate response before sending the response
			int status_code = 200;
			
			/**
			 * Process the received information here
			 */
			
			if (status_code == 200) {
				session->close(200, "The created entity instance", { {"Connection", "close"} });
				return;
			}
			if (status_code == 0) {
				session->close(0, "unexpected error", { {"Connection", "close"} });
				return;
			}

		});
}

void EntityInstanceApiEntitiesInstancesResource::DELETE_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(200, "Success message", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}
void EntityInstanceApiEntitiesInstancesResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<EntityInstanceDto> response = NULL;
		session->close(200, "Array of entity instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}


EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/");
	this->set_method_handler("POST", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::POST_method_handler, this, placeholders::_1));
	this->set_method_handler("DELETE", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::DELETE_method_handler, this, placeholders::_1));
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::POST_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
	// Body params are present, therefore we have to fetch them
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const shared_ptr<Session> session, const Bytes & body )
		{

			const auto request = session->get_request();
			string requestBody = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			/**
			 * Get body params or form params here from the requestBody string
			 */
			
			// Getting the path params
			const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
			
			// Change the value of this variable to the appropriate response before sending the response
			int status_code = 200;
			
			/**
			 * Process the received information here
			 */
			
			if (status_code == 200) {
				session->close(200, "The created or updated entity instance", { {"Connection", "close"} });
				return;
			}
			if (status_code == 0) {
				session->close(0, "unexpected error", { {"Connection", "close"} });
				return;
			}

		});
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::DELETE_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

			// Getting the path params
			const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
			
			// Change the value of this variable to the appropriate response before sending the response
			int status_code = 200;
			
			/**
			 * Process the received information here
			 */
			
			if (status_code == 200) {
				shared_ptr<EntitySystemMessageDto> response = NULL;
				session->close(200, "Success message", { {"Connection", "close"} });
				return;
			}
			if (status_code == 0) {
				shared_ptr<EntitySystemMessageDto> response = NULL;
				session->close(0, "unexpected error", { {"Connection", "close"} });
				return;
			}

}
void EntityInstanceApiEntitiesInstancesEntity_instance_uuidResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");

	spdlog::get("inexor.entity.rest")->debug("Searching for entity instance {}", entity_instance_uuid);

	bool exists = this->entity_instance_manager->does_entity_instance_exist(Guid(entity_instance_uuid));
	spdlog::get("inexor.entity.rest")->debug(exists ? "entity instance exists" : "entity instance does not exist");

	EntityInstancePtrOpt o_ent_inst = this->entity_instance_manager->get_entity_instance(Guid(entity_instance_uuid));

	if (o_ent_inst.has_value()) {
		EntityInstancePtr ent_inst = o_ent_inst.value();
		shared_ptr<EntityInstanceDto> ent_inst_dto = make_shared<EntityInstanceDto>();
		ent_inst_dto->set_entity_instance_uuid(ent_inst->get_GUID().str());
		ent_inst_dto->set_entity_type_uuid(ent_inst->get_entity_type()->get_GUID().str());
		optional<unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> o_ent_inst_attrs = ent_inst->get_instances();
		if (o_ent_inst_attrs.has_value())
		{
			unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr> ent_inst_attrs = o_ent_inst_attrs.value();
			vector<shared_ptr<AttributeDto>> attribute_dtos;
			for (auto& ent_inst_attr : ent_inst_attrs)
			{
				EntityAttributeTypePtr ent_attr_type = ent_inst_attr.first;
				EntityAttributeInstancePtr ent_attr_inst = ent_inst_attr.second;

				shared_ptr<AttributeDto> attribute_dto = make_shared<AttributeDto>(
					ent_attr_inst->get_GUID().str(),
					ent_attr_type->get_type_name(),
					ent_attr_inst->type,
					ent_attr_inst->value.Value(),
					ent_attr_type->get_attribute_features()
				);
//				attribute_dto->set_attribute_uuid(ent_attr_inst->get_GUID().str());
//				attribute_dto->set_name(ent_attr_type->get_type_name());
				attribute_dtos.push_back(attribute_dto);
			}
			ent_inst_dto->set_attributes(attribute_dtos);
		}
		// TODO: ent_inst_dto->set_attributes();
		session->close(restbed::OK, ent_inst_dto->to_json_string(), { {"Connection", "close"} });
		return;
	} else {
		spdlog::get("inexor.entity.rest")->debug("not found");
		shared_ptr<EntitySystemMessageDto> entity_system_message = std::make_shared<EntitySystemMessageDto>();
		entity_system_message->setCode(404);
		entity_system_message->setMessage(fmt::format("Entity type UUID('{}') not found", entity_instance_uuid));
		session->close(restbed::NOT_FOUND, entity_system_message->to_json_string(), { {"Connection", "close"} });
		return;
	}

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<EntityInstanceDto> response = NULL;
		session->close(200, "An entity instance", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}


EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/attributes/{name: .*}/");
	this->set_method_handler("POST", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::POST_method_handler, this, placeholders::_1));
	this->set_method_handler("DELETE", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::DELETE_method_handler, this, placeholders::_1));
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::POST_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
	// Body params are present, therefore we have to fetch them
	int content_length = request->get_header("Content-Length", 0);
	session->fetch(content_length,
		[ this ]( const shared_ptr<Session> session, const Bytes & body )
		{

			const auto request = session->get_request();
			string requestBody = restbed::String::format("%.*s\n", ( int ) body.size( ), body.data( ));
			/**
			 * Get body params or form params here from the requestBody string
			 */
			
			// Getting the path params
			const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
			const string name = request->get_path_parameter("name", "");
			

			
			// Change the value of this variable to the appropriate response before sending the response
			int status_code = 200;
			
			/**
			 * Process the received information here
			 */
			
			if (status_code == 200) {
				session->close(200, "The created or updated attribute", { {"Connection", "close"} });
				return;
			}
			if (status_code == 0) {
				session->close(0, "unexpected error", { {"Connection", "close"} });
				return;
			}

		});
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::DELETE_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
	const string name = request->get_path_parameter("name", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(200, "Success message", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}
void EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesNameResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
	const string name = request->get_path_parameter("name", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<AttributeDto> response = NULL;
		session->close(200, "The attribute", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}


EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/relations/instances/start/{start_entity_instance_uuid: .*}/end/{end_entity_instance_uuid: .*}/");
	this->set_method_handler("DELETE", bind(&EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::DELETE_method_handler, this, placeholders::_1));
	this->set_method_handler("GET", bind(&EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::~EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource()
{
}

void EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::DELETE_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string start_entity_instance_uuid = request->get_path_parameter("start_entity_instance_uuid", "");
	const string end_entity_instance_uuid = request->get_path_parameter("end_entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Success message", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}

void EntityInstanceApiRelationsInstancesStartStart_entity_instance_uuidEndEnd_entity_instance_uuidResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();

	// Getting the path params
	const string start_entity_instance_uuid = request->get_path_parameter("start_entity_instance_uuid", "");
	const string end_entity_instance_uuid = request->get_path_parameter("end_entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		shared_ptr<RelationInstanceDto> response = NULL;
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		shared_ptr<EntitySystemMessageDto> response = NULL;
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}


EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/{relation_type_uuid: .*}/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
	const string relation_type_uuid = request->get_path_parameter("relation_type_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/attributes/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidAttributesResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of attributes", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/{relation_type_uuid: .*}/incoming/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidIncomingResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
	const string relation_type_uuid = request->get_path_parameter("relation_type_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/incoming/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsIncomingResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/{relation_type_uuid: .*}/outgoing/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsRelation_type_uuidOutgoingResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");
	const string relation_type_uuid = request->get_path_parameter("relation_type_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}



EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource::EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource(
	shared_ptr<EntityInstanceManager> entity_instance_manager
)
{
	this->entity_instance_manager = entity_instance_manager;
	this->set_path("/entities/instances/{entity_instance_uuid: .*}/relations/outgoing/");
	this->set_method_handler("GET", bind(&EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource::GET_method_handler, this, placeholders::_1));
}

EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource::~EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource()
{
}

void EntityInstanceApiEntitiesInstancesEntity_instance_uuidRelationsOutgoingResource::GET_method_handler(const shared_ptr<Session> session) {

	const auto request = session->get_request();
			
	// Getting the path params
	const string entity_instance_uuid = request->get_path_parameter("entity_instance_uuid", "");

	// Change the value of this variable to the appropriate response before sending the response
	int status_code = 200;

	/**
	 * Process the received information here
	 */

	if (status_code == 200) {
		session->close(200, "Array of relation instances", { {"Connection", "close"} });
		return;
	}
	if (status_code == 0) {
		session->close(0, "unexpected error", { {"Connection", "close"} });
		return;
	}

}




}
}
}
}

