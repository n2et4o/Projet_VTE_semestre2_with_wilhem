//
// Created by 20220848 on 18/04/2023.
//

#include "Shape.h"
#include<stdlib.h>
#include<stdio.h>
#include"figures.h"
#include"id.h"

// Tableau de formes
Shape *formes[100];
unsigned int nbFormes = 0;
static int n = 0;
unsigned int x ,y ,len,rad,largeur,px1,py1,px2, py2,cote,i,verif=1;;


Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id() ; // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    formes[n] = shp;
    n++; // Incrémenter le nombre de formes créées
    return shp;
}


// Fonction pour ajouter une forme

void ajouterForme(SHAPE_TYPE type) {
    Shape nouvelleForme;
    nouvelleForme.id = nbFormes + 1;
    nouvelleForme.shape_type = type;
    nouvelleForme.ptrShape = NULL;

    switch (type) {
        case POINT:
            // POINT
            choisir_coordonnees(&x, &y);
            Shape *shape_point = create_point_shape(x ,y);
            nouvelleForme.ptrShape = shape_point;
            break;

        case LINE:
            // LINE
            printf("Entrez les premieres coordonnees x et y separees par un espace :");
            scanf("%d %d",&px1,&py1);
            printf("Entrez les secondes coordonnees x et y separees par un espace :");
            scanf("%d %d",&px2,&py2);
            Shape *shape_line = create_line_shape(px1,py1,px2, py2);
            nouvelleForme.ptrShape = shape_line;
            break;

        case CIRCLE:
            //cercle
            choisir_coordonnees(&x, &y);
            printf("Choissisez un rayon :");
            scanf("%d",&rad);
            Shape *shape_circle = create_circle_shape(x,y, rad);
            nouvelleForme.ptrShape = shape_circle;
            break;

        case SQUARE:
            // SQUARE
            choisir_coordonnees(&x, &y);
            Point * p4 = create_point (x, y);
            printf("choississez une longueur :");
            scanf("%d",&len);
            Shape *shape_square = create_square_shape(x, y, len);
            nouvelleForme.ptrShape = shape_square;
            break;

        case RECTANGLE:
            // rectangle
            choisir_coordonnees(&x, &y);
            printf("choississez une longueur :");
            scanf("%d",&len);
            printf("Choississez une largeur :");
            scanf("%d",&largeur);
            Shape *shape_rectangle = create_rectangle_shape(x, y,len,largeur);
            nouvelleForme.ptrShape = shape_rectangle;
            break;

        case POLYGON:
            do {
                printf("Saisir le nombre de cote du polygone:");
                scanf("%d", &cote);
            } while(cote<3);
            choisir_polygone(cote);
            int* list = (int*) malloc(sizeof(int) * cote * 2) ;
            for(i=0;i<cote;i++){
                printf("Choississez les coordonnees de chaque cote (x y) : \n");
                scanf("%d %d",&list[i*2],&list[i*2+1]);
            }
            printf("list = {");
            for(i=0;i<cote*2;i++){
                printf("%d ",list[i]);
            }
            printf("}\n");
            Shape *shape_polygone = create_polygon_shape(list,cote);
            nouvelleForme.ptrShape = shape_polygone;
            break;

        case '7':
            verif=0;
            break;

        default:
            printf("Type de forme non valide.\n");
            return;
    }

    *formes[nbFormes++] = (nouvelleForme);
    printf("La forme a ete ajoutee avec succes.\n");
}

void print_shape() {
    for (int i = 0; i < nbFormes; i++) {
        Shape *shape = formes[i];
        printf("ID : %d, TYPE : %d\n", shape->id, shape->shape_type);
        switch (shape->shape_type) {
            case POINT:
                printf("%d : ", i + 1);

                print_point((Point*) shape->ptrShape);
                break;
            case LINE:
                printf("%d : ", i + 1);
                print_line((Line *) shape->ptrShape);
                break;
            case RECTANGLE:
                printf("%d : ", i + 1);
                print_rectangle((Rectangle *) shape->ptrShape);
                break;
            case CIRCLE:
                printf("%d : ", i + 1);
                print_circle((Circle *) shape->ptrShape);
                break;
            case POLYGON:
                printf("%d : ", i + 1);
                print_polygon((Polygon *) shape->ptrShape);
                break;
        }
    }

}
// Shape Point

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    print_point(p);
    return shp;
}

