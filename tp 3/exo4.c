#include <stdio.h>

void verifier_valeur() {
    int T[100];
    
    printf("Entrer les elements de tableau\n")
    for (int i = 0; i < 100; i++) {
        printf("T[%d]=",i);
        scanf("%d", T[i]);
    }

    int valeur;
    printf("Entrez une valeur à rechercher dans le tableau : ");
    scanf("%d", &valeur);

    for (int i = 0; i < 100; i++) {
        if (T[i] == valeur) {
            printf("La valeur %d a été trouvée à l'indice %d.\n", valeur, i);
            return;
        }
    }

    printf("La valeur %d n'a pas été trouvée dans le tableau.\n", valeur);
}

int main() {
    verifier_valeur();
    return 0;
}
