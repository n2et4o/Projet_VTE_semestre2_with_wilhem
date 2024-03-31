//
// Created by 20220848 on 18/04/2023.
//

#ifndef PROJET_VTE_SEMESTRE2_POINT_H
#define PROJET_VTE_SEMESTRE2_POINT_H


// fonction de choix de coordonnees
void choisir_coordonnees(int *x, int *y);

// Définition du type point
typedef struct{
    int pos_x;
    int pos_y;
}Point;

// Prototype des fonctions utilisant Point
Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

// Définition du type line
typedef struct{
    Point *p1;
    Point *p2;
}Line;

// Prototype des fonctions utilisant Line
Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

void choisir_polygone(int n);


#endif //PROJET_VTE_SEMESTRE2_POINT_H
