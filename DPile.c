//#include "DPile.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct toto{
  int m;
  struct toto* suivant;
}*Pile;

Pile creerPile(){
  return NULL;
}

int estVidePile(Pile p){
  if (p==NULL){
    return 1;
  }
  return 0;
}

Pile empiler(Pile p, int a){
    Pile tmp=(Pile)malloc(sizeof(struct toto));
    tmp->m=a;
    tmp->suivant=p;
    return tmp;

}

Pile depiler(Pile p){
  Pile t=p;
  p=p->suivant;
  free(t);
  return p;
}

int tetePile(Pile p){
  return p->m;
}

void affichePile(Pile p){
  while (!estVidePile(p)){
    printf("%d \n",p->m);
    p=p->suivant;
  }
}

int sommePile(Pile p){
  int sum=0;
  while(!estVidePile(p)){
    sum+=tetePile(p);
    p = depiler(p);
  }
  return sum;
}
