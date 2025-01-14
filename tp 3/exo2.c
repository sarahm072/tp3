#include <stdio.h>

void somme_produit_moyenne() {
    int chiffre, somme = 0, produit = 1, count = 0;
    
    while (1) {
        printf("Entrez un chiffre (0-9) \"0 pour terminer\") : ");
        scanf("%d", &chiffre);

        if (chiffre < 0 || chiffre > 9) {
            printf("Erreur : Veuillez entrer un chiffre valide (0-9).\n");
            continue;
        }

        if (chiffre == 0) {
            break;
        }

        somme =somme + chiffre;
        produit =produit * chiffre;
        count++;
    }

    if (count > 0) {
        float moyenne = somme / count;
        printf("Somme : %d\n", somme);
        printf("Produit : %d\n", produit);
        printf("Moyenne : %f\n", moyenne);
    } else {
        printf("Aucun chiffre n'a été entré.\n");
    }
}

int main() {
    somme_produit_moyenne();
    return 0;
}
