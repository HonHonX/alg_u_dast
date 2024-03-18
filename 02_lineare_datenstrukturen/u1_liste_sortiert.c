#include <stdio.h>
#include <stdlib.h>

// Es wird eine einfache Listenstruktur mit einer Ganzzahl als Datum gewaehlt
struct Listenelement{
	int zahlenwert;
	struct Listenelement* naechstes_Element;	// Zeiger aufs naechste Element der Liste
};


// Globale Variablen

// Es muss ein Zeiger definiert werden, welcher auf den Beginn der Liste zeigt
struct Listenelement* start = NULL;	// Zuerst ist die Liste leer


// Definition der Funktionen

void sortiertesEinfuegenElement(struct Listenelement* neu){
	// Funktion fuegt ein neues Element sortiert ein
	
	struct Listenelement *hilfsZeiger1, *hilfsZeiger2;
	int eingefuegt = 0;	// Hilfsvariable um zu sehen, ob ein Element eingefuegt worden ist
	
	// Falls die Liste leer ist, wird das Element vom Startzeiger adressiert
	if(start == NULL){
		start = neu;	
		neu->naechstes_Element = NULL;
	}
	// Die Liste ist nicht leer; Fuege das neue Element ein
	// Der Zahlenwert ist kleiner als alles in der Liste => Als erstes Element einfuegen
	else if(neu->zahlenwert <= start->zahlenwert){
				hilfsZeiger1 = start;	// Festhalten der Adresse
				start = neu;	// Speicher wird freigegeben
				neu->naechstes_Element = hilfsZeiger1;	// Neusetzen des Startzeigers
	}
	else{
		hilfsZeiger1 = start;
		while( hilfsZeiger1->naechstes_Element != NULL){
			// Festhalten der Adresse
			hilfsZeiger2 = hilfsZeiger1->naechstes_Element;
			// Zahlenwert des Elements ist kleiner oder gleich => Hinzufuegen
			if (neu->zahlenwert <= hilfsZeiger2->zahlenwert){
				// Neureferenzierung des Nachfolgers
				hilfsZeiger1->naechstes_Element = neu;
				neu->naechstes_Element = hilfsZeiger2;
				eingefuegt = 1;	// Element wurde eingefuegt
				break;	// Abbruch der Schleife
			}
			hilfsZeiger1 = hilfsZeiger2;	// Naechstes Element fuer die Schleife
		}	
		
		// Element wurde noch nicht eingefuegt
		if(eingefuegt == 0){
			// Das bisher letzte Element soll aufs neue Element zeigen
			hilfsZeiger1->naechstes_Element = neu;	 
			// Letztes Element zeigt auf kein Element
			neu->naechstes_Element = NULL;
		}
	}
}


void erstelleElement(){
	// Funktion erstellt das Listenelement, welches hinzugefuegt werden soll
	struct Listenelement* neuesElement = malloc(sizeof(struct Listenelement));
	if(neuesElement==NULL){
		printf("Es konnte kein neues Element hinzugefuegt werden.\n");
		return;
	}
	printf("Bitte geben Sie den Zahlenwert des neuen Elementes ein:\n");
	scanf("%d",&(neuesElement->zahlenwert));
	sortiertesEinfuegenElement(neuesElement);	
}

void loescheElement(int wert){
	// Funktion loescht das Element mit Zahlenwert wert 
	struct Listenelement *hilfsZeiger1, *hilfsZeiger2;	// Ein Zeiger zum Iterieren, einer zum Tauschen
	int gefunden = 0;	// Wenn Element nicht gefunden wurde, wird eine Meldung ausgegeben

	// Wenn die Liste leer ist, kann nichts geloescht werden
	if(start != NULL){
		// Das erste Element hat den gesuchten Zahlenwert => Startzeiger muss geaendert werden
		if(start->zahlenwert == wert){
				hilfsZeiger1 = start->naechstes_Element;	// Festhalten der Adresse
				free(start);	// Speicher wird freigegeben
				start = hilfsZeiger1;	// Neusetzen des Startzeigers
				gefunden = 1;
		}
		// Element befindet sich inmitten der Liste => Durchiterieren
		else{
			hilfsZeiger1 = start;
			while( hilfsZeiger1->naechstes_Element != NULL){
				// Festhalten der Adresse
				hilfsZeiger2 = hilfsZeiger1->naechstes_Element;
				// Element wurde gefunden
				if (hilfsZeiger2->zahlenwert == wert){
					// Neureferenzierung des Nachfolgers
					hilfsZeiger1->naechstes_Element = hilfsZeiger2->naechstes_Element;
					free(hilfsZeiger2);	// Element wird geloescht
					gefunden = 1;
					// break;	// Abbruch der Schleife; lediglich dann, wenn max. ein Element geloescht wird
				}
				if(gefunden!=1)
					hilfsZeiger1 = hilfsZeiger2;	// Naechstes Element fuer die Schleife
				else
					hilfsZeiger1 = hilfsZeiger1->naechstes_Element;
			}
		}
	}
	// Pruefung ob Element gefunden wurde
	if (gefunden == 0)
		printf("Element mit dem Wert %d wurde nicht gefunden!\n",wert);
}

void ausgabeListe(){
	// Es werden alle Elemente der Liste ausgegeben
	struct Listenelement* hilfsZeiger = start;
	int aktuellesElement = 1;	// Hilfszaehler fuer Zeilenumbruch
	while(hilfsZeiger != NULL){
			printf("%d\t",hilfsZeiger->zahlenwert);
			hilfsZeiger = hilfsZeiger->naechstes_Element;
			// Nach jedem fuenften Element wird ein Zeilenumbruch durchgefuehrt
			if(aktuellesElement%5 == 0)	
				printf("\n");
			aktuellesElement++;
	}
	printf("\n");
}

int main(void){
	int auswahl;
	int zuLoeschen;	// Wert des Knoten, welcher geloescht werden soll
	do{
		printf("Bitten waehlen Sie:\n");
		printf("1: Neues Element zur Liste hinzufuegen\n");
		printf("2: Element aus Liste loeschen\n");
		printf("3: Liste auf Konsole ausgeben\n");
		printf("0: Programm beenden\n");
		scanf("%d",&auswahl);
		fflush(stdin);
		switch(auswahl){
			case 1: erstelleElement();
					break;
			case 2: printf("Bitte geben Sie den zu loeschenden Wert ein:\n");
					scanf("%d",&zuLoeschen);
					fflush(stdin);
					loescheElement(zuLoeschen);
					break;
			case 3: ausgabeListe();
					break;
		}
	}while(auswahl != 0);
	return EXIT_SUCCESS;
}