#include <stdio.h>
#include "figures.h"
#include"point.h"
#include<stdlib.h>
#include "Shape.h"
#include "area.h"
#include "array.h"

int main() {
    char choixForme;
    char x1, y1;
    int x, y, len, rad, largeur, px1, py1, px2, py2, cote, i, nombres_shapes,z,q;
    int t = 1, verif = 1;
    while (t == 1) {
        do {
            printf("Veuillez choisir une action :\n"
                   "A- Ajouter une forme\n"
                   "B- Afficher la liste des formes\n"
                   "C- Supprimer une forme\n"
                   "D- Tracer le dessin\n"
                   "E- Aide\n"
                   ">> Votre choix : ");
            scanf(" %c", &x1);
        } while (x1 < 'A' || x1 > 'E');

        verif = '1';
        while (verif == '1') {
            switch (x1) {
                case 'A':
                    do {
                        printf("Veuillez choisir une forme :\n"
                               "1- Ajouter un point\n"
                               "2- Ajouter une ligne\n"
                               "3- Ajouter cercle\n"
                               "4- Ajouter un carre\n"
                               "5- Ajouter un rectangle\n"
                               "6- Ajouter un polygone\n"
                               "7- Revenir au menu precedent\n"
                               ">> Votre choix : ");

                        scanf(" %c", &choixForme);
                    } while (choixForme < '1' || choixForme > '7');

                    switch (choixForme) {
                        case '1':
                            ajouterForme(POINT);
                            break;
                        case '2':
                            ajouterForme(LINE);
                            break;
                        case '3':
                            ajouterForme(CIRCLE);
                            break;

                        case '4':
                            ajouterForme(SQUARE);
                            break;

                        case '5':
                            ajouterForme(RECTANGLE);
                            break;

                        case '6':
                            ajouterForme(POLYGON);
                            break;

                        case '7':
                            verif = 0;
                            break;
                    }
                    break;

                case 'B':
                    print_shape();
                    verif = 0;
                    break;

                case 'C':
                    supprimer_forme();
                    verif = 0;
                    break;

                case'D':
                    printf("Dessin en cours...\n");
                    printf("choissisez une zone de dessin de x*y pixels\n");
                    printf("choississez x pixels de hauteur :\n");
                    scanf("%d",&z);
                    printf("choississez x pixels de largeur :\n");
                    scanf("%d",&q);

                    Area* area = create_area(z, q); // Création d'une zone de dessin de 50x20 pixels
                    draw_area(area); // Tracer les formes dans la zone de dessin
                    print_area(area); // Afficher la zone de dessin
                    delete_area(area); // Supprimer la zone de dessin et libérer la mémoire
                    verif = 0;
                    break;
                    verif = 0;
                    break;

                case 'E':
                    printf("Ce programme permet de creer une a plusieurs formes de votre choix. Pour cela :\n");
                    printf("Aller dans le menu vous pouvez choisir 4 fonctionnalité:\n ");
                    printf(
                            "A- Ajouter une forme\n"
                            "B- Afficher la liste des formes\n"
                            "C- Supprimer une forme\n"
                            "D- Tracer le dessin\n"
                            "E- Aide\n"
                            ">> Saisir votre choix en saisissant une lettre de A a E:\n Si vous avez choisi la fonctionnalite A pour"
                            "rajouter une forme,vous pouvez choisir 6 formes en saisissant un chiffre \nde 1 a 6:\n"
                            "                       1- Ajouter un point\n"
                            "                       2- Ajouter une ligne\n"
                            "                       3- Ajouter cercle\n"
                            "                       4- Ajouter un carre\n"
                            "                       5- Ajouter un rectangle\n"
                            "                       6- Ajouter un polygone\n"
                            "                       7- Revenir au menu precedent\n ");


                    verif='0';
                    break;

            }
        }
    }
    return 0;
}