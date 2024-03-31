//
// Created by 20220848 on 22/05/2023.
//

/*case '1':
                            // POINT
                            choisir_coordonnees(&x, &y);
                            Shape *shape_point = create_point_shape(x ,y);
                            break;
                        case '2':
                            // LINE
                            printf("coordonné x et y:");
                            scanf("%d %d",&px1,&py1);
                            printf("2eme coordonné x et y:");
                            scanf("%d %d",&px2,&py2);
                            Shape *shape_line = create_line_shape(px1,py1,px2, py2);


                            break;
                        case '3':
                            //cercle
                            choisir_coordonnees(&x, &y);
                            printf("Choissisez un rayon :");
                            scanf("%d",&rad);
                            Shape *shape_circle = create_circle_shape(x,y, rad);
                            break;

                        case '4':
                            // SQUARE
                            choisir_coordonnees(&x, &y);
                            Point * p4 = create_point (x, y);
                            printf("choississez une longueur :");
                            scanf("%d",&len);
                            Shape *shape_square = create_square_shape(x, y, len);
                            break;
                        case '5':
                            // rectangle
                            choisir_coordonnees(&x, &y);
                            printf("choississez une longueur :");
                            scanf("%d",&len);
                            printf("Choississez une largeur :");
                            scanf("%d",&largeur);
                            Shape *shape_rectangle = create_rectangle_shape(x, y,len,largeur);
                            break;

                        case'6':
                            do {
                                printf("Saisir le nombre de cote du polygone:");
                                scanf("%d", &cote);
                                } while(cote<3);
                                choisir_polygone(cote);
                                int* list = (int*) malloc(sizeof(int) * cote * 2) ;
                                for(i=0;i<cote;i++){
                                    printf("Choississez les coordonnees de chaque cote: \n");
                                    scanf("%d %d",&list[i*2],&list[i*2+1]);
                                }
                                printf("list = {");
                                for(i=0;i<cote*2;i++){
                                    printf("%d ",list[i]);
                                }
                                printf("}\n");
                                Shape *shape_polygone = create_polygon_shape(list,cote);
                            break;

                        case '7':
                            verif=0;
                            break;


                    }*/