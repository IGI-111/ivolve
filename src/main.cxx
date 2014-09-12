#define MAGICKCORE_QUANTUM_DEPTH 16 // 16 bit color depth
#define MAGICKCORE_HDRI_ENABLE 0    // no need for HDRI

#include <Magick++/Image.h>
#include <string>

#include "evolve.h"

int main(int argc, char *argv[])
{
	using namespace std;
	using namespace Magick;
	using namespace Ivolve;

	srand(time(NULL));

	Image img;
	string path;
	for(int i = 1;i<argc;++i)
	{
		path = argv[i];
		img = evolve(path, 10000);
		img.write("evolved" + to_string(i) + ".png");
	}
	return 0;
}
