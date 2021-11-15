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
  if (ab==NULL){
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

Arbre creatNoeud(Arbre fg, Arbre fd, Telement alt){
  Arbre fe=creatFeuille(elt);
  fe->fils_gauche=fg;
  fe->fils_droit=fd;
  return fe;
}

int donneeArbre(Arbre a){
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
    traiter(a->valeur);
    parcoursPrefixe(Arbre a->fils_gauche(a));
    parcoursPrefixe(Arbre a->fils_droit(a));
  }
}

void parcoursInfixe(Arbre a){
  //Infixe : gauche, racine, droite
  if(!estVideArbre(a)){
    parcoursPrefixe(Arbre a->fils_gauche(a));
    traiter(a->valeur);
    parcoursPrefixe(Arbre a->fils_droit(a));
  }
}

void parcoursPostfixe(Arbre a){
  //Postfixe : gauche, droite, racine
  if(!estVideArbre(a)){
    parcoursPrefixe(Arbre a->fils_gauche(a));
    parcoursPrefixe(Arbre a->fils_droit(a));
      traiter(a->valeur);
    }
  }

void parcoursBizarre(Arbre a){
  //commence par le bas de l'arbre
  if(!estVideArbre(a)){
    traiter(a->valeur);
    if(!estFeuille(fils_gauche(a))){
      parcoursPrefixe(Arbre a->fils_gauche(a));
    }
    else{
      traiter(fils_gauche(a));
    }
    if(!estFeuille(fils_droit(a))){
      parcoursPrefixe(Arbre a->fils_droit(a));
    }
    else{
      traiter(fils_droit(a));
    }
  }
}

int tailleArbre(Arbre a){
  int taille=0;
  if (!estVideArbre(a)){
    taille++;
    taille += tailleArbre(a->fils_gauche);
    taille += tailleArbre(a->fils_droit);
  }
  return taille;
}
