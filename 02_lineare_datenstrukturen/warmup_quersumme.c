#include <stdio.h>
#include <stdlib.h>

int quersumme(int zahl) {
    int quersumme;
    while(zahl) {
        quersumme += zahl % 10;
        zahl /= 10;
    }
    return quersumme;
}

int main(void) {
    int zahl;

    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%d", &zahl);
    printf("Die Quersumme der Zahl %d lautet: %d\n", zahl, quersumme(zahl));
    fflush(stdin);

    return EXIT_SUCCESS;
}
