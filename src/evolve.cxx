#include "all.h"
#include "evolve.h"

#include <iostream>

#include "DNA.h"

Magick::Image Ivolve::evolve(const std::string &path, unsigned rounds)
{
	using namespace Magick;

	Image original(path);
	double width = original.columns();
	double height = original.rows();

	Image mother(Geometry(width, height), Color("white"));
	Image daughter(Geometry(width, height), Color("white"));
	DNA genome;

	for(unsigned i = 0;i<rounds;++i)
	{
		// mutate
		genome.mutate(original.columns(), original.rows());

		// check if mutation is closer to original
		// TODO: check
	}
	std::cout << genome.toString() << std::endl;
	original.draw(genome.polygonsToDraw());

	return original; //FIXME
}
