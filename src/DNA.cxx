#include "all.h"
#include "DNA.h"

#include <sstream>
#include <iomanip>
#include <SFML/Graphics/Shape.hpp>

Ivolve::DNA::DNA(unsigned polycount, unsigned verticesPerPoly) noexcept
{
	polygons.resize(polycount);
	for(auto &p : polygons)
		p.setPointCount(verticesPerPoly);
}

void Ivolve::DNA::mutate(unsigned imageWidth, unsigned imageHeight) noexcept
{
	unsigned polyToMutate = rand() % polycount();
	unsigned valueToMutate = rand() % (verticesPerPoly()*2 + 4);

	if(valueToMutate < verticesPerPoly()*2) // mutate a coordinate
	{
		sf::Vector2f pointToMutate = polygons[polyToMutate].getPoint(valueToMutate/2);
		if(valueToMutate % 2 == 0)
			pointToMutate.x = rand() % imageWidth;
		else
			pointToMutate.y = rand() % imageHeight;
		polygons[polyToMutate].setPoint(valueToMutate/2, pointToMutate);
	}
	else // mutate RGB
	{
		sf::Color colorToMutate = polygons[polyToMutate].getFillColor();
		switch(valueToMutate - verticesPerPoly()*2)
		{
			case 0:
				colorToMutate.r = rand();
				break;
			case 1:
				colorToMutate.g = rand();
				break;
			case 2:
				colorToMutate.b = rand();
				break;
			case 3:
				colorToMutate.a = rand();
				break;
		}
		polygons[polyToMutate].setFillColor(colorToMutate);
	}
}

std::string Ivolve::DNA::toString(void) const
{
	std::ostringstream stream;
	stream << polycount() << ' ' << verticesPerPoly() << std::endl;
	for(auto poly : polygons)
	{
		for (unsigned i = 0; i < poly.getPointCount(); ++i)
			stream << poly.getPoint(i).x << ' ' << poly.getPoint(i).y << ' ';
		stream << (int)poly.getFillColor().r << ' ' << (int)poly.getFillColor().g << ' ' << (int)poly.getFillColor().b << ' ' << (int)poly.getFillColor().a << std::endl;
	}
	return stream.str();
}
