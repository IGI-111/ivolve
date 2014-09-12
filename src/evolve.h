#ifndef EVOLVE_H
#define EVOLVE_H

#include <Magick++/Image.h>
#include <string>

namespace Ivolve
{
	Magick::Image evolve(const std::string &path, unsigned rounds);
}

#endif /* end of include guard: EVOLVE_H */

