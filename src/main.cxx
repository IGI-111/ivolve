#include "all.h"

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>
#include <thread>

#include "evolve.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if(argc < 2)
		return 1;

	sf::Image original;
	if(!original.loadFromFile(argv[1]))
		return 2;
	sf::Texture mother;
	mother.create(original.getSize().x, original.getSize().y);
	sf::RenderTexture daughter;
	daughter.create(original.getSize().x, original.getSize().y);

	sf::RenderWindow window(sf::VideoMode(original.getSize().x * 3, original.getSize().y), "Ivolve");

	sf::Sprite originalSprite;
	sf::Texture originalTexture;
	originalTexture.loadFromImage(original);
	originalSprite.setTexture(originalTexture);
	originalSprite.setPosition(0,0);

	sf::Sprite motherSprite;
	motherSprite.setTexture(mother);
	motherSprite.setPosition(original.getSize().x, 0);

	sf::Sprite daughterSprite;
	daughterSprite.setTexture(daughter.getTexture());
	daughterSprite.setPosition(original.getSize().x*2, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Ivolve::evolve(original, mother, daughter);

		window.clear(sf::Color::White);
		window.draw(originalSprite);
		window.draw(motherSprite);
		window.draw(daughterSprite);
		window.display();
	}
	return 0;
}
