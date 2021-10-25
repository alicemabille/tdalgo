#include <stdio.h>
#include <stdlib.h>

typedef int Telement;

typedef struct cellule{
  Telement donnee;
  struct cellule *suivant;
}*Liste;

int estVideListe(Liste l){
  return l==NULL;
}

Liste initListe(){
  return NULL;
}

Liste inserTete(Liste l, Telement elt){
  Liste cel;
  cel=(Liste)malloc(sizeof(struct cellule));
  cel->donnee=elt;
  cel->suivant=l;
  l=cel;
  return l;
}

void afficheLste(Liste l){
  while(!estVideListe(l)){
    printf("%d \n",l->donnee);
    l=l->suivant;
  }
}

void inserQueueRec(Liste *p, Telement m){
  if (estVideListe(*p)){
    *p=inserTete(*p,m);
  }
  else{
    inserQueueRec(&(*p)->suivant, m);
  }
}

int main(){
  Liste l;
  l=initListe();
  l=inserTete(l,15);
  l=inserTete(l,12);
  l=inserTete(l,9);
  afficheLste(l);
  inserQueueRec(&l,20);
  inserQueueRec(&l,25);
  afficheLste(l);
  return 0;
}
