#include "utils.h"

#include <iostream>
#include <stdexcept>
#include <SFML/Graphics/Image.hpp>
#include <cmath>

double Ivolve::compare(const sf::Image &img1, const sf::Image &img2)
{
	double distance = 0;
	for(unsigned x = 0;x<img1.getSize().x;++x)
		for(unsigned y = 0;y<img1.getSize().y;++y)
		{
			sf::Color c1 = img1.getPixel(x,y);
			sf::Color c2 = img2.getPixel(x,y);

			double deltaRed = c1.r - c2.r;
			double deltaGreen = c1.g - c2.g;
			double deltaBlue = c1.b - c2.b;

			double pixelFitness = deltaRed * deltaRed +
				deltaGreen * deltaGreen +
				deltaBlue * deltaBlue;

			distance += pixelFitness;
		}
	return distance;
}
