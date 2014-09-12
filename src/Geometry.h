#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

namespace Ivolve
{
	namespace Geometry
	{
		struct Point
		{
			int x = 0;
			int y = 0;
		};

		struct Polygon
		{
			std::vector<Point> points;
			char red = 0;
			char green = 0;
			char blue = 0;
			float alpha = 0; // invisible by default
		};
	}
}

#endif /* end of include guard: GEOMETRY_H */

