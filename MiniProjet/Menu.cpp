#include <iostream>
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
	Partie partie;
}

void Menu::ChargerPartie() {

}

void Menu::Quitter() {

}