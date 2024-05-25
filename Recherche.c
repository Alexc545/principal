#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Fonction d'affichage de fichier Athlete
void afficherFichierAtlhlete(FILE* Athlete){
    int j;  //valeur pour le jour
    int m;  //valeur pour le mois
    int a;  //valeur pour l'année
    int epreuve;  //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
    int temps; //temps en secondes
    int place; //place dans le relais =0 si pas prise en compte
    printf("\n Affichage dossier athlete : \n");
    while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve, &temps, &place)==6){//Boucle pour parcourir le fichier et afficher les données
        printf(" %d/", j);
        printf("%d/", m);
        printf("%d ", a);
        if(epreuve==1){
          printf("100m ");
        }
        if(epreuve==2){
          printf("400m ");
        }
        if(epreuve==3){
          printf("5000m ");
        }
        if(epreuve==4){
          printf("marathon ");
        }
        if(epreuve==5){
          printf("relais 4*400m ");
        }
        if(place==0){
          printf(" %d sec\n", temps);
        }
        else{
          printf(" %d sec", temps);
          printf(" %d place\n", place);
        }
    }
    rewind(Athlete); //Remonter au début du fichier
}

//Fonction pour ajouter un entrainement
void ajoutFichierAtlhlete(FILE* Athlete) {
  int j;  //valeur pour le jour
  int m;  //valeur pour le mois
  int a;  //valeur pour l'année 
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps; //temps en secondes
  int place; //place dans le relais =0 si pas prise en compte
  printf("\n Ajout athlete : \n");
  printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j);
  printf("\n");
  while(j<1 || j>30){
    printf("erreur\n");
    printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j);
    printf("\n");
  }
  printf("rentrer le mois de l'épreuve sous forme d'entier : ");
  scanf("%d", &m);
  printf("\n");
  while(m<1 || m>12){
    printf("erreur\n");
    printf("rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m);
    printf("\n");
  }
  printf("rentrer l'année de l'épreuve sous forme d'entier : ");
  scanf("%d", &a);
  printf("\n");
  while(a<1 || a>9999){
    printf("erreur\n");
    printf("rentrer l'année de l'épreuve sous forme d'entier : ");
  scanf("%d", &a);
    printf("\n");
  }
  printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
  scanf("%d", &epreuve);
  printf("\n");
  while(epreuve<1 || epreuve>5){
    printf("erreur\n");
    printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
    scanf("%d", &epreuve);
    printf("\n");
  }
  printf("rentrer le temps sous la forme d'un entiers en secondes : ");
  scanf("%d", &temps);
  if(epreuve==5){
    printf("rentrer la place dans le relais sous la forme d'un entiers : ");
    scanf("%d", &place); 
    printf("\n");
    while(place<1 || place>4){
    printf("erreur\n");
    printf("rentrer la place dans le relais sous la forme d'un entiers : ");
    scanf("%d", &place); 
    printf("\n");
  }
  }
  fseek(Athlete, 0, SEEK_END);//aller à la fin du fichier
  fprintf(Athlete, "%d;", j);
  fprintf(Athlete, "%d;", m);
  fprintf(Athlete, "%d;", a);
  fprintf(Athlete, "%d;", epreuve);
  fprintf(Athlete, "%d;", temps);
  if(epreuve==5){
    fprintf(Athlete, "%d\n", place);
  }
  else{
    fprintf(Athlete, "0\n");
  }
  rewind(Athlete); //Remonter au début du fichier
}

void RechercherAthlete(){
  int a=-1;
  char nom[33]; 
  char nomfichier[37];
  printf("\n Recherche athlete : \n");
  printf("Rentrer le nom de l'athlete que vous cherchez : ");
  scanf("%32s", nom);
  printf("\n");
  strcpy(nomfichier, nom);
  strcat(nomfichier, ".txt");
  FILE *Athlete=fopen( nomfichier, "r+"); 
  if (Athlete == NULL){                    
    printf("erreur : l'athlete n'est pas dans notre base de donnée\n");
    exit(0);
  }
  printf("Pour afficher le fichier de l'athlete par rapport à son nom taper 1 : \n Pour ajouter un entrainement dans son fichier taper 2 : \n");
  scanf("%d", &a);
  printf("\n");
  while(a<0 || a>2){
    printf("erreur\n");
    printf("Pour afficher le fichier de l'athlete par rapport à son nom taper 1 : \n Pour ajouter  un entrainement dans son fichier taper 2 : \n");
    scanf("%d", &a);
    printf("\n");
  }
  if(a==1){
    afficherFichierAtlhlete(Athlete);
  }
  else{
    if(a==2){
      ajoutFichierAtlhlete(Athlete);
    }
  }
  fclose(Athlete);
}

