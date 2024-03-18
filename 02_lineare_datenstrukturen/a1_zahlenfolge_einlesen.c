#include <stdio.h>
#include <stdlib.h>

void zahlenfolgeAusgeben(int* zahlenfolge, int laenge) {
    for(int i=0; i<laenge; i++) {
        printf("%d.: %d\n", i+1, zahlenfolge[i]);
    }
}

int main(void) {
    //Variablendeklaration
    int* zahlenfolge;
    int laenge;

    //Zahlen einlesen
    printf("Bitte die Länge der Zahlenfolge eingeben: ");
    scanf("%d",&laenge);
    fflush(stdin);

    //Allokierung des Speichers
    zahlenfolge = malloc(laenge * sizeof(int));

    // Ueberpruefung, ob Speicher angelegt werden konnte
	if(zahlenfolge == NULL){
		printf("Speicherplatz konnte nicht angelegt werden\n");
		return EXIT_FAILURE;
	}

    //Eingabe der Zeichenfolge
    printf("Bitte geben Sie nacheinander die Zahlen ein (mit enter getrennt):\n");
    for (int i=0;i<laenge;i++) {
		scanf("%d",&zahlenfolge[i]);
		fflush(stdin);
	}

    //Ausgabe der Zahlenfolge
    zahlenfolgeAusgeben(zahlenfolge,laenge);	

    // Freigabe des Speichers
	free(zahlenfolge);
	zahlenfolge=NULL;

	return EXIT_SUCCESS;
}