#include <stdio.h>
#include <stdlib.h>

int ggT(int x, int y) {
    int rest;

    while(y) {
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}

int main(void) {
    int x,y;
    int ggt;

    // Zahlen einlesen
	printf("Bitte erste Zahl eingeben (positive Ganzzahl):");
	scanf("%d",&x);
	fflush(stdin);

	printf("Bitte zweite Zahl eingeben (positive Ganzzahl):");
	scanf("%d",&y);

	ggt = ggT(x, y);
	printf("ggT(%d, %d) = %d\n", x, y, ggt);

	return EXIT_SUCCESS;
}