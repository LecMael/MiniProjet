#pragma once
#include"ObjetGraphique.h"

class CoureurIA : public ObjetGraphique //classe h�riti�re d'ObjetGraphique qui g�re un coureur contr�l� par l'ordinateur, par MOHAMAN BELLO Souley
{
public://toutes ces m�thodes ont �t� r�alis�es par MOHAMAN BELLO Souley
	CoureurIA(int x = 0, int y = 0, string image = " ");//constructeur de CoureurIA
	virtual void deplacement(char direction='I');//Cette m�thode g�re le d�placement de l'IA dans une frame.'I' signifie ind�finie.
};