#pragma once
#include"ObjetGraphique.h"

class CoureurIA : public ObjetGraphique//ne pas oubli�e d'initialiser la seed en d�but de main
{
public:
	CoureurIA(int x = 0, int y = 0, string image = " ");
	virtual void deplacement(char direction='I');//'I' signifie ind�finie, et donc qu'il s'agit d'un joueur contr�l� par l'IA et dont le mouvement est compl�tement al�atoire
};