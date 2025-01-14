#include <stdio.h>

void somme_tableau(){
  int N, somme=0;
  do{
  printf("Entrez la taille du tableau (max 50) : ");
    scanf("%d", &N);
  } while (N<0 || N>50);
  int Tableau[N];
//saisir les elements de tableau
  for (int i = 0; i < N; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    //calculer la somme
  for (int i = 0; i < N; i++) {
    somme += tableau[i];
  }
    printf("Somme des éléments du tableau : %d\n", somme);
}

int main() {
    somme_tableau();
    return 0;
}
