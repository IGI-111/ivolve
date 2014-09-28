#include "evolve.h"

#include <iostream>

#include "utils.h"
#include "DNA.h"

void Ivolve::evolve(const sf::Image &original, sf::Texture &mother, sf::RenderTexture &daughter)
{
	static DNA motherGenome;
	static double motherDistance = compare(mother.copyToImage(), original);
	static long double temperature = motherDistance; // init with a big number
	static DNA daughterGenome;

	static unsigned i = 0;

	daughterGenome = motherGenome;
	daughterGenome.mutate(original.getSize().x, original.getSize().y);
	daughter.clear(sf::Color::Black);
	for(auto poly : daughterGenome.getPolygons())
		daughter.draw(poly);

	double daughterDistance = compare(daughter.getTexture().copyToImage(), original);
	if(daughterDistance < motherDistance )
	{
		std::cout << "Improvement!" << std::endl;
		mother = daughter.getTexture();
		motherDistance = daughterDistance;
		motherGenome = daughterGenome;
	}
	else if(metropolisRule(daughterDistance - motherDistance, temperature))
	{
		std::cout << "Metropolis" << std::endl;
		mother = daughter.getTexture();
		motherDistance = daughterDistance;
		motherGenome = daughterGenome;
	}
	temperature *= 0.99; //FIXME: a better law ought to be written
	++i;
}
