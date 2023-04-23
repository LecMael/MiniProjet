#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <string>
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include "Snipper.h"


class Partie
{
	int indicePosPlayer;
	CoureurJoueur coureurJoueur;
	Snipper snipper;
	CoureurIA coureurIA[8];
public:
	Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites);
	void setIndice(int indice) { indicePosPlayer = indice; }
	int getIndice() { return indicePosPlayer; }
	void Sauver(ofstream &ofs, string path) const;
	void Deroulement(int indicePosPlayer);
	void creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture);
	void timer();
};

