#pragma once
#include"ObjetGraphique.h"

class CoureurIA : public ObjetGraphique //classe héritière d'ObjetGraphique qui gère un coureur contrôlé par l'ordinateur, par MOHAMAN BELLO Souley
{
public://toutes ces méthodes ont été réalisées par MOHAMAN BELLO Souley
	CoureurIA(int x = 0, int y = 0, string image = " ");//constructeur de CoureurIA
	virtual void deplacement(char direction='I');//Cette méthode gère le déplacement de l'IA dans une frame.'I' signifie indéfinie.
};