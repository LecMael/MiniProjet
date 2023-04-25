#pragma once
#include"ObjetGraphique.h"

class CoureurJoueur : public ObjetGraphique //classe héritière d'ObjetGraphique qui gère le joueur au clavier
{
public:
	CoureurJoueur(int x = 0, int y = 0, string image = " ");//constructeur de CoureurJoueur
};