#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], marker;
int marker = -1;

static int pop(void) {
    if (marker<0)
        printf("Stack ist leer");
    int d = stack[marker--];
    printf("%d was deleted from Stack\n", d);
    return d;
}

static int push(int z) {
    if (marker == (MAX-1))
        pop();
    //Einfuegen an der naechsten Stelle
    stack[++marker] = z;
    return z;
}

static void output() {
    if (marker<0)
        printf("Stack ist leer"); 
    else {
        for (int i=0; i<=marker; i++) 
            printf("%d. Stelle des Stacks: %d\n", i+1, stack[i]);
    }    
    printf("\n");
}

int main()
{    
	// Beispielein- und ausgaben
	// Kann als Menue individualisiert werden
    push (5); output(); 
    push (7); output(); 
    push (11); output();
    pop (); output();
    push (13); output();
    pop (); output();
    pop (); output();
    return EXIT_SUCCESS;
}