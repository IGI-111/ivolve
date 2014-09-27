#include "all.h"

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <string>
#include <iostream>

#include "utils.h"
#include "DNA.h"

int main(int argc, char *argv[])
{
	using namespace sf;
	using namespace std;
	using namespace Ivolve;

	srand(time(NULL));

	if(argc < 2)
		return 1;


	Image original;
	original.loadFromFile(argv[1]);

	Texture mother;
	mother.create(original.getSize().x, original.getSize().y);
	DNA motherGenome;
	double motherDistance = compare(mother.copyToImage(), original);

	RenderTexture daughter;
	DNA daughterGenome;
	daughter.create(original.getSize().x, original.getSize().y);

	unsigned i = 0;
	while(true) // main loop
	{
		std::cout << daughterGenome.toString() << std::endl;
		std::cout << "Round: " << i << " Distance: " << motherDistance << ' ';

		daughterGenome = motherGenome;
		daughterGenome.mutate(original.getSize().x, original.getSize().y);
		daughter.clear(sf::Color::White);
		for(auto poly : daughterGenome.getPolygons())
			daughter.draw(poly);

		double daughterDistance = compare(daughter.getTexture().copyToImage(), original);
		if(daughterDistance < motherDistance )
		{
			std::cout << "Improvement!";
			mother = daughter.getTexture();
			motherDistance = daughterDistance;
			motherGenome = daughterGenome;
		}
		else if(metropolisRule(daughterDistance - motherDistance, 1))//FIXME: temperature is constant
		{
			std::cout << "Metropolis";
			mother = daughter.getTexture();
			motherDistance = daughterDistance;
			motherGenome = daughterGenome;
		}
		std::cout << std::endl;
		++i;
	}
	return 0;
}
