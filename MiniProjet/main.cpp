#include <SFML/Graphics.hpp>
#include <iostream>
#include<random>
#include<time.h>
//random et time servent � l'initialisation de la graine
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include"Snipper.h"



int main()
{
	//initialisation de la graine pour les d�placements de l'IA.
	srand(time(NULL));

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
	return 0;
}
