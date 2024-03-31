//
// Created by 20220848 on 18/04/2023.
//

#include "point.h"
#include<stdio.h>
#include<stdlib.h>


void choisir_coordonnees(int *x, int *y) {
    printf("Entrez les coordonnees x et y separees par un espace : ");
    scanf("%d %d", x, y);        // x et y sont déjà des pointeurs d'où il y'a pas "&" devant x et y
    printf("Coordonnees saisies : x = %d, y = %d\n", *x, *y); // la présence du "*" est obligatoire sinon le printf affiche les addresses de x et y
}

Point *create_point(int px, int py){
    Point *p = (Point*)malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

void delete_point(Point * point){
    free(point);
}

void print_point(Point * p){
    printf("POINT %d %d\n",p->pos_x,p->pos_y);
}

Line *create_line(Point * p1, Point * p2){
    Line* l = (Line*)malloc(sizeof(Line));
    l->p1 = p1;
    l->p2 = p2;
    return l;
}

void delete_line(Line * line){
    free(line);
}
void print_line(Line * line){
    printf("LINE %d %d %d %d\n",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}

void choisir_polygone(int n) {
    if (n < 3 || n > 1000) {  // vérifier si n est dans les limites acceptables
        //printf("Erreur : nombre de cotes invalide.\n");
        return ;
    }

    char* nom_polygone;
    switch (n) {
        case 3:
            nom_polygone = "Triangle.\n";
            break;
        case 4:
            nom_polygone = "Quadrilatere.\n";
            break;
        case 5:
            nom_polygone = "Pentagone.\n";
            break;
        case 6:
            nom_polygone = "Hexagone.\n";
            break;
        case 7:
            nom_polygone = "Heptagone.\n";
            break;
        case 8:
            nom_polygone = "Octogone.\n";
            break;
        case 9:
            nom_polygone = "Enneagone\n";
            break;
        case 10:
            nom_polygone = "Decagone\n";
            break;
        case 11:
            nom_polygone = "Hendecagone\n";
            break;
        case 12:
            nom_polygone = " Dodecagone\n";
            break;
        case 13:
            nom_polygone = "tridecagone\n";
            break;
        case 14:
            nom_polygone = "tetradecagone\n";
            break;
        case 15:
            nom_polygone = "pentadecagone\n";
            break;
        case 16:
            nom_polygone = "hexadecagone\n";
            break;
        case 17:
            nom_polygone = "heptadecagonee\n";
            break;
        case 18:
            nom_polygone = "octadecagone\n";
            break;
        case 19:
            nom_polygone = "enneadecagone\n";
            break;
        case 20:
            nom_polygone = "icosagone\n";
            break;
        case 21:
            printf("Icosikaihenagone\n");
            break;
        case 22:
            printf("Icosikaidigone\n");
            break;
        case 23:
            printf("Icosikaitrigone\n");
            break;
        case 24:
            printf("Icosikaitetragone\n");
            break;
        case 25:
            printf("Icosikaipentagone\n");
            break;
        case 26:
            printf("Icosikaihexagone\n");
            break;
        case 27:
            printf("Icosikaiheptagone\n");
            break;
        case 28:
            printf("Icosikaioctagone\n");
            break;
        case 29:
            printf("Icosikaienneagone\n");
            break;
        case 30:
            printf("Triakaidecagone\n");
            break;
        case 31:
            printf("Triakaihenagone\n");
            break;
        case 32:
            printf("Triakaidigone\n");
            break;
        case 33:
            printf("Triakaitrigone\n");
            break;
        case 34:
            printf("Triakaitetragone\n");
            break;
        case 35:
            printf("Triakaipentagone\n");
            break;
        case 36:
            printf("Triakaihexagone\n");
            break;
        case 37:
            printf("Triakaiheptagone\n");
            break;
        case 38:
            printf("Triakaioctagone\n");
            break;
        case 39:
            printf("Triakaienneagone\n");
            break;
        case 40:
            printf("Tetracontagone\n");
            break;
        case 50:
            printf("Pentacontagone\n");
            break;
        case 60:
            printf("Hexacontagone\n");
            break;
        case 70:
            printf("Heptacontagone\n");
            break;
        case 80:
            printf("Octacontagone\n");
            break;
        case 90:
            printf("Enneacontagone\n");
            break;
        case 100:
            printf("Hectogone ou Hecatontagone\n");
            break;
        case 1000:
            printf("Chiliagone\n");
            break;
        case 10000:
            printf("Myriagone\n");
            break;
            // ajouter d'autres cas pour d'autres nombres de côtés si besoin
        default:
            nom_polygone = "Polygone de n cotes";
            break;
    }

    printf("Vous avez choisi un polygone a %d cotes qui est un %s", n, nom_polygone);
}
