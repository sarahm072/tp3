#include <stdio.h>
#include <string.h>

void mot_le_plus_long() {
    char phrase[1000], mot_long[100];
    int len_max = 0;

    printf("Entrez une phrase : ");
    fgets(phrase, sizeof(phrase), stdin);

    // Supprime le '\n' si présent
    phrase[strcspn(phrase, "\n")] = 0;

    char *mot = strtok(phrase, " ");
    
    while (mot != NULL) {
        int len = strlen(mot);
        if (len > len_max) {
            len_max = len;
            strcpy(mot_long, mot);
        }
        mot = strtok(NULL, " ");
    }

    printf("Le mot le plus long est : %s\n", mot_long);
}

int main() {
    mot_le_plus_long();
    return 0;
}
