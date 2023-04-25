//Lecoeuche
#pragma once
#include <iostream>
using namespace std;
#include <string>

//Menu de base permettant de lancer une partie ou d'en charger une ancienne, d'afficher les r�gles, enti�rement r�alis� par Ma�l LECOEUCHE
class Menu
{
	const string path = "C:/";
public:
	//constructeur de menu
	Menu();
	//Instancie une nouvelle partie avec des valeurs de d�part par d�faut
	void NouvellePartie();
	//Instancie une nouvelle partie avec des valeurs de d�parts issues des fichiers de sauvegarde
	void ChargerPartie();
};

