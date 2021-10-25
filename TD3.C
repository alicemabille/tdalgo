#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
	int degre;
	float coef;
}Monome;

typedef struct{
	int nbMonome;
	Monome *poly;
}Polynome;

int est_vide_poly(Polynome p){
  /* Façon standard
  if(p.nbMonome == 0){
  	return 1;
  }
  else return 0;
  */
  return (p.nbMonome == 0) ? 1 : 0; // façon inline avec operateur de comparaison ?
}

Polynome initPoly(int taille){
  Polynome p;
  p.nbMonome=taille;
  p.poly = (Monome *)malloc(sizeof(Monome)*taille);
	for(int i=0;i<taille;i++){
		printf("degré ? \n");
		int degre;
		scanf("%d",&degre);
		printf("coefficient ? \n");
		float coef;
		scanf("%f",&coef);
		p.poly[i].degre=degre;
		p.poly[i].coef=coef;
	}
  return p;
}

float evalPoly(Polynome p, float x){
	float sum=0;
	int i=0;
	for(i=0;i<p.nbMonome;i++){
		sum=sum+(p.poly[i].coef*(pow(x,p.poly[i].degre)));
	}
	return sum;
}

Polynome deriv_poly(Polynome p){
	Polynome p2=initPoly(p.nbMonome-1);
	for(int i=0;i<p.nbMonome;i++){
		if(i>0){
			p2.poly[i].degre=p.poly[i].degre-1;
			p2.poly[i].coef=p2.poly[i].coef*p2.poly[i].degre;
		}
	}
	return p2;
}

int main(int argc, char * argv[]){
	Polynome p;
  p=initPoly(5);

	//float x=scanf("Entrez une valeur réelle pour x afin d'évaluer le polynôme. %f",&x);
  float x=7;
	float eval=evalPoly(p,x);
	printf("P(%f)=%f",x,eval);

	/*Polynome p2=deriv_poly(p);
	printf("Dérivée de P : \n");
	for (int i=0; i<p.nbMonome;i++){
		printf("+%fx%d",p.poly[i].coef,p.poly[i].degre);
	}*/
}
