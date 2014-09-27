#include "all.h"

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <string>
#include <iostream>
#include <thread>

#include "evolve.h"
#include "display.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if(argc < 2)
		return 1;

	sf::Image original;
	original.loadFromFile(argv[1]);

	sf::Texture mother;

	sf::RenderTexture daughter;

	std::thread evolution(Ivolve::evolve, std::cref(original), std::ref(mother), std::ref(daughter));
	std::thread interface(Ivolve::display, std::cref(original), std::cref(mother), std::cref(daughter));

	evolution.join();
	interface.join();
	return 0;
}
