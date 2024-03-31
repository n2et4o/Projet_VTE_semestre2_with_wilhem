//
// Created by 20220848 on 16/05/2023.
//

#include "area.h"
#include "Shape.h"
#include<stdlib.h>
#include<stdio.h>
#include"figures.h"
#include"id.h"

// Fonction de création d'une zone (area)
Area* create_area(unsigned int width, unsigned int height) {
    Area* area = (Area*)malloc(sizeof(Area));
    if (area == NULL) {
        printf("Erreur lors de l'allocation mémoire pour la zone (area).\n");
        return NULL;
    }

    area->width = width;
    area->height = height;

    // Allocation de la matrice des pixels
    area->mat = (BOOL**)malloc(sizeof(BOOL*) * width);
    if (area->mat == NULL) {
        printf("Erreur lors de l'allocation mémoire pour la matrice des pixels.\n");
        free(area);
        return NULL;
    }

    for (unsigned int i = 0; i < width; i++) {
        area->mat[i] = (BOOL*)malloc(sizeof(BOOL) * height);
        if (area->mat[i] == NULL) {
            printf("Erreur lors de l'allocation mémoire pour une ligne de la matrice des pixels.\n");
            // Libérer les lignes déjà allouées
            for (unsigned int j = 0; j < i; j++) {
                free(area->mat[j]);
            }
            free(area->mat);
            free(area);
            return NULL;
        }
    }

    // Initialisation du tableau des formes
    area->nb_shape = 0;

    return area;
}

void add_shape_to_area(Area* area, Shape* shape) {
    if (area->nb_shape < SHAPE_MAX) { // Vérifie si le nombre de formes ne dépasse pas la taille maximale

        // Insérer la forme dans le tableau des formes
        area->shapes[area->nb_shape] = shape;

        // Incrémenter le nombre de formes
        area->nb_shape++;
    }
}


void clear_area(Area* area) {
    for (unsigned int i = 0; i < area->width; i++) {
        for (unsigned int j = 0; j < area->height; j++) {
            area->mat[i][j] = 0;
        }
    }
}

// Fonction d'effacement des formes
void erase_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        delete_shape(area->shapes[i]);
        free(area->shapes[i]);
        area->shapes[i] = NULL;
    }
    area->nb_shape = 0;
}

// Fonction de suppression d'une zone (area)
void delete_area(Area* area) {
    erase_area(area);  // Supprime toutes les formes de la zone de dessin
    free(area->mat);   // Libère la mémoire de la matrice des pixels
    free(area);        // Libère la mémoire de la structure de la zone de dessin
}


void draw_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        Shape* shape = area->shapes[i];
        int nb_pixels = 0;
        Pixel** pixels = create_shape_to_pixel(shape, &nb_pixels);

        for (int j = 0; j < nb_pixels; j++) {
            int x = pixels[j]->px;
            int y = pixels[j]->py;

            if (x >= 0 && x < area->width && y >= 0 && y < area->height) {
                area->mat[x][y] = 1;
            }
        }

    }
}


// Fonction de d'affichage d'une zone (area)

void print_area(Area* area) {
    for (int i = 0; i < area->height; i++) {
        for (int j = 0; j < area->width; j++) {
            if (area->mat[j][i] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Fonction de création d'un pixel

Pixel* create_pixel(int px, int py) {
    Pixel* pixel = (Pixel*)malloc(sizeof(Pixel));
    if (pixel != NULL) {
        pixel->px = px;
        pixel->py = py;
    }
    return pixel;
}

// Fonction de suppression d'un pixel

void delete_pixel(Pixel* pixel) {
    free(pixel);
}

/// Fonctions de création d'une forme en pixel

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Point* point = (Point*)shape->ptrShape;
    Pixel* pixel = create_pixel(point->pos_x, point->pos_y);
    *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
    (*pixel_tab)[*nb_pixels] = pixel;
    (*nb_pixels)++;
}

void pixel_line(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Line* line = (Line*)shape->ptrShape;
    int dx = abs(line->p2->pos_x - line->p1->pos_x);
    int dy = abs(line->p2->pos_y - line->p1->pos_y);
    int sx = (line->p1->pos_x < line->p2->pos_x) ? 1 : -1;
    int sy = (line->p1->pos_y < line->p2->pos_y) ? 1 : -1;
    int err = dx - dy;

    int x = line->p1->pos_x;
    int y = line->p1->pos_y;

    while (1) {
        Pixel* pixel = create_pixel(x, y);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel;
        (*nb_pixels)++;

        if (x == line->p2->pos_x && y == line->p2->pos_y)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void pixel_square(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Square* square = (Square*)shape->ptrShape;
    int x = square->cote1.pos_x;
    int y = square->cote1.pos_y;
    int len = square->longueur;

    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            Pixel* pixel = create_pixel(i, j);
            *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
            (*pixel_tab)[*nb_pixels] = pixel;
            (*nb_pixels)++;
        }
    }
}

void pixel_rectangle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Rectangle* rectangle = (Rectangle*)shape->ptrShape;
    int x = rectangle->Rcote1.pos_x;
    int y = rectangle->Rcote1.pos_y;
    int len = rectangle->Rlongueur;
    int width = rectangle->Rlargeur;

    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + width; j++) {
            Pixel* pixel = create_pixel(i, j);
            *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
            (*pixel_tab)[*nb_pixels] = pixel;
            (*nb_pixels)++;
        }
    }
}

