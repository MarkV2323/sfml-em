#include <iostream>
#include <cassert>
#include <random>

#include "entityManagerTwo/entityManagerTwo.h"

// Can disable assert by uncommenting
// #define NDEBUG

using namespace em;
using namespace std;

// internal debugPrint function for eMan
inline void debugPrint(EntityManagerTwo& eMan) {
    cout << "\n";
    cout << "Total Waiting Entities: " << eMan.getTotalWaitingEntities() << "\n";
    cout << "Total Alive Entities: " << eMan.getTotalAliveEntities() << "\n";
    cout << "Total Created Entities: " << eMan.getTotalCreatedEntities() << "\n";
    cout << "\n";
}

// demo function
inline void demoEntityMangerTwo() {
    // Eaxmple of using our unique_ptr Entity Manager
    auto eMan = EntityManagerTwo();
    eMan.addEntity("E-0");
    eMan.addEntity("E-0");
    eMan.addEntity("E-1");
    eMan.addEntity("E-2");
    eMan.addEntity("E-2");
    eMan.addEntity("E-0");
    debugPrint(eMan);
    debugPrint(eMan);

    cout << "Killing an E-0" << endl;
    eMan.getEntities().at(1).get()->kill(); // kill a E-0
    eMan.update();
    debugPrint(eMan);

    cout << "Killing an E-2" << endl;
    eMan.getEntities("E-2").at(1).get()->kill(); // kill a E-2
    eMan.update();
    debugPrint(eMan);

    auto eMap = eMan.getEntityMap();
    for (auto& e : eMap) {
        cout << "eMap Vector Tag & Size: " << e.first << "," << e.second.size() << std::endl;
    }

    cout << "Adding an E-0" << endl;
    eMan.addEntity("E-0");
    eMan.update();
    debugPrint(eMan);
}

// test addition of entityManagerTwo
bool addEntitiesTest() {
    auto eMan = EntityManagerTwo();
    
    assert(eMan.getTotalWaitingEntities() == 0);
    
    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 1);
    
    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 2);
    
    eMan.addEntity("E2");
    assert(eMan.getTotalWaitingEntities() == 3);

    // seed & gen ran num, 1-10
    srand(time(NULL));
    auto randomNum = rand() % 10 + 1;

    for (size_t i = 0; i < randomNum; i++) {
        eMan.addEntity("E5");
    }
    assert(eMan.getTotalWaitingEntities() == (3 + randomNum));

    return true;
}

// test update of entityManagerTwo
bool updateEntitiesTest() {
    auto eMan = EntityManagerTwo();
    
    assert(eMan.getTotalWaitingEntities() == 0);
    
    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 1);
    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 1);
    assert(eMan.getTotalAliveEntities() == 1);

    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 1);
    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 2);
    assert(eMan.getTotalAliveEntities() == 2);

    eMan.addEntity("E2");
    assert(eMan.getTotalWaitingEntities() == 1);
    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 3);
    assert(eMan.getTotalAliveEntities() == 3);

    // seed & gen ran num, 1-10
    srand(time(NULL));
    auto randomNum = rand() % 10 + 1;

    for (size_t i = 0; i < randomNum; i++) {
        eMan.addEntity("E5");
    }
    assert(eMan.getTotalWaitingEntities() == randomNum);

    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 3 + randomNum);
    assert(eMan.getTotalAliveEntities() == 3 + randomNum);

    return true;
}

// test removal of entityManagerTwo
bool removeEntitiesTest() {
    auto eMan = EntityManagerTwo();
    
    assert(eMan.getTotalWaitingEntities() == 0);
    
    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 1);
    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 1);
    assert(eMan.getTotalAliveEntities() == 1);

    eMan.addEntity("E1");
    assert(eMan.getTotalWaitingEntities() == 1);
    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 2);
    assert(eMan.getTotalAliveEntities() == 2);

    // Kills E1
    eMan.getEntities().back().get()->kill();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 2);
    assert(eMan.getTotalAliveEntities() == 2);

    eMan.update();
    assert(eMan.getTotalWaitingEntities() == 0);
    assert(eMan.getTotalCreatedEntities() == 2);
    assert(eMan.getTotalAliveEntities() == 1);

    return true;
}

// Run all tests in emTwoTests
void runEntityManagerTwoTests() {
    cout << "RUNNING addEntitiesTest():    " << boolalpha << addEntitiesTest() << endl;
    cout << "RUNNING updateEntitiesTest(): " << boolalpha << updateEntitiesTest() << endl;
    cout << "RUNNING removeEntitiesTest(): " << boolalpha << removeEntitiesTest() << endl;
}

// Old functions for entityMangaer
/*
inline void debugPrint(EntityManager& eMan) {
    cout << "\n";
    cout << "Total Waiting Entities: " << eMan.getTotalWaitingEntities() << "\n";
    cout << "Total Alive Entities: " << eMan.getTotalAliveEntities() << "\n";
    cout << "Total Created Entities: " << eMan.getTotalCreatedEntities() << "\n";
    cout << "\n";
    eMan.update();
}

inline void demoEntityManager() {
    // Example of using our orginal, raw pointer Entity Manager
    EntityManager* eMan = new EntityManager();
    
    auto e0 = eMan->addEntity("E-0");
    auto e1 = eMan->addEntity("E-0");
    auto e2 = eMan->addEntity("E-1");
    auto e3 = eMan->addEntity("E-0");
    auto e4 = eMan->addEntity("E-0");
    auto e5 = eMan->addEntity("E-0");

    cout << "Total Waiting Entities: " << eMan->getTotalWaitingEntities() << "\n";
    cout << "Total Alive Entities: " << eMan->getTotalAliveEntities() << "\n";
    cout << "Total Created Entities: " << eMan->getTotalCreatedEntities() << "\n";
    eMan->update();
    cout << "\n";

    cout << "Total Waiting Entities: " << eMan->getTotalWaitingEntities() << "\n";
    cout << "Total Alive Entities: " << eMan->getTotalAliveEntities() << "\n";
    cout << "Total Created Entities: " << eMan->getTotalCreatedEntities() << "\n";
    cout << "\n";

    eMan->removeEntity(*e3); // 3,[E-0]2
    eMan->removeEntity(*e5); // 5,[E-0]4
    eMan->update();
    delete eMan;
}
*/
