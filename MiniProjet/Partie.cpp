#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include <vector>
#include <string>
#include "Partie.h"
#include "Menu.h"
#include "Snipper.h"
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
	snipper.setx(0);
	snipper.sety(0);
	snipper.setimage("im.png");

	Deroulement();

	int choice, choiceSave;
	cout << "Entrez 1 : Revenir au menu et sauvegarder la partie" << endl;
	cout << "Entrez 2 : Revenir au menu sans sauvegarder" << endl;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs;
		cout << "Entrez 1 : Sauvegarder dans l'emplacement 1" << endl;
		cout << "Entrez 2 : Sauvegarder dans l'emplacement 2" << endl;
		cout << "Entrez 3 : Sauvegarder dans l'emplacement 3" << endl;
		cin >> choiceSave;
		switch (choiceSave)
		{
		case 1:
			Sauver(ofs, "sauvegarde1.txt");
			break;
		case 2:
			Sauver(ofs, "sauvegarde2.txt");
			break;
		case 3:
			Sauver(ofs, "sauvegarde3.txt");
			break;
		default:
			break;
		}
		Menu menu;
	}
	else
	{
		Menu menu;
	}
	
}

void Partie::Sauver(ofstream& ofs, string path) const {
	ofs.open(path, ofstream::trunc);
	ofs << indicePosPlayer << endl;
	ofs << coureurJoueur.getx() << "," << coureurJoueur.gety() << "," << coureurJoueur.getimage() << endl;
	for (int i = 0; i < 8; i++)
	{
		ofs << coureurIA[i].getx() << ","<< coureurIA[i].gety()<< "," << coureurIA[i].getimage()<< endl;
	}
	ofs.close();

}

void Partie::Deroulement() {
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
}