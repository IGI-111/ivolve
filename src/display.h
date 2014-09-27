#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace Ivolve
{
	void display(const sf::Image &original, const sf::Texture &mother, const sf::RenderTexture &daughter);
}

#endif /* end of include guard: DISPLAY_H */
