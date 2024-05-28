#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int temps;
  char nom[33]; 
} athlete;

void ResumePerf(){
  int max=0;
  int min=0;
  int moy=0;
  int k=0;
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int epreuve2; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps; //temps en secondes
  char nom[33];
  char nomfichier[37];
  printf("\n Resumé performance : \n");
  printf("Choisir une epreuve : \n");
  printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
  scanf("%d", &epreuve);
  printf("\n");
  while(epreuve<1 || epreuve>5){
    printf("erreur\n");
    printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
    scanf("%d", &epreuve);
    printf("\n");
  }
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
  while (fscanf(Athlete, "%*d;%*d;%*d;%d;%d;%*d", &epreuve2, &temps)==2){
     if(epreuve==epreuve2){
        if(k==0){
            max=temps;
            min=temps;
            moy=temps;
        }
        else{
            if(temps<min){
              min=temps;
            }
            if(temps>max){
              max=temps;
            }
            moy=moy+temps;
        }
        k=k+1;
     }
  }
  fclose(Athlete);
  moy=moy/k;
  printf("%s : \n", nom);
  printf("Meilleur temps : %d secondes\n", min);
  printf("Pire temps : %d secondes\n", max);
  printf("Moyenne temps : %d secondes\n", moy);
}

void JO(){
  int moy=0;
  int k=0;
  int n=0;
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int epreuve2; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps; //temps en secondes
  char nom[33];
  char nomfichier[37];
  athlete *pathlete=NULL;
  printf("\n JO : \n");
  printf("Choisir une epreuve : \n");
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
  while (fscanf(Main, "%32s", nom)==1){
      n=n+1;
  }
  rewind(Main);
  pathlete=malloc(n*sizeof(athlete));
  n=0;
  while (fscanf(Main, "%32s", nom)==1){//Boucle pour parcourir le fichier et afficher les données
      strcpy(nomfichier, nom);
      strcat(nomfichier, ".txt");
      FILE *Athlete=fopen( nomfichier, "r+"); 
      if (Athlete == NULL){                    
          printf("erreur : l'athlete n'est pas dans notre base de donnée\n");
          exit(0);
      }
      while (fscanf(Athlete, "%*d;%*d;%*d;%d;%d;%*d", &epreuve2, &temps)==2){
        if(epreuve==epreuve2){
          if(k==0){
            moy=temps;
          }
          else{
            moy=moy+temps;
          }
        k=k+1;
        }
      }
      fclose(Athlete);
      moy=moy/k;
      (*(pathlete+n)).temps=moy;
      strcpy((*(pathlete+n)).nom, nom);
      printf(" %s : %d secondes\n", (*(pathlete+n)).nom, (*(pathlete+n)).temps );
      n=n+1;
      k=0;
  }
  fclose(Main);
  
}

void Progression(){
  int j;
  int m;
  int a;
  int j1=0;
  int m1=0;
  int a1=0;
  int j2=0;
  int m2=0;
  int a2=0;
  int epreuve; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int epreuve2; //type d'epreuve =1 si 100m, =2 si 400m, =3 si 5000m, =4 si marathon, =5 si relais 4*400m
  int temps;//temps en secondes
  int temps1=0;
  int temps2=0;
  int place;
  char nom[33];
  char nomfichier[37];
  printf("\n Progression : \n");
  printf("Choisir une epreuve : \n");
  printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
  scanf("%d", &epreuve);
  printf("\n");
  while(epreuve<1 || epreuve>5){
    printf("erreur\n");
    printf("type d'epreuve rentrer 1 si 100m, rentrer 2 si 400m, rentrer 3 si 5000m, rentrer 4 si marathon, rentrer 5 si relais 4*400m : ");
    scanf("%d", &epreuve);
    printf("\n");
  }
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
  while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve2, &temps, &place)==6){
     if(epreuve==epreuve2){
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
  rewind(Athlete);
  printf("Rentrer 2 dates pour comparer les temps : \n");
  printf("Rentrer la première date dans l'ordre chronologique : \n");
  printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j1);
  printf("\n");
  while(j1<1 || j1>30){
    printf("erreur\n");
    printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j1);
    printf("\n");
  }
  printf("rentrer le mois de l'épreuve sous forme d'entier : ");
  scanf("%d", &m1);
  printf("\n");
  while(m1<1 || m1>12){
    printf("erreur\n");
    printf("rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m1);
    printf("\n");
  }
  printf("rentrer l'année de l'épreuve sous forme d'entier : ");
  scanf("%d", &a1);
  printf("\n");
  while(a1<1 || a1>9999){
    printf("erreur\n");
    printf("rentrer l'année de l'épreuve sous forme d'entier : ");
    scanf("%d", &a1);
    printf("\n");
  }
  printf("Rentrer la deuxieme date dans l'ordre chronologique : \n");
  printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j2);
  printf("\n");
  while(j2<1 || j2>30){
    printf("erreur\n");
    printf("rentrer le jour de l'épreuve sous forme d'entier : ");
  scanf("%d", &j2);
    printf("\n");
  }
  printf("rentrer le mois de l'épreuve sous forme d'entier : ");
  scanf("%d", &m2);
  printf("\n");
  while(m2<1 || m2>12){
    printf("erreur\n");
    printf("rentrer le mois de l'épreuve sous forme d'entier : ");
    scanf("%d", &m2);
    printf("\n");
  }
  printf("rentrer l'année de l'épreuve sous forme d'entier : ");
  scanf("%d", &a2);
  printf("\n");
  while(a2<1 || a2>9999){
    printf("erreur\n");
    printf("rentrer l'année de l'épreuve sous forme d'entier : ");
    scanf("%d", &a2);
    printf("\n");
  }
  while (fscanf(Athlete, "%d;%d;%d;%d;%d;%d", &j, &m, &a, &epreuve2, &temps, &place)==6){
     if(epreuve==epreuve2){
        if(j==j1 && m==m1 && a==a1){
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
          temps1=temps;
        }
        else{
        if(j==j2 && m==m2 && a==a2){
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
          temps2=temps;
        }
        }
     }
  }
  fclose(Athlete);
  if(temps1==0 || temps2==0){
    printf("erreur : dates non présentes dans le fichier");
  }
  else{
    if(temps2<temps1){
      printf("l'athlete s'est améliorer mashallah\n");
    }
    if(temps1<temps2){
      printf("l'athlete a regresser guez\n");
    }
    if(temps1==temps2){
      printf("l'athlete n'a pas évoluer grandis un peu\n");
    }
  }
}
