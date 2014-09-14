#include "all.h"

#include <Magick++/Image.h>
#include <string>
#include <iostream>

#include "utils.h"
#include "DNA.h"

int main(int argc, char *argv[])
{
	using namespace std;
	using namespace Magick;
	using namespace Ivolve;

	srand(time(NULL));
	
	if(argc < 1)
		return 1;

	Image img;
	string path = argv[1];

	Image original(path);
	original.matte(true); // we need transparency to be able to compare

	Image mother(original.page(), "white");
	mother.matte(true);
	DNA motherGenome;
	double motherDistance = compare(mother, original);

	Image daughter(original.page(), "white");
	daughter.matte(true);
	DNA daughterGenome;

	unsigned i = 0;
	while(true) // main loop
	{
		std::cout << daughterGenome.toString() << std::endl;
		std::cout << "Round: " << i << " Distance: " << motherDistance << ' ';

		daughterGenome = motherGenome;
		daughterGenome.mutate(original.columns(), original.rows());
		daughter.erase();
		daughter.draw(daughterGenome.polygonsToDraw());

		double daughterDistance = compare(daughter, original);
		if(daughterDistance < motherDistance )
		{
			std::cout << "Improvement!";
			mother = daughter;
			motherDistance = daughterDistance;
			motherGenome = daughterGenome;
		}
		else if(metropolisRule(daughterDistance - motherDistance, motherDistance))
		{
			std::cout << "Metropolis";
			mother = daughter;
			motherDistance = daughterDistance;
			motherGenome = daughterGenome;
		}
		std::cout << std::endl;
		++i;
	}
	return 0;
}
