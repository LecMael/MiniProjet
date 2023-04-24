#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class ObjetGraphique
{
	//coordonées de l'objet dans la fenêtre
	int x_;
	int y_;
	//chemin d'accès vers le sprite de l'image
	string image_;
public:
	ObjetGraphique(int x=0, int y=0, string image=" ");
	int getx() const { return x_; };
	int gety() const { return y_; };
	string getimage() const { return image_; };
	void setx(int x) { x_ = x; };
	void sety(int y) { y_ = y; };
	void setimage(string image) { image_ = image; };
	virtual void deplacement(char direction = 'I');
	bool victoire(sf::Sprite* concurrent, sf::Sprite* objectif) const { return concurrent->getPosition().x + 30 > objectif->getPosition().x; };
};