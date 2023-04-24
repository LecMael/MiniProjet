#include <iostream>
#include<fstream>
#include<vector>
#include <string>
using namespace std;
#include <string>
#include "Menu.h"
#include "Partie.h"


Menu::Menu() {
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
		cout << "Hidden in plain Sight se joue a 2 joueurs"<< endl;
		break;
	case 4:
		break;
	default:
		break;
	}
}

void Menu::NouvellePartie() {
	vector<int> posX = { 0,0,0,0,0,0,0,0 };
	vector<int> posY = { 0,128,256,384,512,640,752,880 };
	vector<string> sprites = { "blue_0.png","red_0.png","black_0.png","white_0.png","rose_0.png","green_0.png","yellow_0.png", "orange_0.png" };
	int indicePlayerPos = rand() % 8;

	Partie partie(posX, posY, indicePlayerPos, sprites);
}

void Menu::ChargerPartie() {
	
}

void Menu::Quitter() {

}