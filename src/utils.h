#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cmath>
#include <SFML/Graphics/Image.hpp>


#define RESULT_SCALE 1000000

namespace Ivolve
{
	double compare(const sf::Image &img1, const sf::Image &img2);
	inline bool metropolisRule(double variation, double temperature) // variation shall be positive
	{
		return (double)(rand())/(double)(RAND_MAX) < exp(-variation/temperature);
	}
}

#endif /* end of include guard: EVOLVE_H */

