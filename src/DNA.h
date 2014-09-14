#ifndef DNA_H
#define DNA_H

#include <Magick++/Drawable.h>
#include <Magick++/Image.h>
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

	struct Polygon
	{
			std::vector<Magick::Coordinate> points;
			Magick::Color color = Magick::Color("white");
	};

	class DNA
	{
		private:
			std::vector<Polygon> polygons;
			inline unsigned polycount() const noexcept
			{
				return polygons.size();
			}
			inline unsigned verticesPerPoly() const noexcept
			{
				return polygons.size() > 0 ? polygons[0].points.size() : 0;
			}

		public:
			DNA(unsigned polycount = 20, unsigned verticesPerPoly = 10) noexcept;
			void mutate(unsigned imageWidth, unsigned imageHeight) noexcept;
			std::string toString(void) const;
			inline std::vector<Polygon> getPolygons() const noexcept
			{
				return polygons;
			}
			Magick::DrawableList polygonsToDraw() const;
	};

}

#endif /* end of include guard: DNA_H */

