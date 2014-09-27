#ifndef UTILS_H
#define UTILS_H

#include <Magick++/Image.h>
#include <string>
#include <cmath>

#define RESULT_SCALE 1000000

namespace Ivolve
{
	double compare(Magick::Image &img1, Magick::Image &img2);
	inline bool metropolisRule(double variation, double currentDistance) // variation shall be positive
	{
		return (double)(rand())/(double)(RAND_MAX) < exp(-variation/currentDistance);
	}
}

#endif /* end of include guard: EVOLVE_H */

