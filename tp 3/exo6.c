#include <stdio.h>
#include <ctype.h>

void convertir_en_majuscules() {
    char texte[100];

    printf("Entrez une chaîne de caractères : ");
    fgets(texte, sizeof(texte), stdin);

    // Convertir chaque caractère en majuscule
    for (int i = 0; texte[i] != '\0'; i++) {
        texte[i] = toupper(texte[i]);
    }

    printf("Version en majuscules : %s\n", texte);
}

int main() {
    convertir_en_majuscules();
    return 0;
}
