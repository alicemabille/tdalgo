#include "TDfiles/file.h"
#include "TDpiles/DPile.h"
#include <math.h>

typedef int Telement;

typedef struct arbre{
  Telement valeur;
  struct arbre* fils_gauche;
  struct arbre* fils_droit;
}*Arbre;

Arbre initArbre(){
  return NULL;
}

int estVideArbre(Arbre a){
  if (a==NULL){
    return 1;
  }
  return 0;
}

Arbre creatFeuille(Telement elt){
  Arbre f = initArbre();
  f=(Arbre)malloc(sizeof(struct arbre));
  f->valeur=elt;
  f->fils_gauche=NULL; //initArbre();
  f->fils_droit=NULL;
  return f;
}

Arbre creatNoeud(Arbre fg, Arbre fd, Telement elt){
  Arbre fe=creatFeuille(elt);
  fe->fils_gauche=fg;
  fe->fils_droit=fd;
  return fe;
}

Telement donneeArbre(Arbre a){
  return a-> valeur;
}

Arbre fils_gauche(Arbre a){
  return a->fils_gauche;
}

Arbre fils_droit(Arbre a){
  return a->fils_droit;
}

int estFeuille(Arbre a){
  //une feuille est un noeud terminal : ses fils sont NULL
  //un noeud est un sous-arbre
  if (fils_gauche(a)==NULL && fils_droit(a)==NULL){
    return 1;
  }
  return 0;
}

void parcoursPrefixe(Arbre a){
  //Préfixe : racine, gauche, droite
  if(!estVideArbre(a)){
    //traiter(a->valeur);
    parcoursPrefixe(a->fils_gauche);
    parcoursPrefixe(a->fils_droit);
  }
}

void parcoursInfixe(Arbre a){
  //Infixe : gauche, racine, droite
  if(!estVideArbre(a)){
    parcoursPrefixe(a->fils_gauche);
    //traiter(a->valeur);
    parcoursPrefixe(a->fils_droit);
  }
}

void parcoursPostfixe(Arbre a){
  //Postfixe : gauche, droite, racine
  if(!estVideArbre(a)){
    parcoursPrefixe(a->fils_gauche);
    parcoursPrefixe(a->fils_droit);
    //traiter(a->valeur);
  }
}

void parcoursBizarre(Arbre a){
  //commence par le bas de l'arbre
  if(!estVideArbre(a)){
    //traiter(a->valeur);
    if(!estFeuille(fils_gauche(a))){
      parcoursPrefixe(a->fils_gauche);
    }
    else{
      //traiter(fils_gauche(a));
    }
    if(!estFeuille(fils_droit(a))){
      parcoursPrefixe(a->fils_droit);
    }
    else{
      //traiter(fils_droit(a));
    }
  }
}

int tailleArbre(Arbre a){
  if (estVideArbre(a)){
    return 0;
  }
  else{
    return 1 + tailleArbre(a->fils_gauche) + tailleArbre(a->fils_droit);
  }
}

int nbFeuilles(Arbre a){
  if (estVideArbre(a)){
    return 0;
  }
  else{
    if(estFeuille(a)){
      return 1;
    }
    return nbFeuilles(a->fils_gauche) + nbFeuilles(a->fils_droit);
  }
}

int contientEltArbre(Arbre a, Telement elt){
  if(!estVideArbre(a)){
    return (a->valeur==elt) || contientEltArbre(a->fils_gauche, elt) || contientEltArbre(a->fils_droit, elt);
  }
  else return 0;
}

int hauteurArbre(Arbre a){
  if (estVideArbre(a)){
    return 0;
  }
  int hg = hauteurArbre(fils_gauche(a));
  int hd = hauteurArbre(fils_droit(a));
  //return max(hg,hd)+1;
  if (hg>hd){
    return hg+1;
  }
  else return hd+1;
}

Arbre LibMem(Arbre a){
  free(a);
  return a=NULL;
}

Arbre suppArbre(Arbre a){
  if(!estVideArbre(a)){
    suppArbre(fils_gauche(a));
    suppArbre(fils_droit(a));
    a=LibMem(a);
  }
  return a;
}

Telement RechercheMinArbre(Arbre a, Telement min){
  if (estVideArbre(a)){
    return 0;
  }
  Telement g = RechercheMinArbre(fils_gauche(a),min);
  Telement d = RechercheMinArbre(fils_droit(a),min);
  if (a->valeur<min){
    min=a->valeur;
  }
}

void SommeArbre(Arbre ab, int *somme){//précondition initialisée à 0
  if(!estVideArbre(ab)){
    SommeArbre(ab->fils_gauche, somme);
    *somme+=ab->valeur;
    SommeArbre(ab->fils_droit,somme);
  }
}

void ParcoursLargeur(Arbre ab){ //affichage des valeurs de l'arbre par étage
  if (estVideArbre(ab)){
    printf("Arbre vide!\n");
  }
  else{
    Arbre tmp=ab;
    File f=creerFile();
    f=inserQueue(f,ab);
    while(!estVideFile(f)){
      tmp=teteFile(f);
      printf("%d\n",tmp->valeur);
      f=suppTete(f);
      if(!estVideArbre(tmp->fils_gauche)){
        f=inserQueue(f,tmp->fils_gauche);
      }
      if(!estVideArbre(tmp->fils_droit)){
        f=inserQueue(f,tmp->fils_droit);
      }
    }
  }
}

//Arbre ParcoursLargeurRec(...) à faire à la maison

void ParcoursPrefixeIt(Arbre ab){
  //Préfixe : racine, gauche, droite
  if (estVideArbre(ab)){
    printf("Arbre vide!\n");
  }
  else{
    Arbre tmp;
    Pile p=empiler(p,ab);
    while(!estVidePile(p)){
      tmp=tetePile(p);
      p=depiler(p);
      printf("%d\n",tmp->valeur);
      if(!estVideArbre(tmp->fils_droit)){
        p=empiler(p,tmp->fils_droit);
      }
      if(!estVideArbre(tmp->fils_gauche)){
        p=empiler(p,tmp->fils_gauche);
      }
    }
  }
}

Arbre inserABR(Telement elt, Arbre a){
  if(estVideArbre(a)){
    return creatFeuille(elt);
  }
  if (elt>donneeArbre(a)){
    a->fils_droit=inserABR(elt,fils_droit(a));
  }
  else {
    a->fils_gauche=inserABR(elt,fils_gauche(a));
    return a;
  }
}

void inserABR(Telement elt, Arbre *a){
  if(estVideArbre(*a)){
    *a = creatFeuille(elt);
  }
  else {
    if(elt>donneeArbre(*a)){
      inserABR(elt, &((*a)->fils_droit));
    }
    else inserABR(elt, &((*a)->fils_gauche));
  }
}

//définir suppRacineABR
Arbre suppEltABR(Telement elt, Arbre racine){
  if(!estVideArbre(racine)){
    if(donneeArbre(racine)==elt){
      suppRacineABR(racine);
      return racine;
    }
    else{
      if(elt<donneeArbre(racine)){
        racine->fils_gauche = suppEltABR(elt, fils_gauche(racine));
      }
      else racine->fils_droit = suppEltABR(elt, fils_gauche(racine));
    }
  }
}