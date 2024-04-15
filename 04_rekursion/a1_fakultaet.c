#include <stdio.h>
#include <stdlib.h>

int Fakul(int n) {
    if (n>1)
        return n*Fakul(n-1);
    return n;
}

int main() {
    int zahl;
	do{
		printf("Bitte geben Sie eine natuerliche Zahl ein:");
		scanf("%d",&zahl);
		fflush(stdin);
		if (!(zahl>0))
			printf("Ungueltige Eingabe. Es muss eine natuerliche Ganzzahl eingegeben werden.\n");
	} while(!(zahl>0));
	printf("%d! = %d",zahl, Fakul(zahl));
    printf("\n");
	return EXIT_SUCCESS;
}