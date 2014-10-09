#ifndef EVOLVE_H
#define EVOLVE_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace Ivolve
{
	void evolve(const sf::Image &original, sf::Texture &mother, sf::RenderTexture &daughter);

	extern unsigned improvements;
	extern unsigned metropolisRules;
	extern unsigned rounds;
}

#endif /* end of include guard: EVOLVE_H */
