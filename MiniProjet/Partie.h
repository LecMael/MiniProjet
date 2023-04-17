#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include "Snipper.h"


class Partie
{
	int indicePosPlayer;
	CoureurJoueur coureurJoueur;
	Snipper snipper;
	CoureurIA coureurIA[7];
public:
	Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites);
};

