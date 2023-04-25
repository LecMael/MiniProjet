#include"ObjetGraphique.h"
#include <SFML/Graphics.hpp>

ObjetGraphique::ObjetGraphique(int x, int y, string image)
//Constructeur d'ObjetGraphique qui initialise tous les champs
{
	x_ = x;
	y_ = y;
	image_ = image;
}



