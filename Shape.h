//
// Created by 20220848 on 18/04/2023.
//

#ifndef PROJET_VTE_SEMESTRE2_SHAPE_H
#define PROJET_VTE_SEMESTRE2_SHAPE_H

typedef enum { POINT  , LINE , SQUARE , RECTANGLE, CIRCLE , POLYGON } SHAPE_TYPE;

typedef struct {
    int id; // identifiant unique de la forme
    SHAPE_TYPE shape_type; // type de la forme pointé
    void *ptrShape; // pointeur sur n'importe quelle forme
}Shape;

void ajouterForme(SHAPE_TYPE type);
void supprimer_forme();

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape();


#endif //PROJET_VTE_SEMESTRE2_SHAPE_H
