

#include <stdio.h>

void division_par_soustraction() {
    int dividende, diviseur, quotient = 0, reste;
    
    printf("Entrez le dividende : ");
    scanf("%d", &dividende);
    printf("Entrez le diviseur : ");
    scanf("%d", &diviseur);

    if (diviseur == 0) {
        printf("Erreur : Division par zéro non autorisée.\n");
        return;
    }

    reste = dividende;

    while (reste >= diviseur) {
        reste -= diviseur;
        quotient++;
    }

    printf("Quotient : %d\n", quotient);
    printf("Reste : %d\n", reste);
}

int main() {
    division_par_soustraction();
    return 0;
}
