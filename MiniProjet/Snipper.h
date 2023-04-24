#pragma once
#include"ObjetGraphique.h"

class Snipper : public ObjetGraphique
{
public:
	Snipper(int x = 0, int y = 0, string image = " ");
	virtual bool victoire(sf::Sprite* concurrent, sf::Sprite* objectif) const;
};