//
// Created by 20220848 on 18/04/2023.
//

#include "figures.h"

// fonctions du Square

Square *create_square(Point * point, int length){
    Square *carre= (Square*) malloc(sizeof(Square));
    carre->longueur = length;
    carre->cote1 = *point;        // possède pos_x et pos_y du point en paramètre
    carre->cote2.pos_x = point->pos_x;
    carre->cote2.pos_y = point->pos_y + length;
    carre->cote3.pos_x = point->pos_x + length;
    carre->cote3.pos_y = point->pos_y ;
    carre->cote4.pos_x = point->pos_x + length;
    carre->cote4.pos_y = point->pos_y + length;
    //les pos_x et pos_y sont les mêmes du point en paramètre, la présence du "." indique qu'ils ont été copiés
    return carre;
}

void delete_square(Square * square){
    free(square);
}

void print_square(Square * square){
    printf("SQUARE : ");
    printf(" (%d %d)\n ",square->cote1.pos_x,square->cote1.pos_y);
    printf(" (%d %d)\n ",square->cote2.pos_x,square->cote2.pos_y);
    printf(" (%d %d)\n ",square->cote3.pos_x,square->cote3.pos_y);
    printf(" (%d %d)\n ",square->cote4.pos_x,square->cote4.pos_y);
}

// Fonctions du Rectangle

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle * rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    rectangle->Rlargeur = width;
    rectangle->Rlongueur = height;
    rectangle->Rcote1 = *point;
    rectangle->Rcote2.pos_x = point->pos_x;
    rectangle->Rcote2.pos_y = point->pos_y + height;
    rectangle->Rcote3.pos_x = point->pos_x + width;
    rectangle->Rcote3.pos_y = point->pos_y;
    rectangle->Rcote4.pos_x = point->pos_x + width;
    rectangle->Rcote4.pos_y = point->pos_y + height;
    return rectangle;
}

void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}

void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE :\n");
    printf("(%d %d)\n",rectangle->Rcote1.pos_x,rectangle->Rcote1.pos_y);
    printf("(%d %d)\n",rectangle->Rcote2.pos_x,rectangle->Rcote2.pos_y);
    printf("(%d %d)\n",rectangle->Rcote3.pos_x,rectangle->Rcote3.pos_y);
    printf("(%d %d)\n",rectangle->Rcote4.pos_x,rectangle->Rcote4.pos_y);
}

// fonctions du Circle

Circle *create_circle(Point * center, int radius){
    Circle * cercle = (Circle*)malloc(sizeof(Circle));
    cercle->Pcentre = *center;
    cercle->rayon = radius;
}
void delete_circle(Circle * circle){
    free(circle);
}

void print_circle(Circle * circle){
    printf("CIRCLE :\n");
    printf("(%d %d)\n",circle->Pcentre.pos_x,circle->Pcentre.pos_y);
    printf("(%d)\n",circle->rayon);
}

// fonctions du Polygon

Polygon *create_polygon(int n){
    Polygon * polygone = (Polygon*) malloc(sizeof(Polygon));
    polygone->n = n;
    polygone->points = (Point**)malloc(n * sizeof(Point*)); // tableau 1D dynamique de Point*
    int x,y;
    for (int i = 0;i < n ; i++){
        do {
            printf("Choississez les valeurs de points x et y separees par un espace:\n");
            scanf("%d %d", &x, &y);
        } while (x && y <= 0 );
        polygone->points[i] = create_point(x,y);
    }
    return polygone;
}

void print_polygon(Polygon * polygon) {
    printf("POLYGON :\n");
    for (int i = 0; i < polygon->n; i++) {
        printf("%d %d\n ",polygon->points[i]->pos_x,polygon->points[i]->pos_y);
    }
}

void delete_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->n; i++) {
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}



