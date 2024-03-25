#include <stdio.h>
#include <stdlib.h>

// Definition der Struktur für Listenelemente
struct Listenelement {
    int zahlenwert;
    struct Listenelement* naechstes_Element;
};

// Globale Variable, um den Start der Liste zu speichern
struct Listenelement* start = NULL;

// Funktion zur Erstellung eines neuen Listenelements
struct Listenelement* erstelleElement(int wert) {
    struct Listenelement* neu = malloc(sizeof(struct Listenelement));
    if (neu == NULL) {
        printf("Speicherzuweisung fehlgeschlagen. Beenden des Programms.\n");
        exit(EXIT_FAILURE);
    }
    neu->zahlenwert = wert;
    neu->naechstes_Element = NULL;
    return neu;
}

// Funktion zum Einfügen eines Listenelements am Ende der Liste
void einfuegenElement(int wert) {
    struct Listenelement* neu = erstelleElement(wert);
    if (start == NULL) {
        start = neu;
    } else {
        struct Listenelement* aktuell = start;
        while (aktuell->naechstes_Element != NULL) {
            aktuell = aktuell->naechstes_Element;
        }
        aktuell->naechstes_Element = neu; //Element am Ende einfügen und den Zeiger für das nächste Element auf NULL setzen
        neu->naechstes_Element = NULL;
    }
}

// Funktion zum Löschen eines Listenelements mit einem bestimmten Wert
void loescheElement(int wert) {
    struct Listenelement* aktuell = start;
    struct Listenelement* vorheriges = NULL;

    while (aktuell != NULL) {
        if (aktuell->zahlenwert == wert) {
            if (vorheriges == NULL) {
                start = aktuell->naechstes_Element;
            } else {
                vorheriges->naechstes_Element = aktuell->naechstes_Element;
            }
            free(aktuell);
            aktuell = NULL;
            return;
        }
        vorheriges = aktuell;
        aktuell = aktuell->naechstes_Element;
    }
    printf("Element mit dem Wert %d wurde nicht gefunden!\n", wert);
}

// Funktion zum Ausgeben der gesamten Liste
void ausgabeListe() {
    if (start == NULL) {
        printf("Die Liste ist leer!\n");
        return;
    }
    struct Listenelement* aktuell = start;
    int position = 1;
    while (aktuell != NULL) {
        printf("%d. Element: %d\n", position++, aktuell->zahlenwert);
        aktuell = aktuell->naechstes_Element;
    }
}

// Funktion zum Freigeben des Speichers für die gesamte Liste
void listeFreigeben() {
    struct Listenelement* aktuell = start;
    struct Listenelement* temp;
    while (aktuell != NULL) {
        temp = aktuell->naechstes_Element;
        free(aktuell);
        aktuell = temp;
    }
}

int main(void) {
    int auswahl, wert;

    // Auswahl der Aktionen durch den Benutzer
    do {
        printf("\nBitte waehlen Sie:\n");
        printf("1: Neues Element zur Liste hinzufuegen\n");
        printf("2: Element aus Liste loeschen\n");
        printf("3: Liste auf Konsole ausgeben\n");
        printf("0: Programm beenden\n\n");
        scanf("%d", &auswahl);

        switch (auswahl) {
            case 1:
                printf("Bitte geben Sie den Zahlenwert des neuen Elements ein: ");
                scanf("%d", &wert);
                einfuegenElement(wert);
                break;
            case 2:
                printf("Bitte geben Sie den zu loeschenden Wert ein: ");
                scanf("%d", &wert);
                loescheElement(wert);
                break;
            case 3:
                ausgabeListe();
                break;
            case 0:
                printf("Programm wird beendet.\n");
                break;
            default:
                printf("Ungueltige Eingabe! Bitte geben Sie eine der verfuegbaren Optionen ein.\n");
        }
    } while (auswahl != 0);

    // Speicher freigeben
    listeFreigeben();

    return 0;
}