void RechercherDate(){
  int j;  //valeur pour le jour
  int m;  //valeur pour le mois
  int a;  //valeur pour l'année
  int j2;  //valeur pour le jour
  int m2;  //valeur pour le mois
  int a2;  //valeur pour l'année
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps; //temps en secondes
  int place; //place dans le relais =0 si pas prise en compte
  char nom[33];
  char nomfichier[37];
  printf("\n Recherche date : \n");
  printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j);
  printf("\n");
  while(j<1 || j>30){
    printf("erreur\n");
    printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j);
    printf("\n");
  }
  printf("rentrer le mois de l'épreuve sous forme d'entier : ");
  scanf("%d", &m);
  printf("\n");
  while(m<1 || m>12){
    printf("erreur\n");
    printf("rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m);
    printf("\n");
  }
  printf("rentrer l'année de l'épreuve sous forme d'entier : ");
  scanf("%d", &a);
  printf("\n");
  while(a<1 || a>9999){
    printf("erreur\n");
    printf("rentrer l'année de l'épreuve sous forme d'entier : ");
    scanf("%d", &a);
    printf("\n");
  }
  FILE *Main=fopen( "main.txt", "r+"); 
  if (Main == NULL) {                    
      printf("erreur : fichier principal non présent\n");
      exit(0);
  }
  while (fscanf(Main, "%32s", nom)==1){//Boucle pour parcourir le fichier et afficher les données
      strcpy(nomfichier, nom);
      strcat(nomfichier, ".txt");
      FILE *Athlete=fopen( nomfichier, "r+"); 
      if (Athlete == NULL){                    
          printf("erreur : l'athlete n'est pas dans notre base de donnée\n");
          exit(0);
      }
      while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j2, &m2, &a2, &epreuve, &temps, &place)==6){
            if(j2==j && m==m2 && a==a2){
                printf(" %s", nom);
                printf(" %d/", j);
                printf("%d/", m);
                printf("%d ", a);
                if(epreuve==1){
                  printf("100m ");
                }
                if(epreuve==2){
                  printf("400m ");
                }
                if(epreuve==3){
                  printf("5000m ");
                }
                if(epreuve==4){
                  printf("marathon ");
                }
                if(epreuve==5){
                  printf("relais 4*400m ");
                }
                if(place==0){
                  printf(" %d sec\n", temps);
                }
                else{
                  printf(" %d sec", temps);
                  printf(" %d place\n", place);
                }
            }
      }
      fclose(Athlete);
  }
  fclose(Main);
}

void RechercherEpreuve(){
  int j;  //valeur pour le jour
  int m;  //valeur pour le mois
  int a;  //valeur pour l'année
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int epreuve2; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps; //temps en secondes
  int place; //place dans le relais =0 si pas prise en compte
  char nom[33];
  char nomfichier[37];
  printf("\n Recherche epreuve : \n");
  printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
  scanf("%d", &epreuve);
  printf("\n");
  while(epreuve<1 || epreuve>5){
    printf("erreur\n");
    printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
    scanf("%d", &epreuve);
    printf("\n");
  }
  FILE *Main=fopen( "main.txt", "r+"); 
  if (Main == NULL) {                    
      printf("erreur : fichier principal non présent\n");
      exit(0);
  }
  while (fscanf(Main, "%32s", nom)==1){//Boucle pour parcourir le fichier et afficher les données
      strcpy(nomfichier, nom);
      strcat(nomfichier, ".txt");
      FILE *Athlete=fopen( nomfichier, "r+"); 
      if (Athlete == NULL){                    
          printf("erreur : l'athlete n'est pas dans notre base de donnée\n");
          exit(0);
      }
      while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve2, &temps, &place)==6){
            if(epreuve==epreuve2){
                printf(" %s", nom);
                printf(" %d/", j);
                printf("%d/", m);
                printf("%d ", a);
                if(epreuve==1){
                  printf("100m ");
                }
                if(epreuve==2){
                  printf("400m ");
                }
                if(epreuve==3){
                  printf("5000m ");
                }
                if(epreuve==4){
                  printf("marathon ");
                }
                if(epreuve==5){
                  printf("relais 4*400m ");
                }
                if(place==0){
                  printf(" %d sec\n", temps);
                }
                else{
                  printf(" %d sec", temps);
                  printf(" %d place\n", place);
                }
            }
      }
      fclose(Athlete);
  }
  fclose(Main);
}
