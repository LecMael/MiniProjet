#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Partie.h"
#include "Menu.h"
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include<random>

Partie::Partie(vector<int> posX,  vector<int> posY, int indicePosPlyr_, vector<string> sprites) {
	setIndice(indicePosPlyr_);
	for (int i = 0; i <= 7; i++) {
		if (i == indicePosPlyr_) {
			coureurJoueur.setx(posX[i]);
			coureurJoueur.sety(posY[i]);
			coureurJoueur.setimage(sprites[i]);
		}
		else
		{
			coureurIA[i].setx(posX[i]);
			coureurIA[i].sety(posY[i]);
			coureurIA[i].setimage(sprites[i]);
		}
	}
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(300, 300), "MiniProjet");

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	Menu menu;
}