#include "all.h"
#include "DNA.h"

#include <sstream>

Ivolve::DNA::DNA(unsigned polycount, unsigned verticesPerPoly) noexcept
{
	polygons.resize(polycount);
	for(Geometry::Polygon &p : polygons)
		p.points.resize(verticesPerPoly);
}

void Ivolve::DNA::mutate(unsigned imageWidth, unsigned imageHeight) noexcept
{
	unsigned polyToMutate = rand() % polycount();
	unsigned valueToMutate = rand() % (verticesPerPoly()*2 + 4);

	if(valueToMutate < verticesPerPoly()*2) // mutate a coordinate
	{
		if(valueToMutate % 2 == 0)
			polygons[polyToMutate].points[valueToMutate/2].x = rand() % imageWidth;
		else
			polygons[polyToMutate].points[valueToMutate/2].y = rand() % imageHeight;
	}
	else // mutate RGB
	{
		switch(valueToMutate - verticesPerPoly()*2)
		{
			case 0:
				polygons[polyToMutate].red = rand() % 255;
				break;
			case 1:
				polygons[polyToMutate].green = rand() % 255;
				break;
			case 2:
				polygons[polyToMutate].blue = rand() % 255;
				break;
			case 3:
				polygons[polyToMutate].alpha = (float)(rand())/(float)(RAND_MAX);
				break;
		}
	}
}

std::string Ivolve::DNA::toString(void) const
{
	std::ostringstream stream;
	stream << polycount() << ' ' << verticesPerPoly() << std::endl;
	for(Geometry::Polygon poly : polygons)
	{
		for(Geometry::Point p : poly.points)
			stream << p.x << ' ' << p.y << ' ';
		stream << poly.red << ' ' << poly.green << ' ' << poly.blue << ' ' << poly.alpha << std::endl;
	}
	return stream.str();
}
