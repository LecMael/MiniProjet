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
	int indicePosPlayer_;
	CoureurJoueur coureurJoueur_;
	Snipper snipper_;
	CoureurIA coureurIA_[8];
public:
	Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites);
	void setIndice(int indice) { indicePosPlayer_ = indice; }
	int getIndice() { return indicePosPlayer_; }
	void Sauver(ofstream &ofs, string path) const;
	bool Deroulement();
	void creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture, sf::Vector2f echelle=sf::Vector2f(0.125f,0.125f));
	void timer(int duree);//duree en ms
	int surbrillance(sf::Sprite* snipperSprite);
};

