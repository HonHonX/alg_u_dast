#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n) {
    if (n<2)
        return n;
    return Fibonacci(n-1)+Fibonacci(n-2);
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
	printf("Die %d. Fibonacci Zahl lautet : %d",zahl, Fibonacci(zahl));
    printf("\n");
	return EXIT_SUCCESS;
}