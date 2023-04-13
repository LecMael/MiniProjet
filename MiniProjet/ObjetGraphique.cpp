#include"ObjetGraphique.h"

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
		x_++;
		break;
	case 'G':
		x_--;
		break;
	default:
		break;
	}
}