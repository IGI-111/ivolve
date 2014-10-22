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
	/// La classe représentant un génome.
	class DNA
	{
		private:
			/// Les polygones constituant le génome.
			std::vector<sf::ConvexShape> polygons;
			/// Renvoie le nombre de polygones du génome.
			inline unsigned polycount() const noexcept
			{
				return polygons.size();
			}
			/// Renvoie le nombre de sommets des polygones du génome.
			inline unsigned verticesPerPoly() const noexcept
			{
				return polygons.size() > 0 ? polygons[0].getPointCount(): 0;
			}

		public:
			/// \param polycount Le nombre de polygones du génome.
			/// \param polycount Le nombre de sommets des polygones du génome.
			DNA(unsigned polycount = 70, unsigned verticesPerPoly = 6) noexcept;
			/// Change de manière pseudo-aléatoire une des coordonées des sommets d'un polygone ou l'un des composants de sa couleur ou sa transparence.
			/// \param imageWidth La largeur de l'image originale en pixels.
			/// \param imageHeight La hauteur de l'image originale en pixels.
			void mutate(unsigned imageWidth, unsigned imageHeight) noexcept;
			/// Renvoie une chaine de caractères formatée représentant le génome.
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

