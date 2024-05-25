#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Performance.h"
#include "Recherche.h"

//Fonction d'affichage de fichier principal
void afficherFichierMain(FILE* Main){
    char nom[33];
    while (fscanf(Main, "%32s", nom)==1){//Boucle pour parcourir le fichier et afficher les données
        printf(" %32s\n", nom);
    }
    rewind(Main); //Remonter au début du fichier
}

int main(void) {
    int a=-1;
    int b=0;
    while(b==0){
      printf("souhaiter vous afficher le fichier principal avec le nom de tout les athletes 0 pour non, 1 pour oui : ");
      scanf("%d", &a);
      printf("\n");
      while(a<0 || a>1){
        printf("erreur\n");
        printf("souhaiter vous afficher le fichier principal avec le nom de tout les athletes 0 pour non, 1 pour oui : ");
        scanf("%d", &a);
        printf("\n");
      }
      if(a==1){
        FILE *Main=fopen( "main.txt", "r+"); 
        if (Main == NULL) {                    
          printf("erreur : fichier principal non présent\n");
          exit(0);
        }
        afficherFichierMain(Main);
        fclose(Main);
      }
      a=-1;
      printf(" Pour consulter le fichier d'un athlete par rapport à son nom taper 1 : \n Pour rechercher un entrainement selon sa date taper 2 : \n Pour rechercher un entrainement selon son épreuve taper 3 : \n Pour afficher les performances d'un athlete selon une épreuve taper 4 : \n Pour sélectionner les athletes pour les JO taper 5 : \n Pour voir l'évolution d'un athlete entre 2 dates taper 6 : \n");
      scanf("%d", &a);
      printf("\n");
      while(a<0 || a>6){
        printf("erreur\n");
        printf(" Pour consulter le fichier d'un athlete par rapport à son nom taper 1 : \n Pour rechercher un entrainement selon sa date taper 2 : \n Pour rechercher un entrainement selon son épreuve taper 3 : \n Pour afficher les performances d'un athlete selon une épreuve taper 4 : \n Pour sélectionner les athletes pour les JO taper 5 : \n Pour voir l'évolution d'un athlete entre 2 dates taper 6 : \n");
        scanf("%d", &a);
        printf("\n");
      }
      if(a==1){
        RechercherAthlete();
      }
      if(a==2){
        RechercherDate();
      }
      if(a==3){
        RechercherEpreuve();
      }
      if(a==4){
        ResuméPerf();
      }
      if(a==5){
        JO();
      }
      if(a==6){
        Progression();
      }
      a=-1;
      printf("Pour continuer à naviguer taper 0, pour quitter taper 1 : ");
      scanf("%d", &b);
      printf("\n");
      while(b<0 || b>1){
        printf("erreur\n");
        printf("Pour continuer à naviguer taper 0, pour quitter taper 1 : ");
        scanf("%d", &b);
        printf("\n");
      }
  }
  return 0;
}