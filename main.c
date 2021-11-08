#include "DPile.h"

int main(void){
  int a=-1;
  Pile p = NULL;
  while(a<0){
    printf("Entrer un entier positif à empiler :\n");
    scanf("%d", &a);
    p=empiler(p,a);
  }

  affichePile(p);

  int sum = sommePile(p);
  printf("Somme des nombres dans votre pile : %d", sum);

  return 0;
}
