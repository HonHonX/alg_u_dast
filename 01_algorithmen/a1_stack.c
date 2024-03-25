#include <stdio.h>
#include <stdlib.h>

struct stackelement {
    int wert;
    struct stackelement* next;
};


//Startzeiger initialisieren
struct stackelement* start = NULL;

