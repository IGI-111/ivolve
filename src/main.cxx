#define MAGICKCORE_QUANTUM_DEPTH 16 // 16 bit color depth
#define MAGICKCORE_HDRI_ENABLE 0    // no need for HDRI
#include <Magick++/Image.h>

int main(int argc, char *argv[])
{
	using namespace Magick;
	Image img("Law.jpg");
	img.write("Law.gif");
	return 0;
}
