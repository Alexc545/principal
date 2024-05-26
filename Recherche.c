#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fonction d'affichage de fichier Athlete
void afficherFichierAthlete(FILE* Athlete) {
    int j;  // valeur pour le jour
    int m;  // valeur pour le mois
    int a;  // valeur pour l'année
    int epreuve;  // type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
    int temps; // temps en secondes
    int place; // place dans le relais =0 si pas prise en compte

    printf("\n Affichage dossier athlete : \n");

    // Boucle pour parcourir le fichier et afficher les données
    while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve, &temps, &place) == 6) {
        printf(" %d/%d/%d ", j, m, a);
        switch (epreuve) {
            case 1: printf("100m "); break;
            case 2: printf("400m "); break;
            case 3: printf("5000m "); break;
            case 4: printf("marathon "); break;
            case 5: printf("relais 4*400m "); break;
            default: printf("epreuve inconnue "); break;
        }
        printf("%d sec", temps);
        if (place != 0) {
            printf(" %d place", place);
        }
        printf("\n");
    }

    rewind(Athlete); // Remonter au début du fichier
}

// Fonction pour ajouter un entraînement
void ajoutFichierAthlete(FILE* Athlete) {
    int j;  // valeur pour le jour
    int m;  // valeur pour le mois
    int a;  // valeur pour l'année
    int epreuve; // type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
    int temps; // temps en secondes
    int place = 0; // place dans le relais =0 si pas prise en compte

    printf("\n Ajout athlete : \n");
    printf("Rentrer le jour de l'épreuve sous forme d'entier : ");
    scanf("%d", &j);
    while (j < 1 || j > 31) {
        printf("Erreur : jour invalide.\n");
        printf("Rentrer le jour de l'épreuve sous forme d'entier : ");
        scanf("%d", &j);
    }

    printf("Rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m);
    while (m < 1 || m > 12) {
        printf("Erreur : mois invalide.\n");
        printf("Rentrer le mois de l'épreuve sous forme d'entier : ");
        scanf("%d", &m);
    }

    printf("Rentrer l'année de l'épreuve sous forme d'entier : ");
    scanf("%d", &a);
    while (a < 1 || a > 9999) {
        printf("Erreur : année invalide.\n");
        printf("Rentrer l'année de l'épreuve sous forme d'entier : ");
        scanf("%d", &a);
    }

    printf("Type d'épreuve : entrer 1 pour 100m, 2 pour 400m, 3 pour 5000m, 4 pour marathon, 5 pour relais 4*400m : ");
    scanf("%d", &epreuve);
    while (epreuve < 1 || epreuve > 5) {
        printf("Erreur : type d'épreuve invalide.\n");
        printf("Type d'épreuve : entrer 1 pour 100m, 2 pour 400m, 3 pour 5000m, 4 pour marathon, 5 pour relais 4*400m : ");
        scanf("%d", &epreuve);
    }

    printf("Rentrer le temps en secondes : ");
    scanf("%d", &temps);

    if (epreuve == 5) {
        printf("Rentrer la place dans le relais (entre 1 et 4) : ");
        scanf("%d", &place);
        while (place < 1 || place > 4) {
            printf("Erreur : place invalide.\n");
            printf("Rentrer la place dans le relais (entre 1 et 4) : ");
            scanf("%d", &place);
        }
    }

    fseek(Athlete, 0, SEEK_END); // aller à la fin du fichier
    fprintf(Athlete, "%d;%d;%d;%d;%d;%d\n", j, m, a, epreuve, temps, place);

    rewind(Athlete); // Remonter au début du fichier
}

void RechercherAthlete() {
    int choix = -1;
    char nom[33];
    char nomfichier[37];

    printf("\n Recherche athlete : \n");
    printf("Rentrer le nom de l'athlete que vous cherchez : ");
    scanf("%32s", nom);

    strcpy(nomfichier, nom);
    strcat(nomfichier, ".txt");

    FILE *Athlete = fopen(nomfichier, "r+");
    if (Athlete == NULL) {
        printf("Erreur : l'athlete n'est pas dans notre base de donnée.\n");
        return;
    }

    printf("Pour afficher le fichier de l'athlete taper 1 : \nPour ajouter un entrainement taper 2 : \n");
    scanf("%d", &choix);
    while (choix < 1 || choix > 2) {
        printf("Erreur : choix invalide.\n");
        printf("Pour afficher le fichier de l'athlete taper 1 : \nPour ajouter un entrainement taper 2 : \n");
        scanf("%d", &choix);
    }

    if (choix == 1) {
        afficherFichierAthlete(Athlete);
    } else if (choix == 2) {
        ajoutFichierAthlete(Athlete);
    }

    fclose(Athlete);
}

void RechercherDate() {
    int j, m, a;
    int j2, m2, a2;
    int epreuve, temps, place;
    char nom[33];
    char nomfichier[37];

    printf("\n Recherche date : \n");

    printf("Rentrer le jour de l'épreuve sous forme d'entier : ");
    scanf("%d", &j);
    while (j < 1 || j > 31) {
        printf("Erreur : jour invalide.\n");
        printf("Rentrer le jour de l'épreuve sous forme d'entier : ");
        scanf("%d", &j);
    }

    printf("Rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m);
    while (m < 1 || m > 12) {
        printf("Erreur : mois invalide.\n");
        printf("Rentrer le mois de l'épreuve sous forme d'entier : ");
        scanf("%d", &m);
    }

    printf("Rentrer l'année de l'épreuve sous forme d'entier : ");
    scanf("%d", &a);
    while (a < 1 || a > 9999) {
        printf("Erreur : année invalide.\n");
        printf("Rentrer l'année de l'épreuve sous forme d'entier : ");
        scanf("%d", &a);
    }

    FILE *Main = fopen("main.txt", "r+");
    if (Main == NULL) {
        printf("Erreur : fichier principal non présent.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(Main, "%32s", nom) == 1) {
        strcpy(nomfichier, nom);
        strcat(nomfichier, ".txt");

        FILE *Athlete = fopen(nomfichier, "r+");
        if (Athlete == NULL) {
            printf("Erreur : l'athlete %s n'est pas dans notre base de donnée.\n", nom);
            continue;
        }

        while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j2, &m2, &a2, &epreuve, &temps, &place) == 6) {
            if (j2 == j && m2 == m && a2 == a) {
                printf("%s %d/%d/%d ", nom, j, m, a);
                switch (epreuve) {
                    case 1: printf("100m "); break;
                    case 2: printf("400m "); break;
                    case 3: printf("5000m "); break;
                    case 4: printf("marathon "); break;
                    case 5: printf("relais 4*400m "); break;
                    default: printf("epreuve inconnue "); break;
                }
                printf("%d sec", temps);
                if (place != 0) {
                    printf(" %d place", place);
                }
                printf("\n");
            }
        }

        fclose(Athlete);
    }

    fclose(Main);
}

void RechercherEpreuve() {
    int j, m, a, epreuve, epreuve2, temps, place;
    char nom[33];
    char nomfichier[37];

    printf("\n Recherche epreuve : \n");

    printf("Type d'épreuve : entrer 1 pour 100m, 2 pour 400m, 3 pour 5000m, 4 pour marathon, 5 pour relais 4*400m : ");
    scanf("%d", &epreuve);
    while (epreuve < 1 || epreuve > 5) {
        printf("Erreur : type d'épreuve invalide.\n");
        printf("Type d'épreuve : entrer 1 pour 100m, 2 pour 400m, 3 pour 5000m, 4 pour marathon, 5 pour relais 4*400m : ");
        scanf("%d", &epreuve);
    }

    FILE *Main = fopen("main.txt", "r+");
    if (Main == NULL) {
        printf("Erreur : fichier principal non présent.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(Main, "%32s", nom) == 1) {
        strcpy(nomfichier, nom);
        strcat(nomfichier, ".txt");

        FILE *Athlete = fopen(nomfichier, "r+");
        if (Athlete == NULL) {
            printf("Erreur : l'athlete %s n'est pas dans notre base de donnée.\n", nom);
            continue;
        }

        while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve2, &temps, &place) == 6) {
            if (epreuve == epreuve2) {
                printf("%s %d/%d/%d ", nom, j, m, a);
                switch (epreuve2) {
                    case 1: printf("100m "); break;
                    case 2: printf("400m "); break;
                    case 3: printf("5000m "); break;
                    case 4: printf("marathon "); break;
                    case 5: printf("relais 4*400m "); break;
                    default: printf("epreuve inconnue "); break;
                }
                printf("%d sec", temps);
                if (place != 0) {
                    printf(" %d place", place);
                }
                printf("\n");
            }
        }

        fclose(Athlete);
    }

    fclose(Main);
}
