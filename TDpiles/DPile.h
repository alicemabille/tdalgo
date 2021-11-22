#include <stdio.h>
#include <stdlib.h>

typedef struct arbre *Arbre;
typedef Arbre Telement;
typedef struct toto *Pile;

Pile creerPile();
Pile empiler(Pile p, Telement a);
Pile depiler(Pile p);
int estVidePile(Pile p);
Telement tetePile(Pile p);
void affichePile(Pile p);
int sommePile(Pile p);
