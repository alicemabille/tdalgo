#include <stdio.h>
#include <stdlib.h>


typedef struct toto{
  int m;
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


int teteFile(File p){
  return p->m;
}

File inserQueue(p){
  if (estVideFile(*p)){
    File tmp=creerFile();
    tmp=(File*)malloc(sizeof(struct toto)); //on rajoute un élément donc on malloc
    tmp->m=m;
    tmp->suivant=p;
    return tmp;
  }
  else{
    inserQueue((*p)->suivant, m);
  }
}

void afficheFile(File p){
  while (!estVideFile(p)){
    printf("%d",p->m);
    p=p->suivant;
  }
}

int sommeFile(File p){
  int sum=0;
  while(!estVideFile(p)){
    sum+=teteFile(p);
    suppTete(p);
  }
  return sum;
}
