#include <stdio.h>
#include <stdlib.h>

typedef struct arbre *Arbre;
typedef Arbre Telement;
typedef struct toto *File;

File creerFile();
File suppTete(File p);
File inserQueue(File p, Telement a);
int estVideFile(File p);
Telement teteFile(File p);
void afficheFile(File p);
int sommeFile(File p);
