#ifndef EVOLVE_H
#define EVOLVE_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace Ivolve
{
	/// Applique le résultat d'une génération.
	/// \param original L'image originale.
	/// \param mother La texture de l'image mère.
	/// \param daughter La texture de rendu de l'image fille.
	void evolve(const sf::Image &original, sf::Texture &mother, sf::RenderTexture &daughter);

	/// Le nombre d'améliorations totales.
	extern unsigned improvements;

	/// Le nombre d'améliorations dues à la règle de Métropolis.
	extern unsigned metropolisRules;
	/// Le nombre de générations déjà appliquées.
	extern unsigned rounds;
}

#endif /* end of include guard: EVOLVE_H */
