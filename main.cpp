#include <iostream>

#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Works!", sf::Style::Default);
    window.setFramerateLimit(120);

    sf::Clock clock;
    float deltaTime;
    // 0.0082
    float multiplier = 122.f;

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(100.f, 100.f));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        // Update
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            shape.move(-5.f * deltaTime * multiplier, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            shape.move(5.f * deltaTime * multiplier, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            shape.move(0.f, -5.f * deltaTime * multiplier);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move(0.f, 5.f * deltaTime * multiplier);

        // Draw
        window.clear();
        // Draw stuff
        window.draw(shape);

        window.display();

        std::cout << "Delta time: " << deltaTime << std::endl;
    }

    return 0;
}

