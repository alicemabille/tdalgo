#include <stdio.h>
#include <stdlib.h>

typedef struct arbre{
  Telement valeur;
  struct arbre* fils_gauche;
  struct arbre* fils_droit;
}*Arbre;

typedef Arbre Telement;

typedef struct toto{
  Telement m;
  struct toto* suivant;
}*File;

File creerFile(){
  return NULL;
}

int estVideFile(File p){
  if (p==NULL){
    return 1;
  }
  return 0;
}


File suppTete(File p){
  File t=p; //pas besoin de malloc car on fait pointeur t = pointeur p
  p=p->suivant;
  free(t);
  return p;
}


Telement teteFile(File p){
  return p->m;
}

File inserQueue(File p, Telement m){
  if (estVideFile(p)){ //équivalent de InserTete() mais on n'a pas de fonction InserTete() ici car c'est une file
    File tmp=creerFile();
    tmp=(File)malloc(sizeof(struct toto)); //on rajoute un élément donc on malloc
    tmp->m=m;
    tmp->suivant=p;
    return tmp;
  }
  else{
    inserQueue((p)->suivant, m);
  }
}

void afficheFile(File p){
  while (!estVideFile(p)){
    printf("%d",p->m);
    p=p->suivant;
  }
}

/*int sommeFile(File p){
  int sum=0;
  while(!estVideFile(p)){
    sum+=teteFile(p);
    p = suppTete(p);
  }
  return sum;
}*/
