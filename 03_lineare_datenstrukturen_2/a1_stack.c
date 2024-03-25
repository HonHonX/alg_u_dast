#include <stdio.h>
#include <stdlib.h>

struct stackelement {
    int wert;
    struct stackelement* next;
};


//Startzeiger initialisieren
struct stackelement* start = NULL;

//Fügt dem Stack ein Element nach dem LIFO Prinzip hinzu
void push(int zahlenwert) {
    struct stackelement* neu = malloc(sizeof(struct stackelement));
    
    if (neu == NULL) {
        printf("Speicherzuweisung fehlgeschlagen. Beenden des Programms.\n");
        exit(EXIT_FAILURE);
    }

    struct stackelement* temp = start;
    start= neu;
    neu->wert = zahlenwert;
    neu->next = temp;
}

//Löscht nach dem LIFO Prinzip ein Element aus dem Stack
int pop() {
    if (start != NULL) {
        int zahl = start->wert;
        struct stackelement* naechstesElement = start->next;
        free(start);
        start = naechstesElement;
        return zahl;
    } 
    else {
        printf("Der Stack ist leer! Es konnte nichts gelöscht werden.\n");
        return 0;
    }
} 

//Gibt die Inhalte des Stacks auf der Konsole aus
void ausgabeStack() {
    if (start == NULL) {
        printf("Der Stack ist leer!\n");
        return;
    }
    struct stackelement* aktuell = start;
    int position = 1;
    while (aktuell != NULL) {
        printf("%d. Element: %d\n", position++, aktuell->wert);
        aktuell = aktuell->next;
    }
}

//Gibt den benutzten Speicher wieder frei 
void stackFreigeben() {
    struct stackelement* aktuell = start;
    struct stackelement* temp;

    //Der Stack wird nach und nach durchgegangen
    while (aktuell != NULL) {
        temp = aktuell->next;
        free(aktuell);
        aktuell = temp;
    }45
}

int main(void) {
    int auswahl, wert;

    // Auswahl der Aktionen durch den Benutzer
    do {
        printf("\n");
        printf("******************************************\n");
        printf("* Bitte waehlen Sie:                     *\n");
        printf("* 1: Neues Element zum Stack hinzufuegen *\n");
        printf("* 2: Element aus Stack loeschen          *\n");
        printf("* 3: Stack auf Konsole ausgeben          *\n");
        printf("* 0: Programm beenden                    *\n");
        printf("\n");
        scanf("%d", &auswahl);
        fflush(stdin);

        switch (auswahl) {
            case 1:
                printf("Bitte geben Sie den Zahlenwert des neuen Elements ein: ");
                scanf("%d", &wert);
                push(wert);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Ausgabe des Stacks. Das 1.Element ist das obenliegenden Element:\n");
                ausgabeStack();
                break;
            case 0:
                printf("Programm wird beendet.\n");
                break;
            default:
                printf("Ungueltige Eingabe! Bitte geben Sie eine der verfuegbaren Optionen ein.\n");
        }
    } while (auswahl != 0);

    // Speicher freigeben
    stackFreigeben();

    return EXIT_SUCCESS;
}