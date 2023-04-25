#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include <string>
#include "Partie.h"
#include "Menu.h"
#include "Snipper.h"
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include<time.h>

//Constructeur de la partie prenant les positions de départ des joueurs en paramètre
Partie::Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites)
//Constructeur de la partie prenant les positions de départ des joueurs en paramètre,la position du joueur dans le tableau et les sprites, par Maël LECOEUCHE
{
	//L'indice indique l'endroit où se situe le joueur coureur
	setIndice(indicePosPlyr);
	for (int i = 0; i <= 7; i++) {
		if (i == indicePosPlayer_) {
			coureurJoueur_.setx(posX[i]);
			coureurJoueur_.sety(posY[i]);
			coureurJoueur_.setimage(sprites[i]);
		}
		else
		{
			coureurIA_[i].setx(posX[i]);
			coureurIA_[i].sety(posY[i]);
			coureurIA_[i].setimage(sprites[i]);
		}
	}
	//On place le snipper à une postion par défaut car sa position importe peu
	snipper_.setx(512);
	snipper_.sety(512);
	snipper_.setimage("snipper.png");

	bool fin=Deroulement();//indique si la partie a été achevée(true) ou interrompue(false)
	//On teste si la partie est achevée ou non
	if (not(fin))
	{
		//Si elle ne l'est pas on propose au joueur de sauvegarder
		int choice, choiceSave;
		cout << "Entrez 1 : Revenir au menu et sauvegarder la partie" << endl;
		cout << "Entrez 2 : Revenir au menu sans sauvegarder" << endl;
		cin >> choice;
		if (choice == 1)
		{
			//On peut sauvegarder dans 3 fichiers en écrasant le contenu précédent si le fichier est non vide
			ofstream ofs;
			cout << "Entrez 1 : Sauvegarder dans l'emplacement 1" << endl;
			cout << "Entrez 2 : Sauvegarder dans l'emplacement 2" << endl;
			cout << "Entrez 3 : Sauvegarder dans l'emplacement 3" << endl;
			cin >> choiceSave;
			switch (choiceSave)
			{
			case 1:
				Sauver(ofs, "sauvegarde1.txt");
				break;
			case 2:
				Sauver(ofs, "sauvegarde2.txt");
				break;
			case 3:
				Sauver(ofs, "sauvegarde3.txt");
				break;
			default:
				break;
			}
		}
	}
	Menu menu;
}

void Partie::Sauver(ofstream& ofs, string path) const 
//Sauvegarde les données dans des fichiers txt. On prend en paramètre le flux dans lequel écrire ofs et le nom du fichier concerné path, par Maël LECOEUCHE
{
	//On ouvre le fichier du nom donné en paramètre en s'assurant d'écraser le contenu précédent
	ofs.open(path, ofstream::trunc);
	// en première place du tableau on met la position du joueur dans les coureur
	ofs << indicePosPlayer_ << endl;
	//On place les X, les Y et les sprites dans un tableau en prenant soin de conserver le joueur à la même position
	for (int i = 0; i < 8; i++)
	{
		if (i == indicePosPlayer_) {
			ofs << coureurJoueur_.getx() << " ";
		}
		else
		{
			ofs << coureurIA_[i].getx() << " ";
		}
	}
	ofs << endl;

	for (int i = 0; i < 8; i++)
	{
		if (i == indicePosPlayer_) {
			ofs << coureurJoueur_.gety() << " ";
		}
		else
		{
			ofs << coureurIA_[i].gety() << " ";
		}

	}
	ofs << endl;

	for (int i = 0; i < 8; i++)
	{
		if (i == indicePosPlayer_) {
			ofs << coureurJoueur_.getimage() << " ";
		}
		else
		{
			ofs << coureurIA_[i].getimage() << " ";
		}

	}
	ofs.close();

}

void Partie::timer(int duree)
//cette méthode réalise une boucle permettant de faire passer "valeur de duree" millisecondes, par MOHAMAN BELLO Souley
{
	clock_t debut, fin;
	debut = clock();
	fin = debut;
	do
	{
		fin = clock();
	} while (fin - debut < duree);
}

void Partie::creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture, sf::Vector2f echelle)
//cette fonction crée un sprite à partir du chemin d'accès vers l'image à utiliser pour la texture, un pointeur sur l'objet sprite concerné, un pointeur sur sa texture et elle initialise la position du sprite dans la fenêtre grâce au paramètre position et son échelle ggrâce au paramètre echelle, par MOHAMAN BELLO Souley
{
	if (!(*texture).loadFromFile(image));
	{
		cout << "erreur dans la création de la texture" << endl;
	}
	sprite->setTexture(*texture);
	sprite->setScale(echelle);
	sprite->setPosition(position);
}

