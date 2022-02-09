#include <stdio.h>
#include <stdlib>

typedef struct{
  int degre;
  float coef;
}Monome;

typedef struct{
  int nbMonome;
  Monome *poly;
}Polynome;

void initPolynome(Polynome *p){
  p = (Polynome *)malloc(nbMonome*sizeof(Monome));
}

float evalMonome(Monome *m){
  float total=1;
  for (i=0; i++; i=Monome.degre){
    total=total*Monome.coef;
  }
  return total;
}

float evalPolynome(Polynome *p){
  float somme=0;
  for (int i=0; i++; i=degre){
    somme+=evalMonome(Polynome[i]);
  }
}

bool estVidePoly(Polynome *p){
  if (p.taille==0){
    return 1;
  }
  else{
    return 0;
  }
}

int degNoms(Monome *m){
  return m.coef;
}

int coefMon(Polynome *p){
  int n=0;
  for (int i=0;i=p.nbMonome;i++){
    if (p.coef>n){
      n=p.coef;
    }
  }
}
