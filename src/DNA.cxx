#include "all.h"
#include "DNA.h"

#include <sstream>
#include <iomanip>
#include <Magick++/Color.h>
#include <Magick++.h>

Ivolve::DNA::DNA(unsigned polycount, unsigned verticesPerPoly) noexcept
{
	polygons.resize(polycount);
	for(Polygon &p : polygons)
		p.points.resize(verticesPerPoly);
}

void Ivolve::DNA::operator=(const DNA &d)
{
	polygons.resize(d.polycount());
	for(Polygon &p : polygons)
		p.points.resize(d.verticesPerPoly());
	for (unsigned i = 0; i < d.polycount(); ++i)
	{
		polygons[i] = d.polygons[i];
	}
}

void Ivolve::DNA::mutate(unsigned imageWidth, unsigned imageHeight) noexcept
{
	unsigned polyToMutate = rand() % polycount();
	unsigned valueToMutate = rand() % (verticesPerPoly()*2 + 4);

	if(valueToMutate < verticesPerPoly()*2) // mutate a coordinate
	{
		if(valueToMutate % 2 == 0)
			polygons[polyToMutate].points[valueToMutate/2].x(rand() % imageWidth);
		else
			polygons[polyToMutate].points[valueToMutate/2].y(rand() % imageHeight);
	}
	else // mutate RGB
	{
		switch(valueToMutate - verticesPerPoly()*2)
		{
			case 0:
				polygons[polyToMutate].color.redQuantum(rand());
				break;
			case 1:
				polygons[polyToMutate].color.greenQuantum(rand());
				break;
			case 2:
				polygons[polyToMutate].color.blueQuantum(rand());
				break;
			case 3:
				polygons[polyToMutate].color.alpha((double)(rand())/(double)(RAND_MAX));
				break;
		}
	}
}

std::string Ivolve::DNA::toString(void) const
{
	std::ostringstream stream;
	stream << polycount() << ' ' << verticesPerPoly() << std::endl;
	for(Polygon poly : polygons)
	{
		for(auto p : poly.points)
			stream << p.x() << ' ' << p.y() << ' ';
		stream << poly.color.redQuantum() << ' ' << poly.color.greenQuantum() << ' ' << poly.color.blueQuantum() << ' ' << poly.color.alpha() << std::endl;
	}
	return stream.str();
}

Magick::DrawableList Ivolve::DNA::polygonsToDraw() const
{
	using namespace Magick;
	Magick::DrawableList result;
	for(Polygon poly : polygons)
	{
		result.push_back(DrawableStrokeColor(poly.color));
		result.push_back(DrawableFillColor(poly.color));
		CoordinateList list;
		for(auto p : poly.points)
			list.push_back(p);
		result.push_back(DrawablePolygon(list));
	}
	return result;
}
