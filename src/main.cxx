#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#include <thread>

#include "evolve.h"

#define FRAMERATE 60

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if(argc < 2 || argc > 3)
	{
		std::cerr << "Usage: ivolve pathToImage [pathToSaveEvolvedImage]" << std::endl;
		return 1;
	}

	sf::Image original;
	if(!original.loadFromFile(argv[1]))
		return 2;
	sf::Texture mother;
	mother.create(original.getSize().x, original.getSize().y);
	sf::RenderTexture daughter;
	daughter.create(original.getSize().x, original.getSize().y);

	sf::RenderWindow window(sf::VideoMode(original.getSize().x * 3, original.getSize().y), "Ivolve");
	sf::Clock framerateClock;
	sf::Clock timeElapsed;

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



	sf::Clock consoleOutputClock;
	unsigned alreadyCountedImprovements = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		Ivolve::evolve(original, mother, daughter);

		if(framerateClock.getElapsedTime().asMilliseconds() >= 1000/FRAMERATE)
		{
			// display every 20ms
			window.clear(sf::Color::White);
			window.draw(originalSprite);
			window.draw(motherSprite);
			window.draw(daughterSprite);
			window.display();
			framerateClock.restart();
		}

		if(consoleOutputClock.getElapsedTime().asSeconds() >= 1)
		{
			unsigned timeElapsedInSeconds = timeElapsed.getElapsedTime().asSeconds();
            std::cout
                << timeElapsedInSeconds/60 << ':' << std::setfill('0') << std::setw(2) << timeElapsedInSeconds%60
                << std::setw(3) << " ips: " << Ivolve::improvements - alreadyCountedImprovements
                << std::setw(3) << " ti: " << Ivolve::improvements
                << std::setw(3) << " metro: " << Ivolve::metropolisRules
                << std::setw(3) << " fit: " << std::setprecision(4) << Ivolve::fitness * 100  << '%' << std::endl;
            alreadyCountedImprovements = Ivolve::improvements;
			consoleOutputClock.restart();
		}
	}

	if(argc == 3)
	{
		std::cout << "Saving to " << argv[2] << std::endl;
		mother.copyToImage().saveToFile(argv[2]);
	}
	return 0;
}