void pixel_circle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Circle* circle = (Circle*)shape->ptrShape;
    int x = circle->Pcentre.pos_x;
    int y = circle->Pcentre.pos_y;
    int rad = circle->rayon;

    int cx = 0;
    int cy = rad;
    int d = 3 - 2 * rad;

    while (cx <= cy) {
        Pixel* pixel1 = create_pixel(x + cx, y + cy);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel1;
        (*nb_pixels)++;

        Pixel* pixel2 = create_pixel(x - cx, y + cy);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel2;
        (*nb_pixels)++;

        Pixel* pixel3 = create_pixel(x + cx, y - cy);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel3;
        (*nb_pixels)++;

        Pixel* pixel4 = create_pixel(x - cx, y - cy);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel4;
        (*nb_pixels)++;

        Pixel* pixel5 = create_pixel(x + cy, y + cx);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel5;
        (*nb_pixels)++;

        Pixel* pixel6 = create_pixel(x - cy, y + cx);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel6;
        (*nb_pixels)++;

        Pixel* pixel7 = create_pixel(x + cy, y - cx);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel7;
        (*nb_pixels)++;

        Pixel* pixel8 = create_pixel(x - cy, y - cx);
        *pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 1) * sizeof(Pixel*));
        (*pixel_tab)[*nb_pixels] = pixel8;
        (*nb_pixels)++;

        if (d < 0) {
            d = d + 4 * cx + 6;
        } else {
            d = d + 4 * (cx - cy) + 10;
            cy--;
        }
        cx++;
    }
}

void pixel_polygon(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    Polygon* polygon = (Polygon*)shape->ptrShape;
    int numPoints = polygon->n;
    Point** points = polygon->points;

    for (int i = 0; i < numPoints; i++) {
        int x1 = points[i]->pos_x;
        int y1 = points[i]->pos_y;
        int x2 = points[(i + 1) % numPoints]->pos_x;
        int y2 = points[(i + 1) % numPoints]->pos_y;

        Line *line = {(Point *)x1,  (Point *) y1, (Point *)x2, (Point *)y2 };
        pixel_line(line, pixel_tab, nb_pixels);
    }
}

/// Fonction de création d'une forme en pixel

void pixel_forme(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
    switch (shape->shape_type) {
        case POINT:
            pixel_point(shape, pixel_tab, nb_pixels);
            break;
        case LINE:
            pixel_line(shape, pixel_tab, nb_pixels);
            break;
        case SQUARE:
            pixel_square(shape, pixel_tab, nb_pixels);
            break;
        case RECTANGLE:
            pixel_rectangle(shape, pixel_tab, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle(shape, pixel_tab, nb_pixels);
            break;
        case POLYGON:
            pixel_polygon(shape, pixel_tab, nb_pixels);
            break;
        default:
            break;
    }
}


Pixel **create_shape_to_pixel(Shape *shape, int *nb_pixels) {
    Pixel** pixel_tab = NULL; // Tableau de pixels à retourner
    *nb_pixels = 0; // Initialisation du nombre de pixels à 0

    // Appel de la fonction appropriée en fonction du type de la forme
    switch (shape->shape_type) {
        case POINT:
            pixel_point(shape, &pixel_tab, nb_pixels);
            break;
        case LINE:
            pixel_line(shape, &pixel_tab, nb_pixels);
            break;
        case SQUARE:
            pixel_square(shape, &pixel_tab, nb_pixels);
            break;
        case RECTANGLE:
            pixel_rectangle(shape, &pixel_tab, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle(shape, &pixel_tab, nb_pixels);
            break;
        case POLYGON:
            pixel_polygon(shape, &pixel_tab, nb_pixels);
            break;
        default:
            break;
    }

    return pixel_tab;
}

void delete_pixel_shape(Pixel*** pixel, int nb_pixels) {
    for (int i = 0; i < nb_pixels; i++) {
        free((*pixel)[i]); // Libérer la mémoire allouée pour chaque pixel
    }
    free(*pixel); // Libérer la mémoire allouée pour le tableau de pixels
    *pixel = NULL; // Définir le pointeur de pixel à NULL pour éviter les accès indésirables
}

