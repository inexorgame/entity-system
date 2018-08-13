// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"
#include "tests/EntitySystemTests.hpp"
using namespace inexor;
using namespace entity_system;

// Create singleton instance of the entity system.
EntitySystem* entsys = EntitySystem::create_entity_system();


int main(int argc, char* argv[])
{   
    Print_MinimumMaximumMemoryValues();
	Test_DataContainer_CorrectUsage();
	Test_CreateEntityType_CorrectUsage();
	Test_CreateEntityAttributeType_CorrectUsage();

    std::cin.get();
    return 0;
}
