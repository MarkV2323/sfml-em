#include <SFML/Graphics.hpp>
#include <iostream>

#include "entityManager/entityManager.h"
#include "entityManagerTwo/entityManagerTwo.h"

using namespace em;
using namespace std;

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

inline void debugPrint(EntityManagerTwo& eMan) {
    cout << "\n";
    cout << "Total Waiting Entities: " << eMan.getTotalWaitingEntities() << "\n";
    cout << "Total Alive Entities: " << eMan.getTotalAliveEntities() << "\n";
    cout << "Total Created Entities: " << eMan.getTotalCreatedEntities() << "\n";
    cout << "\n";
    eMan.update();
}

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Entity Manager Demo");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Escape)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}