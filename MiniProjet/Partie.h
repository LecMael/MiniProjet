#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include "Snipper.h"


class Partie
{
	CoureurJoueur coureurJoueur;
	Snipper snipper;
	CoureurIA coureurIA[6];
public:
	Partie();
};

