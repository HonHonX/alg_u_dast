#include <stdio.h>
#include <stdlib.h>

void zahlenfolgeAusgeben(int* zahlenfolge, int laenge) {
    for(int i=0; i<laenge; i++) {
        printf("%d.: %d\n", i+1, zahlenfolge[i]);
    }
}

int zahlEinfuegen (int* zahlenfolge, int laenge, int index, int zahlenwert) {
    //Pruefung, ob Index zulässig
    if (index > laenge || index < 0) {
        printf("Fehler: Index nicht zulässig.");
        return 0;
    }

    // Pruefung, ob Speicherplatz erweitert werden konnte
	if(zahlenfolge==NULL){
		printf("Speicherplatz konnte nicht erweitert werden.\n");
		return 0;
	}

    //Erweiterung des Speicherplatzes
    zahlenfolge = realloc(zahlenfolge, (laenge+1) * sizeof(int));

    //Verschiebung der Werte um eine Position
    for (int i=laenge; i>index; i--) {
        zahlenfolge[i] = zahlenfolge[i-1];
    }

    //Zahlenwert einfuegen
    zahlenfolge[index] = zahlenwert;

    return 1;
}

int indexSuchen(int* zahlenfolge, int laenge, int wert) {
    for(int i=0; i<laenge; i++) {
        if(zahlenfolge[i] == wert) {
            return i;
        }
    }
    return -1;
}

int loescheWert(int* zahlenfolge, int laenge, int wert){
	int index = indexSuchen(zahlenfolge, laenge, wert);
	if(index>-1){
		for(int i=index+1; i<laenge; i++)
			zahlenfolge[i-1]=zahlenfolge[i];

        //Speicherplatzbedarf verringern
		zahlenfolge = realloc(zahlenfolge, (laenge-1)*sizeof(int));
		return 1;
	}
	return 0;
}

int main(void) {
    //Variablendeklaration
    int* zahlenfolge;
    int laenge, auswahl, index, wert;

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

    //Auswahl des gewünschten Modus
    do{
        printf("\n*********************\n");
		printf("Was wollen Sie machen?\n");
		printf("1) Element hinzufuegen\n");
		printf("2) Element loeschen\n");
		printf("3) Element suchen\n");
		printf("4) Liste ausgeben\n");
		printf("0) Programm beenden\n");
		scanf("%d",&auswahl);
		fflush(stdin);
		switch(auswahl){
			case 1: printf("Bitte geben Sie den Zahlenwert ein, den Sie hinzufuegen wollen:");
					scanf("%d", &wert);
					fflush(stdin);
					printf("Bitte geben Sie den Index ein, an welchem Sie das Element einfuegen wollen:");
					scanf("%d", &index);
					fflush(stdin);
					if(zahlEinfuegen(zahlenfolge, laenge, index, wert)){
						printf("%d konnte erfolgreich an Index %d eingefuegt werden.\n",wert,index);
						laenge++;
					}
					else
						printf("%d konnte nicht an Index %d eingefuegt werden.\n",wert,index);
					break;
			case 2: printf("Bitte geben Sie den Zahlenwert ein, den Sie loeschen wollen:");
					scanf("%d", &wert);
					fflush(stdin);
					if(loescheWert(zahlenfolge, laenge, wert)){
						printf("%d konnte aus der Liste geloescht werden\n",wert);
						laenge--;
					}
					else
						printf("%d nicht in Liste vorhanden\n",wert);
					break;
			case 3: printf("Bitte geben Sie den Zahlenwert ein, den Sie suchen wollen:");
					scanf("%d", &wert);
					fflush(stdin);
                    index = indexSuchen(zahlenfolge, laenge, wert);
					if(index==-1)
						printf("%d nicht in Liste vorhanden\n",wert);
					else
						printf("%d befindet sich an Index %d\n",wert,index);
					break;
			case 4: zahlenfolgeAusgeben(zahlenfolge, laenge);
					break;
			case 0:	printf("Programm wird abgebrochen\n");
					break;
			default: printf("Fehlerhafte Eingabe. Bitte wiederholen.\n");
		}
	}while(auswahl!=0);

    // Freigabe des Speichers
	free(zahlenfolge);
	zahlenfolge=NULL;

	return EXIT_SUCCESS;
}