int Partie::surbrillance(sf::Sprite* snipperSprite)
//cette méthode permet d'indiquer à travers l'indice à la fonction déroulement si le snipper à en viser un coureur, afin qu'il soit affiché en rouge plus tard dans déroulement. Elle prend en paramètre un pointeur sur le sprite du snipper. Par MOHAMAN BELLO Souley.
{
	int i = 0, indice = -1;
	while(i<8)
	{
		//on teste si le snipper est dans le voisinage d'un joueurIA, auquel cas on renvoie son indice, sinon on renvoie 8 si il est dans le voisniage d'un joueur, sinon on renvoie -1
		if (not(i == indicePosPlayer_))
		{
			if ((snipperSprite->getPosition().x <= coureurIA_[i].getx() && snipperSprite->getPosition().x >= coureurIA_[i].getx() - 40) && ((snipperSprite->getPosition().y >= coureurIA_[i].gety() && snipperSprite->getPosition().y <= coureurIA_[i].gety() + 20)))
			{
				indice = i;
				i = 8;
			}
		}
		i++;
	}
	if ((indice == -1))
	{
		if ((snipperSprite->getPosition().x <= coureurJoueur_.getx() && snipperSprite->getPosition().x >= coureurJoueur_.getx() - 40) && ((snipperSprite->getPosition().y >= coureurJoueur_.gety() && snipperSprite->getPosition().y <= coureurJoueur_.gety() + 20))) indice = 8;
	}
	return indice;
}

