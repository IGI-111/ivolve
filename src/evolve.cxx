#include "evolve.h"

#include <iostream>

#include "utils.h"
#include "DNA.h"

void Ivolve::evolve(const sf::Image &original, sf::Texture &mother, sf::RenderTexture &daughter)
{
	mother.create(original.getSize().x, original.getSize().y);
	DNA motherGenome;
	double motherDistance = compare(mother.copyToImage(), original);

	DNA daughterGenome;
	daughter.create(original.getSize().x, original.getSize().y);

	unsigned i = 0;
	while(true)
	{
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
}
