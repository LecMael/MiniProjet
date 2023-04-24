//Lecoeuche
#pragma once
#include <iostream>
using namespace std;
#include <string>

//Menu de base permettant de lancer une partie ou d'en charger une ancienne, d'afficher les règles
class Menu
{
	const string path = "C:/";
public:
	//constructeur de menu
	Menu();
	//Instancie une nouvelle partie avec des valeurs de départ standarts
	void NouvellePartie();
	//Instancie une nouvelle partie avec des valeurs de départs issues des fichiers de sauvegarde
	void ChargerPartie();
};

