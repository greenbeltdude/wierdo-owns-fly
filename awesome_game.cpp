#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1366, 768), "The Wierdo Owns the Fly, Dude", sf::Style::Fullscreen);
	sf::CircleShape wierdo(30);
	sf::CircleShape fly(15);
	wierdo.setFillColor(sf::Color::Green);
	fly.setFillColor(sf::Color::Red);
	fly.setPosition(683,384);
	sf::Clock clock;

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) wierdo.move(12,0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) wierdo.move(-12,0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) wierdo.move(0,-12);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) wierdo.move(0,12);

		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f fly_position = fly.getPosition();
		if (mouse_position.x > fly_position.x) fly.move(12,0);
		if (mouse_position.x < fly_position.x) fly.move(-12,0);
		if (mouse_position.y < fly_position.y) fly.move(0,-12);
		if (mouse_position.y > fly_position.y) fly.move(0,12);

		window.clear();
		window.draw(wierdo);
		window.draw(fly);
		window.display();

		if (wierdo.getGlobalBounds().intersects(fly.getGlobalBounds()))
		{
			window.close();
			std::cout << "Wierdo! Wins!\n" << std::endl;
		}
		if (clock.getElapsedTime().asSeconds() > 60)
		{
			window.close();
			std::cout << "Fly! Wins!\n" << std::endl;
		}
	}

	return 0;
}
		
		
			
		

