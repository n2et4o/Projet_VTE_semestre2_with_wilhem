//
// Created by 20220848 on 16/05/2023.
//

#ifndef PROJET_VTE_SEMESTRE2_AREA_H
#define PROJET_VTE_SEMESTRE2_AREA_H
#include "Shape.h"


#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int
struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape * shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
};
typedef struct area Area;

struct pixel {
    int px;
    int py;

};
typedef struct pixel Pixel;

void delete_pixel(Pixel* pixel);
Pixel* create_pixel(int px, int py);
Pixel **create_shape_to_pixel(Shape *shape, int *nb_pixels);

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);




#endif //PROJET_VTE_SEMESTRE2_AREA_H
