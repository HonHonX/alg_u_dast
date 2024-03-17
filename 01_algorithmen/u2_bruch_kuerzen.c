#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int zaehler;
    int nenner;
} Bruch;

int ggT(int x, int y) {
    int temp;

    while (x>0) {
        if (x<y) {
            temp = x;
            x = y;
            y = temp;
        }
        x -= y;
    }
    return y;
}

void kuerzen(Bruch *bruch) {
    int x = ggT(bruch->zaehler, bruch->nenner);
    bruch->zaehler /= x;
    bruch->nenner /= x;
}

void bruchEinlesen(Bruch *bruch) {
    printf("Bitte Zaehler eingeben:");
    scanf("%d", &(bruch->zaehler));
    printf("Bitte Nenner eingeben:");
    scanf("%d", &(bruch->nenner));
    fflush(stdin);
}

int main(void) {
    Bruch bruch;

    bruchEinlesen(&bruch);
    printf("Der eingelesene Bruch lautet: %d / %d\n", bruch.zaehler, bruch.nenner);

    kuerzen(&bruch);
    printf("Der eingelesene Bruch gekuerzt: %d / %d\n", bruch.zaehler, bruch.nenner);

    return EXIT_SUCCESS;
}
