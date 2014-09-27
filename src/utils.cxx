#include "all.h"
#include "utils.h"

#include <iostream>
#include <stdexcept>
#include <Magick++/Pixels.h>
#include <cmath>

double Ivolve::compare(Magick::Image &img1, Magick::Image &img2)
{
	if(img1.columns() != img2.columns())
		throw std::runtime_error("Different Length");
	if(img1.rows() != img2.rows())
		throw std::runtime_error("Different Height");
	if(img1.colorSpace() != img2.colorSpace())
		throw std::runtime_error("Different Colorspace");
	if(img1.matte() != img2.matte())
		throw std::runtime_error("Different Matte");
	img1.compare(img2);
	return img1.meanErrorPerPixel();
}
