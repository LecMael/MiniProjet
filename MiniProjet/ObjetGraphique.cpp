#include"ObjetGraphique.h"
#include <SFML/Graphics.hpp>

ObjetGraphique::ObjetGraphique(int x, int y, string image)
{
	x_ = x;
	y_ = y;
	image_ = image;
}

void ObjetGraphique::deplacement(char direction)
{
	switch (direction)
	{
	case 'D':
		x_ = x_ + 3;
		break;
	case 'G':
		x_--;
		break;
	default:
		break;
	}
}

