#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <string>
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include "Snipper.h"


class Partie //C'est la classe qui gère le déroulement d'une partie et sa sauvegarde, par MOHAMAN BELLO Souley et Maël LECOEUCHE
{//réalisation des champs par Mael Lecoeuche
	int indicePosPlayer_;//c'est l'indice du coureur joueur dans le tableau des coureurIA
	CoureurJoueur coureurJoueur_;//c'est le joueur jouant au clavier
	Snipper snipper_;//c'est le joueur jouant à la souris
	CoureurIA coureurIA_[8];//tableau contenant tous les coureurs IA. Une case correspondant au coureurjoueur sera laissée vide, elle sert juste à l'attribution aléatoire d'un personnage au coureur joueur
public:
	
	Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites);//Constructeur de la partie prenant les positions de départ des joueurs en paramètre,la position du joueur dans le tableau et les sprites, par Maël LECOEUCHE
	void setIndice(int indice) { indicePosPlayer_ = indice; }//modifie le champ indicePosPlayer_ qui prend la valeur du paramètre indice, par Maël LECOEUCHE
	int getIndice() { return indicePosPlayer_; }//retourne le champ indicePosPlayer_, par Maël LECOEUCHE
	void Sauver(ofstream &ofs, string path) const;//Sauvegarde les données dans des fichiers txt. On prend en paramètre le flux dans lequel écrire ofs et le nom du fichier concerné path, par Maël LECOEUCHE
	bool Deroulement();//Cette méthode gère le dessin de la fenêtre, la création et le dessin des sprites et la gestion des évènements clavier et souris(notamment le déplacement et le tir du snipper) par MOHAMAN BELLO Souley 
	void creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture, sf::Vector2f echelle=sf::Vector2f(0.125f,0.125f));//cette fonction crée un sprite à partir du chemin d'accès vers l'image à utiliser pour la texture, un pointeur sur l'objet sprite concerné, un pointeur sur sa texture et elle initialise la position du sprite dans la fenêtre grâce au paramètre position et son échelle ggrâce au paramètre echelle, par MOHAMAN BELLO Souley
	void timer(int duree);//cette méthode réalise une boucle permettant de faire passer "valeur de duree" millisecondes, par MOHAMAN BELLO Souley
	int surbrillance(sf::Sprite* snipperSprite);//cette méthode permet d'indiquer à travers l'indice à la fonction déroulement si le snipper à en visée un coureur, afin qu'il soit affiché en rouge plus tard dans déroulement. Elle prend en paramètre un pointeur sur le sprite du snipper. Par MOHAMAN BELLO Souley.
};

