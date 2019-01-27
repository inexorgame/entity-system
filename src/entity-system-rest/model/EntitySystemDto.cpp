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



#include "EntitySystemDto.hpp"

#include <string>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace inexor {
namespace entity_system {
namespace rest {
namespace model {

	EntitySystemDto::EntitySystemDto()
	{

	}

	EntitySystemDto::~EntitySystemDto()
	{
	}

	std::string EntitySystemDto::toJsonString()
	{
		std::stringstream ss;
		ptree pt;
		write_json(ss, pt, false);
		return ss.str();
	}

	void EntitySystemDto::fromJsonString(std::string const& jsonString)
	{
		std::stringstream ss(jsonString);
		ptree pt;
		read_json(ss,pt);
	}

	std::vector<std::shared_ptr<EntityTypeDto>> EntitySystemDto::getEntityTypes() const
	{
		return m_Entity_types;
	}

	void EntitySystemDto::setEntityTypes(std::vector<std::shared_ptr<EntityTypeDto>> value)
	{
		m_Entity_types = value;
	}

	std::vector<std::shared_ptr<RelationTypeDto>> EntitySystemDto::getRelationTypes() const
	{
		return m_Relation_types;
	}

	void EntitySystemDto::setRelationTypes(std::vector<std::shared_ptr<RelationTypeDto>> value)
	{
		m_Relation_types = value;
	}

	std::vector<std::shared_ptr<EntityInstanceDto>> EntitySystemDto::getEntityInstances() const
	{
		return m_Entity_instances;
	}

	void EntitySystemDto::setEntityInstances(std::vector<std::shared_ptr<EntityInstanceDto>> value)
	{
		m_Entity_instances = value;
	}

	std::vector<std::shared_ptr<RelationInstanceDto>> EntitySystemDto::getRelationInstances() const
	{
		return m_Relation_instances;
	}

	void EntitySystemDto::setRelationInstances(std::vector<std::shared_ptr<RelationInstanceDto>> value)
	{
		m_Relation_instances = value;
	}

}
}
}
}
