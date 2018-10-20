#include "DumbAlien.h"
#include "TrackingAlien.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

        sf::RenderWindow window(sf::VideoMode(1366, 768), "The Wierdo Owns the Fly, Dude", sf::Style::Fullscreen);
        std::shared_ptr<sf::CircleShape> wierdo = std::make_shared<sf::CircleShape>(30);
        sf::CircleShape fly(15);
        TrackingAlien alien(10);
        DumbAlien dude(52);

        wierdo->setFillColor(sf::Color::Green);
        fly.setFillColor(sf::Color::Red);
        alien.setFillColor(sf::Color::Yellow);
        dude.setFillColor(sf::Color::Magenta);

        fly.setPosition(683,0);
        wierdo->setPosition(683,708);
        alien.setPosition(100,0);
        dude.setPosition(300,25);

        alien.setTarget( wierdo );
        dude.setTarget(wierdo);

        sf::Clock clock;
        int oldElapseTime = 10;

        while (window.isOpen())
        {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && wierdo->getPosition().x<1306 ) wierdo->move(12,0);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && wierdo->getPosition().x>30 ) wierdo->move(-12,0);
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) wierdo.move(0,-12);
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) wierdo.move(0,12);

                //sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                //sf::Vector2f fly_position = fly.getPosition();
                //if (mouse_position.x > fly_position.x) fly.move(12,0);
                //if (mouse_position.x < fly_position.x) fly.move(-12,0);
                //if (mouse_position.y < fly_position.y) fly.move(0,-12);
                //if (mouse_position.y > fly_position.y) fly.move(0,12);

                if ( clock.getElapsedTime().asMilliseconds() > (oldElapseTime + 10) ) {
                	oldElapseTime = clock.getElapsedTime().asMilliseconds();
                	fly.move(0,1);
                	if (wierdo->getPosition().x > fly.getPosition().x) fly.move(1,0);
                	if (wierdo->getPosition().x < fly.getPosition().x) fly.move(-1,0);
                    dude.step();
                	alien.step();
                }


                window.clear();
                window.draw(*(wierdo.get()));
                window.draw(fly);
                window.draw(alien);
                window.draw(dude);
                window.display();

                if (wierdo->getGlobalBounds().intersects(fly.getGlobalBounds()))
                {
                        window.close();
                        std::cout << "Fly! Wins!\n" << std::endl;
                }
                if (wierdo->getGlobalBounds().intersects(alien.getGlobalBounds()))
                 {
                         window.close();
                         std::cout << "Alien Wins!\n" << std::endl;
                 }
                if (clock.getElapsedTime().asSeconds() > 60)
                {
                        window.close();
                        std::cout << "Weirdo! Wins!\n" << std::endl;
                }
        }
        {
        	wierdo->getGlobalBounds().intersects(dude.getGlobalBounds());
        	window.close();
        	std::cout << "Dude Wins!" << std::endl;
        }
        return 0;
}
