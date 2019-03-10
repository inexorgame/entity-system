#pragma once

#include "type-system/factories/trigonometric/SinFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

#include <iostream>

namespace inexor {
namespace visual_scripting {


	/// @class SinTest
    /// @brief Tests for the SIN type.
	class SinTest
	{
		public:

			using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
			using FloatConstantFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::FloatConstantFactory>;
			using SinFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::SinFactory>;

			/// @brief Constructor.
			SinTest(
				ConnectorManagerPtr connector_manager,
				FloatConstantFactoryPtr float_constant_factory,
				SinFactoryPtr sin_factory
			);

			/// @brief Destructor.
			~SinTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// Factory for FLOAT_CONSTANT
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for SIN
			SinFactoryPtr sin_factory;
	};


}
}