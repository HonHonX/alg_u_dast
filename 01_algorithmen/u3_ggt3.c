#include <stdio.h>
#include <stdlib.h>

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

int ggT3(int x, int y, int z) {
    return ggT(x, ggT(y,z));
}

int main(void) {
    int x,y,z;
    int ggt;

    // Zahlen einlesen
	printf("Bitte erste Zahl eingeben (positive Ganzzahl):");
	scanf("%d",&x);
	fflush(stdin);

	printf("Bitte zweite Zahl eingeben (positive Ganzzahl):");
	scanf("%d",&y);

    printf("Bitte dritte Zahl eingeben (positive Ganzzahl):");
	scanf("%d",&z);

	ggt = ggT3(x, y, z);
	printf("ggT3(%d, %d, %d) = %d\n", x, y, z, ggt);

	return EXIT_SUCCESS;
}