// Shape Line

Shape* create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point* p1 = (Point *) malloc(sizeof (Point));
    Point* p2 = (Point *) malloc(sizeof (Point));
    p1->pos_x = px1;
    p1->pos_y = py1;
    p2->pos_x = px2;
    p2->pos_y = py2;
    Line *l = create_line(p1, p2);
    shp->ptrShape = l;
    return shp;
}

// Shape Square

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point* p_square = (Point *) malloc(sizeof (Point));
    p_square->pos_x = px;
    p_square->pos_y = py;
    Square* square = create_square( p_square, length);
    shp->ptrShape = square;
    return shp;
}

// Shape rectangle

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point* p_rectangle = (Point *) malloc(sizeof (Point));
    p_rectangle->pos_x = px;
    p_rectangle->pos_y = py;
    Rectangle *rectangle = create_rectangle(p_rectangle, width,height);
    shp->ptrShape = rectangle;
    return shp;
}

// Shape Circle

Shape *create_circle_shape(int px, int py, int radus){
    Shape *shp = create_empty_shape(CIRCLE);
    Point* p_circle = (Point *) malloc(sizeof (Point));
    p_circle->pos_x = px;
    p_circle->pos_y = py;
    Circle *circle = create_circle(p_circle,radus);
    shp->ptrShape = circle;
    print_circle(circle);
    return shp;
}

// Shape Polygon

Shape *create_polygon_shape(int lst[], int n) // lst[], tableau 1D dynamique de Point*
 {
    Shape * shp = create_empty_shape(POLYGON);
     Polygon* polygone = (Polygon*) malloc(sizeof (Polygon));
     polygone->n = n;
     polygone->points = (Point**)malloc(n*sizeof(Point*));
    int x,y;
     for (int i = 0; i < n; i++) {
         polygone->points[i] = (Point*)malloc(sizeof(Point));
         polygone->points[i]->pos_x = lst[i*2];
         polygone->points[i]->pos_y = lst[i*2 +1];
     }
     shp->ptrShape = polygone;
    print_polygon(polygone);
     return shp;
}

void delete_shape(Shape *shape) {
    switch (shape->shape_type) {
        case POINT:
            delete_point(shape->ptrShape);
            break;
        case LINE:
            delete_line(((Line *) shape->ptrShape));
            break;
        case RECTANGLE:
            delete_rectangle(((Rectangle *) shape->ptrShape));
            break;
        case CIRCLE:
            delete_circle((Circle *) &shape->ptrShape);
            break;
        case POLYGON:
            delete_polygon((Polygon * ) &shape->ptrShape );
            break;
    }
}

void supprimer_forme() {
    printf("Veuillez saisir l'ID de la forme a supprimer : ");
    int idSupprimer;
    scanf("%d", &idSupprimer);

    int indexSupprimer = -1;
    for (int i = 0; i < nbFormes; i++) {
        if (formes[i]->id == idSupprimer) {
            indexSupprimer = i;
            break;
        }
    }
    if (indexSupprimer != -1) {
        delete_shape(&formes[indexSupprimer]);
        // Supprimer la forme de la liste en décalant les éléments vers la gauche
        for (int i = indexSupprimer; i < nbFormes - 1; i++) {
            formes[i] = formes[i + 1];
        }

        nbFormes--;
        printf("La forme avec l'ID %d a ete supprimee.\n", idSupprimer);
    } else {
        printf("Aucune forme avec l'ID %d n'a ete trouvee.\n", idSupprimer);
    }
}
