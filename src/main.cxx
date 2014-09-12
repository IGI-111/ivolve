#include "all.h"

#include <Magick++/Image.h>
#include <string>

#include "evolve.h"

int main(int argc, char *argv[])
{
	using namespace std;
	using namespace Magick;
	using namespace Ivolve;

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
