#include "DPile.h"

int main(void){
  int a;
  Pile p = NULL;
  printf("Entrer un entier positif à empiler :\n");
  scanf("%d", &a);
  while(a<0){
    p=empiler(p,a);
    printf("Entrer un entier positif à empiler :\n");
    scanf("%d", &a);

  }

  affichePile(p);

  int sum = sommePile(p);
  printf("\n Somme des nombres dans votre pile : %d\n", sum);



  return 0;
}
