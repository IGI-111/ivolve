#ifndef DNA_H
#define DNA_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <vector>

// DNA uses the following format when converted to string, every number is an integer except for Alpha which is float
//
// polycount verticesPerPoly
// X0 Y0 X1 Y1 ... XverticesPerPoly-1 YverticesPerPoly-1 Red Green Blue Alpha
// ...
// [continues for polycount lines]
// ...

namespace Ivolve
{

	class DNA
	{
		private:
			std::vector<sf::ConvexShape> polygons;
			inline unsigned polycount() const noexcept
			{
				return polygons.size();
			}
			inline unsigned verticesPerPoly() const noexcept
			{
				return polygons.size() > 0 ? polygons[0].getPointCount(): 0;
			}

		public:
			DNA(unsigned polycount = 70, unsigned verticesPerPoly = 6) noexcept;
			void mutate(unsigned imageWidth, unsigned imageHeight) noexcept;
			std::string toString(void) const;
			inline std::vector<sf::ConvexShape> getPolygons() const noexcept
			{
				return polygons;
			}
			inline void operator=(const DNA &d)
			{
				this->polygons = d.polygons;
			}
	};

}

#endif /* end of include guard: DNA_H */

