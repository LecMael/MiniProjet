#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class ObjetGraphique //C'est la classe g�n�rique qui d�finit ce qu'est un objet(coureurs, snippers) � l'�cran, sans g�rer leur affichage(dessin de sprites), par MOHAMAN BELLO Souley 
{   //les champs ont �t� r�alis�s par MOHAMAN BELLO Souley
	//coordon�es de l'objet dans la fen�tre
	int x_;
	int y_;
	//chemin d'acc�s vers le sprite de l'image
	string image_;
public://Toutes ces m�thodes ont �t� r�alis�es par MOHAMAN BELLO Souley
	ObjetGraphique(int x=0, int y=0, string image=" ");//Constructeur d'ObjetGraphique qui initialise tous les champs
	int getx() const { return x_; };//retourne la valeur du champ x_
	int gety() const { return y_; };//retourne la valeur du champ y_
	string getimage() const { return image_; };//retourne la valeur du champ image
	void setx(int x) { x_ = x; };//modifie la valeur du champ x_ qui prend la valeur de x
	void sety(int y) { y_ = y; };//modifie la valeur du champ y_ qui prend la valeur de y
	void setimage(string image) { image_ = image; };//modifie la valeur du champ image_ qui prend la valeur d'image
	virtual void deplacement() { x_ = x_ + 3; };//g�re le d�placement du coureurJoueur dans une frame. 
	bool victoire(sf::Sprite* concurrent, sf::Sprite* objectif) const { return concurrent->getPosition().x + 30 > objectif->getPosition().x; };//Cette m�thode renvoie un bool�en qui indique si un coureur a frachi la ligne d'arriv�e ou pas. Elle prend en param�tre un pointeur sur le sprite du joueur consid�r� et un pointeur sur le sprite de l'objectif, ici la ligne d'arriv�e
};