#include <stdio.h>
#include <stdlib.h>

typedef struct toto *Pile;

Pile creerPile();
Pile empiler(Pile p, int a);
Pile depiler(Pile p);
int estVidePile(Pile p);
int tetePile(Pile p);
void affichePile(Pile p);
int sommePile(Pile p);