bool Partie::Deroulement()
//Cette méthode gère le dessin de la fenêtre, la création et le dessin des sprites et la gestion des évènements clavier et souris(notamment le déplacement et le tir du snipper) par MOHAMAN BELLO Souley
{
	int avanceIA = 0, attributionrealisee = 0, indice = -1;
	bool acheve = false;
	bool fin[3] = {false,false,false};//indique si une partie est gagnée, i=0: coureur, i=1: snipper et i=2: IA 
	
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "MiniProjet");
	//Lancement d'une musique
	sf::Music music;
	if (!music.openFromFile("music.WAV")) {
		cout << "erreur musique";
	}
	//On joue la musique en boucle
	music.setLoop(true);
	music.play();

	//Création de l'arène
	sf::Sprite arene;
	sf::Texture areneTexture;
	creationSprite("arene.png", &arene, sf::Vector2f(0, 0), &areneTexture,sf::Vector2f(1,1));

	//Création du sprite du joueur
	sf::Sprite joueur;
	sf::Texture texture;
	creationSprite(coureurJoueur_.getimage(), &joueur, sf::Vector2f(coureurJoueur_.getx(), coureurJoueur_.gety()), &texture);

	//Création du sprite du joueur mis en surbrillance
	sf::Sprite joueurSur;
	sf::Texture textureSur;
	creationSprite(coureurJoueur_.getimage(), &joueurSur, sf::Vector2f(coureurJoueur_.getx(), coureurJoueur_.gety()), &textureSur);
	joueurSur.setColor(sf::Color::Red);

	//Création des sprites des IA
	sf::Sprite joueursIA[8];
	sf::Texture textureIA[8];
	for (int i = 0; i < 8; i++)
	{
		if (not(i == indicePosPlayer_))
		{
			creationSprite(coureurIA_[i].getimage(), &joueursIA[i], sf::Vector2f(coureurIA_[i].getx(), coureurIA_[i].gety()), &textureIA[i]);
		}
	}

	//Création des sprites des IA en surbrillance
	sf::Sprite joueursIASur[8];
	sf::Texture textureIASur[8];
	for (int i = 0; i < 8; i++)
	{
		if (not(i == indicePosPlayer_))
		{
			creationSprite(coureurIA_[i].getimage(), &joueursIASur[i], sf::Vector2f(coureurIA_[i].getx(), coureurIA_[i].gety()), &textureIASur[i]);
			joueursIASur[i].setColor(sf::Color::Red);
		}
	}

	//Création du sprite du snipper
	sf::Sprite snipperSprite;
	sf::Texture snipperTexture;
	creationSprite(snipper_.getimage(), &snipperSprite, sf::Vector2f(snipper_.getx(), snipper_.gety()), &snipperTexture);

	//Création du sprite de la ligne d'arrivée
	sf::Sprite arriveSprite;
	sf::Texture arriveeTexture;
	creationSprite("arrivee.png", &arriveSprite, sf::Vector2f(980, 0), &arriveeTexture, sf::Vector2f(1,1));
	arriveSprite.setScale(sf::Vector2f(1, 1));
	

	// Boucle principale
	while (window.isOpen())
	{
		window.setMouseCursorVisible(false);//pour masquer le curseur

		if ((fin[0]) || (fin[1]) || (fin[2]))//on teste si la partie est gagnée
		{
			acheve = true;
			music.stop();
			window.close();
		}

		indice = surbrillance(&snipperSprite);//on vérifie si le snipper a un coureur en visée

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed://demande de fermeture de la fenêtre
				music.stop();
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Right)
				{
					coureurJoueur_.deplacement();
					joueur.setPosition(sf::Vector2f(coureurJoueur_.getx(), coureurJoueur_.gety()));
					joueurSur.setPosition(sf::Vector2f(coureurJoueur_.getx(), coureurJoueur_.gety()));
					//on teste si le coureurjoueur a gagné la partie
					fin[0] = coureurJoueur_.victoire(&joueur, &arriveSprite);
					
				}
				if (event.key.code == sf::Keyboard::Escape)//on met la partie en pause, donc fermeture de la fenêtre en appuyant sur échappe
				{
					music.stop();
					window.close();
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (attributionrealisee == 0) attributionrealisee++;//Pour indiquer que le joueur souhaite mettre fin à la phase d'attribution et lancer la partie
					else// le snipper a tiré, on vérifie si sa cible était la bonne
					{
						if (indice == 8) fin[1] = true;
						else fin[0] = true;
					}
				}
				break;
			case sf::Event::MouseMoved://mouvement du snipper
				snipperSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
				break;
			default:
				break;
			}
		}

		

		//on fait avancer les joueurs IA si la phase d'attribution est terminée et la partie lancée(après le GO!)
		if (attributionrealisee > 1)
		{
			for (int i = 0; i < 8; i++)
			{
				if (not(i == indicePosPlayer_))
				{
					coureurIA_[i].deplacement();
					joueursIA[i].setPosition(sf::Vector2f(coureurIA_[i].getx(), coureurIA_[i].gety()));
					joueursIASur[i].setPosition(sf::Vector2f(coureurIA_[i].getx(), coureurIA_[i].gety()));
					timer(5);
				}
			}
		}

		//on lance le timer
		
		window.clear(sf::Color::Black);

		
		//on dessine les sprites en commençant par celui de l'arène

		window.draw(arene);

		window.draw(arriveSprite);//on dessine la ligne d'arrivée

		//on dessine le joueur
		if (indice == 8)//le snipper a le joueur en visée
		{
			window.draw(joueurSur);
		}
		else
		{
			window.draw(joueur);
		}

		//on dessine les joueurs IA si la phase d'attribution est terminé
		if (attributionrealisee >= 1)
		{
			attributionrealisee++;
			for (int i = 0; i < 8; i++)
			{
				if (not(i == indicePosPlayer_))
				{
					if(indice==i) window.draw(joueursIASur[i]);
					else window.draw(joueursIA[i]);
					//on teste si un joueur IA a atteint la ligne d'arrivée
					if (not(fin[0]) && not(fin[1]) && not(fin[2])) fin[2] = coureurIA_[i].victoire(&joueursIA[i], &arriveSprite);
				}
			}
		}

		window.draw(snipperSprite);//on dessine le snipper

		//phase d'attribution:indique au joueur qui est son personnage
		if (attributionrealisee == 2)//le joueur souhaite lancer la partie, donc il faudra afficher GO! à l'écran. Cette boucle crée le sprite GO!
		{
			sf::Sprite go;
			sf::Texture gotexture;
			creationSprite("go.png", &go, sf::Vector2f(0, 0), &gotexture, sf::Vector2f(1, 1));
			window.draw(go);
		}
		


		if (fin[0])//victoire du coureur
		{
			sf::Sprite victoireCoureur;
			sf::Texture victoireCoureurtexture;
			creationSprite("victoirejoueur.png", &victoireCoureur, sf::Vector2f(0, 0), &victoireCoureurtexture, sf::Vector2f(1, 1));
			window.draw(victoireCoureur);
		}

		if (fin[1])//victoire du snipper
		{
			sf::Sprite victoireSnipper;
			sf::Texture victoireSnippertexture;
			creationSprite("victoiresnipper.png", &victoireSnipper, sf::Vector2f(0, 0), &victoireSnippertexture, sf::Vector2f(1, 1));
			window.draw(victoireSnipper);
		}

		if (fin[2])//match nul, un IA a franchi la ligne d'arrivée en premier
		{
			sf::Sprite victoireIA;
			sf::Texture victoireIAtexture;
			creationSprite("matchNul.png", &victoireIA, sf::Vector2f(0, 0), &victoireIAtexture, sf::Vector2f(1, 1));
			window.draw(victoireIA);
		}

		window.display();

		if ((fin[0]) || (fin[1]) || (fin[2])) timer(5000);//Pour faire afficher le message de victoire pendant 5s
		if (attributionrealisee == 2) timer(500);//pour afficher GO! pendant 0,5s
		
		
	}
	return acheve;
}

