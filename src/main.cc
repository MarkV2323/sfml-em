#include <SFML/Graphics.hpp>
#include <iostream>

#include "entityManager/entityManager.h"

using namespace em;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Entity Manager Demo");
    window.setFramerateLimit(60);

    // Setup our E.M
    EntityManager* eMan = new EntityManager();
    
    auto e0 = eMan->addEntity("E-0");
    auto e1 = eMan->addEntity("E-0");
    auto e2 = eMan->addEntity("E-1");
    auto e3 = eMan->addEntity("E-0");
    auto e4 = eMan->addEntity("E-0");
    auto e5 = eMan->addEntity("E-0");

    std::cout << "Total Waiting Entities: " << eMan->getTotalWaitingEntities() << "\n";
    std::cout << "Total Alive Entities: " << eMan->getTotalAliveEntities() << "\n";
    std::cout << "Total Created Entities: " << eMan->getTotalCreatedEntities() << "\n";
    eMan->update();
    std::cout << "\n";

    std::cout << "Total Waiting Entities: " << eMan->getTotalWaitingEntities() << "\n";
    std::cout << "Total Alive Entities: " << eMan->getTotalAliveEntities() << "\n";
    std::cout << "Total Created Entities: " << eMan->getTotalCreatedEntities() << "\n";
    std::cout << "\n";

    eMan->removeEntity(*e3); // 3,[E-0]2
    eMan->removeEntity(*e5); // 5,[E-0]4
    eMan->update();
    
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

    delete eMan;
    return 0;
}