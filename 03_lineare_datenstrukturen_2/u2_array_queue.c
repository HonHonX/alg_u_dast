#include <stdio.h>
#include <stdlib.h>

#define N 10

// Definiere die Queue und die Indizes zum Einfuegen und Ausgeben
// Automatische Anfangsinitialisierung, da globale Variablen: head = tail = 0
static int queue[N+1], head, tail;

static int put(int v) 
{
    // Einfuegen an aktuellen Index, welcher danach um 1 erhoeht wird
	queue[tail++] = v;
	// Ist der neue Index groesser als die festgelegte Groesse der Queue, wird dieser an den Anfang gesetzt
    if (tail > N) tail = 0;
    return v; 
}

static int get(void)
{ 
    // Auslesen des Elements, welches als erstes eingelesen worden ist
	int t = queue[head++];
	// Ende der Queue erreicht --> Beginne vorne
    if (head > N) head = 0;
    return t;
}

static void queueinit(void)
{ 
    head = 0; 
    tail = 0; 
}
 
static void output()
{
    int i = head; 
    for ( i = head; i < tail; i++ ) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    queueinit();
    
	// Beispielein- und ausgaben
	// Kann als Menue individualisiert werden
    put (5); output(); 
    put (7); output(); 
    put (11); output();
    get (); output();
    put (13); output();
    get (); output();
    get (); output();
    return EXIT_SUCCESS;
}

