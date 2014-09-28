#include "evolve.h"

#include <iostream>

#include "utils.h"
#include "DNA.h"

void Ivolve::evolve(const sf::Image &original, sf::Texture &mother, sf::RenderTexture &daughter)
{
	static DNA motherGenome;
	static double motherDistance = compare(mother.copyToImage(), original);

	static DNA daughterGenome;

	static unsigned i = 0;

	std::cout << i << ' ';
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
