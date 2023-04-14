#include "Partie.h"
#include "Menu.h"

Partie::Partie() {
	// Cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(300, 300), "MiniProjet");

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	Menu menu;
}