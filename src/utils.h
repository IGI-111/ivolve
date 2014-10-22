#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cmath>
#include <SFML/Graphics/Image.hpp>

namespace Ivolve
{
	/// Calcule la différence entre deux images.
	double compare(const sf::Image &img1, const sf::Image &img2);
	/// Renvoie un booléen vrai avec une probabilité déterminée par la règle de Métropolis.
	inline bool metropolisRule(double variation, double temperature) // variation shall be positive
	{
		return (double)(rand())/(double)(RAND_MAX) < exp(-variation/temperature);
	}
}

#endif /* end of include guard: EVOLVE_H */

