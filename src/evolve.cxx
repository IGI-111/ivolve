#include "all.h"
#include "evolve.h"

#include <iostream>

#include "DNA.h"

Magick::Image Ivolve::evolve(const std::string &path, unsigned rounds)
{
	using namespace Magick;

	Image original(path);
	original.matte(true); // we need transparency to be able to compare

	Image mother(original.page(), "white");
	mother.matte(true);
	DNA genome;
	double motherDistance = compare(mother, original);
	Image daughter(original.page(), "white");
	mother.matte(true);

	for(unsigned i = 0;i<rounds;++i)
	{
		std::cout << "Left: " << rounds-i << ' ';
		// mutate
		genome.mutate(original.columns(), original.rows());
		daughter.erase();
		daughter.draw(genome.polygonsToDraw());

		// FIXME: hill climb
		double daughterDistance = compare(daughter, original);
		if(daughterDistance < motherDistance)
		{
			std::cout << "Improvement!";
			mother = daughter;
			motherDistance = daughterDistance;
		}
		std::cout << std::endl;
	}
	std::cout << genome.toString() << std::endl;
	return mother;
}

double Ivolve::compare(Magick::Image &img1, Magick::Image &img2)
{
	try
	{
		img1.compare(img2);
		return img1.meanErrorPerPixel();
	}
	catch(Magick::ErrorImage &e)
	{
		std::cout << e.what() << std::endl;
		if(img1.columns() != img2.columns())
			std::cout << "Different Length" << std::endl;
		if(img1.rows() != img2.rows())
			std::cout << "Different Height" << std::endl;
		if(img1.colorSpace() != img2.colorSpace())
			std::cout << "Different Colorspace" << std::endl;
		if(img1.matte() != img2.matte())
			std::cout << "Different Matte" << std::endl;
		exit(1);
	}
}
