#include"Snipper.h"

Snipper::Snipper(int x, int y, string image)
{
	setx(x);
	sety(y);
	setimage(image);
}

bool Snipper::victoire(sf::Sprite* concurrent, sf::Sprite* objectif) const
{
	sf::FloatRect concurrentRect = concurrent->getGlobalBounds(), objectifRect = objectif->getGlobalBounds();
	return concurrent->getOrigin().x + (round(concurrentRect.width / 2)) > objectif->getPosition().x;
}