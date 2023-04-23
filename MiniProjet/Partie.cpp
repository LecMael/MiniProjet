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
#include<time.h>

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
	//snipper.setimage("im.png");

	Deroulement(indicePosPlyr_);

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

void Partie::timer()
{
	clock_t debut, fin;
	debut = clock();
	fin = debut;
	do
	{
		fin = clock();
	} while (fin - debut < 5);//10ms
}

void Partie::creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture)
{
	if (!(*texture).loadFromFile(image));
	{
		cout << "erreur dans la création de la texture" << endl;
	}
	sprite->setTexture(*texture);
	sprite->setScale(sf::Vector2f(0.25f, 0.25f));
	sprite->setPosition(position);
}

void Partie::Deroulement(int indicePosPlayer) {
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "MiniProjet");

	//Création du sprite du joueur
	sf::Sprite joueur;
	sf::Texture texture;
	creationSprite(coureurJoueur.getimage(), &joueur, sf::Vector2f(coureurJoueur.getx(), coureurJoueur.gety()), &texture);

	//Création des sprites des IA
	sf::Sprite joueursIA[8];
	sf::Texture textureIA[8];
	for (int i = 0; i < 8; i++)
	{
		if (not(i == indicePosPlayer))
		{
			creationSprite(coureurIA[i].getimage(), &joueursIA[i], sf::Vector2f(coureurIA[i].getx(), coureurIA[i].gety()), &textureIA[i]);
		}
	}
	

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed://demande de fermeture de la fenêtre
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Right)
				{
					coureurJoueur.deplacement('D');
					joueur.setPosition(sf::Vector2f(coureurJoueur.getx(), coureurJoueur.gety()));
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//lancer la procédure de victoire
				}
				break;
			case sf::Event::MouseMoved:
				//deplacement du curseur
				break;
			default:
				break;
			}
		}

		

		//on fait avancer les joueurs IA
		for (int i = 0; i < 8; i++)
		{
			if (not(i == indicePosPlayer))
			{
				coureurIA[i].deplacement('I');
				joueursIA[i].setPosition(sf::Vector2f(coureurIA[i].getx(), coureurIA[i].gety()));
			}
		}

		//on lance le timer
		
		window.clear(sf::Color::Black);

		timer();
		//on dessine les sprites en commençant par celui de l'arène
		window.draw(joueur);
		//on dessine les joueurs IA
		for (int i = 0; i < 8; i++)
		{
			if (not(i == indicePosPlayer))
			{
				window.draw(joueursIA[i]);
			}
		}

		window.display();
		
	}
}

