#include "file.h"

int main(void){
  int a=-1;
  File p = NULL;
  while(a<0){
    printf("Entrer un entier positif à emfiler :\n");
    scanf("%d", &a);
    p=emfiler(p,a);
  }

  afficheFile(p);

  int sum = sommeFile(p);
  printf("Somme des nombres dans votre file : %d", sum);

  return 0;
}
