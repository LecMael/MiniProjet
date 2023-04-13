#pragma once
#include"ObjetGraphique.h"

class CoureurIA : public ObjetGraphique//ne pas oubliée d'initialiser la seed en début de main
{
public:
	CoureurIA(int x = 0, int y = 0, string image = " ");
	virtual void deplacement(char direction='I');//'I' signifie indéfinie, et donc qu'il s'agit d'un joueur contrôlé par l'IA et dont le mouvement est complètement aléatoire
};