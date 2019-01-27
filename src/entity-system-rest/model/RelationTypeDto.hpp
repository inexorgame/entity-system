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

#include <string>
#include <vector>
#include <memory>

#include "AttributeDto.hpp"

namespace inexor {
namespace entity_system {
namespace rest {
namespace model {

	/// <summary>
	///
	/// </summary>
	class RelationTypeDto
	{
	public:
		RelationTypeDto();
		virtual ~RelationTypeDto();

		std::string toJsonString();
		void fromJsonString(std::string const& jsonString);

		/// <summary>
		///
		/// </summary>
		std::string getRelationTypeUuid() const;
		void setRelationTypeUuid(std::string value);

		/// <summary>
		///
		/// </summary>
		std::string getName() const;
		void setName(std::string value);

		/// <summary>
		///
		/// </summary>
		std::string getStartNodeEntityTypeUuid() const;
		void setStartNodeEntityTypeUuid(std::string value);

		/// <summary>
		///
		/// </summary>
		std::string getEndNodeEntityTypeUuid() const;
		void setEndNodeEntityTypeUuid(std::string value);

		/// <summary>
		///
		/// </summary>
		std::vector<std::shared_ptr<AttributeDto>> getAttributes() const;
		void setAttributes(std::vector<std::shared_ptr<AttributeDto>> value);

	protected:
		std::string m_Relation_type_uuid;
		std::string m_Name;
		std::string m_Start_node_entity_type_uuid;
		std::string m_End_node_entity_type_uuid;
		std::vector<std::shared_ptr<AttributeDto>> m_Attributes;
	};

}
}
}
}
