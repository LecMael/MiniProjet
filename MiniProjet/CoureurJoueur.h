#pragma once
#include"ObjetGraphique.h"

class CoureurJoueur : public ObjetGraphique //classe h�riti�re d'ObjetGraphique qui g�re le joueur au clavier
{
public:
	CoureurJoueur(int x = 0, int y = 0, string image = " ");//constructeur de CoureurJoueur
};