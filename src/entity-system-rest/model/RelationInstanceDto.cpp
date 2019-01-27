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



#include "RelationInstanceDto.hpp"

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

	RelationInstanceDto::RelationInstanceDto()
	{
		m_Relation_instance_uuid = "";
		m_Relation_type_uuid = "";
		m_Start_node_entity_instance_uuid = "";
		m_End_node_entity_instance_uuid = "";

	}

	RelationInstanceDto::~RelationInstanceDto()
	{
	}

	std::string RelationInstanceDto::toJsonString()
	{
		std::stringstream ss;
		ptree pt;
		pt.put("relation_instance_uuid", m_Relation_instance_uuid);
		pt.put("relation_type_uuid", m_Relation_type_uuid);
		pt.put("start_node_entity_instance_uuid", m_Start_node_entity_instance_uuid);
		pt.put("end_node_entity_instance_uuid", m_End_node_entity_instance_uuid);
		write_json(ss, pt, false);
		return ss.str();
	}

	void RelationInstanceDto::fromJsonString(std::string const& jsonString)
	{
		std::stringstream ss(jsonString);
		ptree pt;
		read_json(ss,pt);
		m_Relation_instance_uuid = pt.get("relation_instance_uuid", "");
		m_Relation_type_uuid = pt.get("relation_type_uuid", "");
		m_Start_node_entity_instance_uuid = pt.get("start_node_entity_instance_uuid", "");
		m_End_node_entity_instance_uuid = pt.get("end_node_entity_instance_uuid", "");
	}

	std::string RelationInstanceDto::getRelationInstanceUuid() const
	{
		return m_Relation_instance_uuid;
	}
	void RelationInstanceDto::setRelationInstanceUuid(std::string value)
	{
		m_Relation_instance_uuid = value;
	}
	std::string RelationInstanceDto::getRelationTypeUuid() const
	{
		return m_Relation_type_uuid;
	}
	void RelationInstanceDto::setRelationTypeUuid(std::string value)
	{
		m_Relation_type_uuid = value;
	}
	std::string RelationInstanceDto::getStartNodeEntityInstanceUuid() const
	{
		return m_Start_node_entity_instance_uuid;
	}
	void RelationInstanceDto::setStartNodeEntityInstanceUuid(std::string value)
	{
		m_Start_node_entity_instance_uuid = value;
	}
	std::string RelationInstanceDto::getEndNodeEntityInstanceUuid() const
	{
		return m_End_node_entity_instance_uuid;
	}
	void RelationInstanceDto::setEndNodeEntityInstanceUuid(std::string value)
	{
		m_End_node_entity_instance_uuid = value;
	}
	std::vector<std::shared_ptr<AttributeDto>> RelationInstanceDto::getAttributes() const
	{
		return m_Attributes;
	}
	void RelationInstanceDto::setAttributes(std::vector<std::shared_ptr<AttributeDto>> value)
	{
		m_Attributes = value;
	}

}
}
}
}
