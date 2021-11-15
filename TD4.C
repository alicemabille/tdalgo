#include <stdio.h>
#include <stdlib.h>

typedef int TElement;

typedef struct cellule{
  TElement donnee;
  struct cellule *suivant;
}*Liste;

TElement getDonnee(Liste l){
  return l->donnee;
}
Liste getSuivant(Liste l){
  return l->suivant;
}

Liste initL(void){
  return NULL;
}

int estVideL(Liste l){
  if (l==NULL){
    return 1;
  }
  return 0;
}

void afficheL(Liste l){
  while(!estVideL(l)){
    printf("%d \n",l->donnee);
    l=l->suivant;
  }
}

int longListe(Liste l){
  int i=0;
  while(!estVideL(l)){
    i++;
    l=l->suivant;
  }
  return i;
}

TElement donneeMax(Liste l){
  if (estVideL(l)){
    printf("La liste est vide.");
    return 0;
  }
  else{
    TElement max=getDonnee(l);
    while(!estVideL(l)){
      if (max<getDonnee(l)){
        max=getDonnee(l);
      }
      l=getSuivant(l);
    }
    return max;
  }
}

Liste adresseDonneeMax(Liste l){
  TElement max=l->donnee;
  Liste adMax=l;
  while(!estVideL(l)){
    if (max < l->donnee){
      max=l->donnee;
    }
    else{
      adMax=l->suivant;
    }
    l=l->suivant;
  }
  return adMax;
}

void inserTete(Liste *l, TElement donnee){
    Liste tmp=initL();
    tmp=(Liste)malloc(sizeof(struct cellule));
    tmp->donnee=donnee;
    tmp->suivant=*l;
    *l=tmp;
}
