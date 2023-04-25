#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class ObjetGraphique //C'est la classe générique qui définit ce qu'est un objet(coureurs, snippers) à l'écran, sans gérer leur affichage(dessin de sprites), par MOHAMAN BELLO Souley 
{   //les champs ont été réalisés par MOHAMAN BELLO Souley
	//coordonées de l'objet dans la fenêtre
	int x_;
	int y_;
	//chemin d'accès vers le sprite de l'image
	string image_;
public://Toutes ces méthodes ont été réalisées par MOHAMAN BELLO Souley
	ObjetGraphique(int x=0, int y=0, string image=" ");//Constructeur d'ObjetGraphique qui initialise tous les champs
	int getx() const { return x_; };//retourne la valeur du champ x_
	int gety() const { return y_; };//retourne la valeur du champ y_
	string getimage() const { return image_; };//retourne la valeur du champ image
	void setx(int x) { x_ = x; };//modifie la valeur du champ x_ qui prend la valeur de x
	void sety(int y) { y_ = y; };//modifie la valeur du champ y_ qui prend la valeur de y
	void setimage(string image) { image_ = image; };//modifie la valeur du champ image_ qui prend la valeur d'image
	virtual void deplacement() { x_ = x_ + 3; };//gère le déplacement du coureurJoueur dans une frame. 
	bool victoire(sf::Sprite* concurrent, sf::Sprite* objectif) const { return concurrent->getPosition().x + 30 > objectif->getPosition().x; };//Cette méthode renvoie un booléen qui indique si un coureur a frachi la ligne d'arrivée ou pas. Elle prend en paramètre un pointeur sur le sprite du joueur considéré et un pointeur sur le sprite de l'objectif, ici la ligne d'arrivée
};