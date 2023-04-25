#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <string>
#include"CoureurIA.h"
#include"CoureurJoueur.h"
#include "Snipper.h"


class Partie //C'est la classe qui g�re le d�roulement d'une partie et sa sauvegarde, par MOHAMAN BELLO Souley et Ma�l LECOEUCHE
{//r�alisation des champs par Mael Lecoeuche
	int indicePosPlayer_;//c'est l'indice du coureur joueur dans le tableau des coureurIA
	CoureurJoueur coureurJoueur_;//c'est le joueur jouant au clavier
	Snipper snipper_;//c'est le joueur jouant � la souris
	CoureurIA coureurIA_[8];//tableau contenant tous les coureurs IA. Une case correspondant au coureurjoueur sera laiss�e vide, elle sert juste � l'attribution al�atoire d'un personnage au coureur joueur
public:
	
	Partie(vector<int> posX, vector<int> posY, int indicePosPlyr, vector<string> sprites);//Constructeur de la partie prenant les positions de d�part des joueurs en param�tre,la position du joueur dans le tableau et les sprites, par Ma�l LECOEUCHE
	void setIndice(int indice) { indicePosPlayer_ = indice; }//modifie le champ indicePosPlayer_ qui prend la valeur du param�tre indice, par Ma�l LECOEUCHE
	int getIndice() { return indicePosPlayer_; }//retourne le champ indicePosPlayer_, par Ma�l LECOEUCHE
	void Sauver(ofstream &ofs, string path) const;//Sauvegarde les donn�es dans des fichiers txt. On prend en param�tre le flux dans lequel �crire ofs et le nom du fichier concern� path, par Ma�l LECOEUCHE
	bool Deroulement();//Cette m�thode g�re le dessin de la fen�tre, la cr�ation et le dessin des sprites et la gestion des �v�nements clavier et souris(notamment le d�placement et le tir du snipper) par MOHAMAN BELLO Souley 
	void creationSprite(string image, sf::Sprite* sprite, sf::Vector2f position, sf::Texture* texture, sf::Vector2f echelle=sf::Vector2f(0.125f,0.125f));//cette fonction cr�e un sprite � partir du chemin d'acc�s vers l'image � utiliser pour la texture, un pointeur sur l'objet sprite concern�, un pointeur sur sa texture et elle initialise la position du sprite dans la fen�tre gr�ce au param�tre position et son �chelle ggr�ce au param�tre echelle, par MOHAMAN BELLO Souley
	void timer(int duree);//cette m�thode r�alise une boucle permettant de faire passer "valeur de duree" millisecondes, par MOHAMAN BELLO Souley
	int surbrillance(sf::Sprite* snipperSprite);//cette m�thode permet d'indiquer � travers l'indice � la fonction d�roulement si le snipper � en vis�e un coureur, afin qu'il soit affich� en rouge plus tard dans d�roulement. Elle prend en param�tre un pointeur sur le sprite du snipper. Par MOHAMAN BELLO Souley.
};

