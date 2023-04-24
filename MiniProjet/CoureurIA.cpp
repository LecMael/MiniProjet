#include"CoureurIA.h"
#include<random>

CoureurIA::CoureurIA(int x, int y, string image)
{
	setx(x);
	sety(y);
	setimage(image);
}

void CoureurIA::deplacement(char direction)
{
	int dir = rand() % 100 + 1;//dir est compris entre 0 et 1 et indique dans quelle direction on avance: 0 pour gauche et 1 pour droite
	if (dir < 25)//probabilité de 25% d'avancer
	{
		setx(getx() + 2);
	}
}