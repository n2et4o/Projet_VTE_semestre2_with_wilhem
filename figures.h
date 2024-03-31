//
// Created by 20220848 on 18/04/2023.
//

#ifndef PROJET_VTE_SEMESTRE2_FIGURES_H
#define PROJET_VTE_SEMESTRE2_FIGURES_H

#include<stdlib.h>
#include<stdio.h>
#include"point.h"

// stucture et fonctions de Square
typedef struct {
    Point cote1;  // Coin supérieur gauche
    Point cote2; // Coin supérieur droit
    Point cote3; // Coin inférieur gauche
    Point cote4; // Coin inférieur droit
    int longueur; // Longueur du côté
} Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

// stucture et fonctions du Rectangle
typedef struct{
    Point Rcote1;  // Coin supérieur gauche
    Point Rcote2; // Coin supérieur droit
    Point Rcote3; // Coin inférieur gauche
    Point Rcote4; // Coin inférieur droit
    int Rlongueur; // Longueur du côté
    int Rlargeur; // Largeur du côté
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

// stucture et fonctions du cercle

typedef struct{
    Point Pcentre;
    int rayon ;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

// stucture et fonctions du polygone

typedef struct {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

Polygon *create_polygon(int n);
void print_polygon(Polygon * polygon);
void delete_polygon(Polygon * polygon);


#endif //PROJET_VTE_SEMESTRE2_FIGURES_H
