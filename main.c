#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Performance.h"
#include "Recherche.h"

// Fonction d'affichage de fichier principal
void afficherFichierMain(FILE* Main) {
    char nom[33];
    while (fscanf(Main, "%32s", nom) == 1) { // Boucle pour parcourir le fichier et afficher les données
        printf("%32s\n", nom);
    }
    rewind(Main); // Remonter au début du fichier
}

int main(void) {
    int choixMenu = -1;
    int continuer = 0;

    while (continuer == 0) {
        printf("Souhaitez-vous afficher le fichier principal avec le nom de tous les athlètes ? (0 pour non, 1 pour oui) : ");
        scanf("%d", &choixMenu);
        printf("\n");

        while (choixMenu < 0 || choixMenu > 1) {
            printf("Erreur de saisie.\n");
            printf("Souhaitez-vous afficher le fichier principal avec le nom de tous les athlètes ? (0 pour non, 1 pour oui) : ");
            scanf("%d", &choixMenu);
            printf("\n");
        }

        if (choixMenu == 1) {
            FILE *Main = fopen("main.txt", "r+");
            if (Main == NULL) {
                printf("Erreur : fichier principal non présent\n");
                exit(EXIT_FAILURE);
            }
            afficherFichierMain(Main);
            fclose(Main);
        }

        choixMenu = -1;
        printf("Menu principal :\n");
        printf("1 - Consulter le fichier d'un athlète par rapport à son nom\n");
        printf("2 - Rechercher un entraînement selon sa date\n");
        printf("3 - Rechercher un entraînement selon son épreuve\n");
        printf("4 - Afficher les performances d'un athlète selon une épreuve\n");
        printf("5 - Sélectionner les athlètes pour les JO\n");
        printf("6 - Voir l'évolution d'un athlète entre 2 dates\n");
        printf("Choix : ");
        scanf("%d", &choixMenu);
        printf("\n");

        while (choixMenu < 1 || choixMenu > 6) {
            printf("Erreur de saisie.\n");
            printf("Menu principal :\n");
            printf("1 - Consulter le fichier d'un athlète par rapport à son nom\n");
            printf("2 - Rechercher un entraînement selon sa date\n");
            printf("3 - Rechercher un entraînement selon son épreuve\n");
            printf("4 - Afficher les performances d'un athlète selon une épreuve\n");
            printf("5 - Sélectionner les athlètes pour les JO\n");
            printf("6 - Voir l'évolution d'un athlète entre 2 dates\n");
            printf("Choix : ");
            scanf("%d", &choixMenu);
            printf("\n");
        }

        switch (choixMenu) {
            case 1:
                RechercherAthlete();
                break;
            case 2:
                RechercherDate();
                break;
            case 3:
                RechercherEpreuve();
                break;
            case 4:
                ResumePerf();
                break;
            case 5:
                JO();
                break;
            case 6:
                Progression();
                break;
            default:
                printf("Erreur : choix non reconnu.\n");
                break;
        }

        choixMenu = -1;
        printf("Pour continuer à naviguer taper 0, pour quitter taper 1 : ");
        scanf("%d", &continuer);
        printf("\n");

        while (continuer < 0 || continuer > 1) {
            printf("Erreur de saisie.\n");
            printf("Pour continuer à naviguer taper 0, pour quitter taper 1 : ");
            scanf("%d", &continuer);
            printf("\n");
        }
    }

    return 0;
}


