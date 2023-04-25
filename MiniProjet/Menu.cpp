#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
using namespace std;
#include <string>
#include<vector>
#include "Menu.h"
#include "Partie.h"

//Menu de base permettant de lancer une partie ou d'en charger une ancienne
Menu::Menu()
//constructeur de menu
{
	int choice;
	cout << "Bienvenu sur Hidden in plain sight!!"<< endl;
	cout << "Entrez 1 : Lancer une partie" << endl;
	cout << "Entrez 2 : Charger une partie" << endl;
	cout << "Entrez 3 : Connaitre les regles" << endl;
	cout << "Entrez 4 : Quitter le jeu" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		NouvellePartie();
		break;
	case 2:
		ChargerPartie();
		break;
	case 3:
		cout << "Hidden in plain Sight se joue a 2 joueurs, un coureur et un snipper. Le coureur est camoufle dans une foule de personnages non joueurs. Son objectif est d'atteindre la ligne d'arrivee sans que le snipper ne le reconnaisse et l'elimine. Le snipper n'a qu'une seule chance pour trouver son adversaire"<< endl;
		cout << "Lorsqu'une partie est lancée, il y a une phase où un unique personnage apparait a l'ecran, c'est celui controle par le joueur au clavier(attention a ce que l'autre ne puisse pas voir cette phase)" << endl;
		cout << "Lorsqu'il aura mémorisé son personnage, il devra faire un clic gauche sur la fenetre pour lancer la partie" << endl;
		cout << "Lorsque le snipper a un joueur en visee, celui ci devient rouge, et il pourra faire un clic gauche a la souris pour tirer" << endl;
		cout << "le joueur au clavier ne qu'avancer avec la touche directionnelle droite" << endl;
		cout << "Appuyer sur la touche echappe pour quitter le jeu" << endl;
		cout << "BONNE CHANCE!" << endl;
		break;
	case 4:
		break;
	default:
		break;
	}
	if (choice == 3) Menu menu;
}

void Menu::NouvellePartie() 
//Instancie une nouvelle partie avec des valeurs de départ par défaut
{
	vector<int> posX = {0,0,0,0,0,0,0,0};
	vector<int> posY = {0,128,256,384,512,640,752,880};
	vector<string> sprites = {"blue_0.png","red_0.png","black_0.png","white_0.png","rose_0.png","green_0.png","yellow_0.png", "orange_0.png"};
	int indicePlayerPos = rand() % 8;

	Partie partie(posX, posY, indicePlayerPos, sprites);
}

void Menu::ChargerPartie() 
//Instancie une nouvelle partie avec des valeurs de départs issues des fichiers de sauvegarde
{
	int choiceSave;
	fstream newfile;
	string str;
	int i = 0;
	vector<int> posX;
	vector<int> posY;
	vector<string> sprites;
	string temp;
	cout << "Entrez 1 : Charger la sauvegarde 1" << endl;
	cout << "Entrez 2 : Charger la sauvegarde 2" << endl;
	cout << "Entrez 3 : Charger la sauvegarde 3" << endl;
	cin >> choiceSave;
	switch (choiceSave)
	{
	case 1:
		newfile.open("sauvegarde1.txt", ios::in);
		break;
	case 2:
		newfile.open("sauvegarde2.txt", ios::in);
		break;
	case 3:
		newfile.open("sauvegarde3.txt", ios::in);
		break;
	default:
		break;
	}
	int indicePlayerPos = 0;
	while (getline(newfile, str))
	{
		if (i == 0) {
			indicePlayerPos = stoi(str);
			i++;
		}
		else if (i == 1) {
			istringstream oss(str);
			while (!oss.eof())
			{
				oss >> temp;
				if (oss.good())
				{
					posX.push_back(stoi(temp));
				}
			}
			i++;
		}
		else if (i == 2) {
			istringstream oss(str);
			while (!oss.eof())
			{
				oss >> temp;
				if (oss.good())
				{
					posY.push_back(stoi(temp));
				}
			}
			i++;
		}
		else
		{
			istringstream oss(str);
			while (!oss.eof())
			{
				oss >> temp;
				if (oss.good())
				{
					sprites.push_back(temp);
				}
			}
			i++;
		}
	}
	Partie partie(posX, posY, indicePlayerPos, sprites);
}
