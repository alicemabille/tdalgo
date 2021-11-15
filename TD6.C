typedef struct {
  float coef;
  int degre;
}Monome;

typedef struct toto{
  Monome m;
  struct toto *suivant;
}*Polynome;

int degMon(Monome m){
  return m.degre;
}

int coefMon(Monome m){
  return m.coef;
}

Monome monCourant(Polynome p){
  return p->m;
}

Polynome monSuivant(Polynome p){
  return p->suivant;
}

Polynome creerPolynome(){
  return NULL;
}

int estVidePoly(Polynome p){
  if (p->m==NULL){
    return 1;
  }
  return 0;
}

Polynome inserTete(Polynome p, Monome m){
  Polynome tmp=creerPolynome();
  tmp=(Polynome*)malloc(sizeof(struct toto));
  tmp->m=m;
  tmp->suivant=p;
  return tmp;
}

Polynome inserQueue(Polynome p, Monome m){
  Polynome c=p;
  while (!estVidePoly(p->suivant)){
    p=p->suivant;
  }
  Polynome tmp =creerPolynome();
  tmp=(Polynome*)malloc(sizeof(struct toto));
  tmp->m=m;
  tmp->suivant=NULL;
  p->suivant=tmp;
  return c;
}

void inserQueueRec(Polynome *p, Monome m){
  if (estVidePoly(*p)){
    p=inserTete(*p,m);
  }
  else{
    inserQueueRec((*p)->suivant, m);
  }
}

Polynome inserMonPoly(Polynome p, Monome val){
  Polynome c=p;
  if (estVidePoly(p)){
    return p=inserTete(p,m);
  }
  else{
    while(degMon(val)<degMon(monCourant(monSuivant(p))) && !estVidePoly(p->suivant)){
      p=p->suivant;
    }
  }
  if(!estVidePoly(p->suivant)){
    Polynome tmp=(Polynome*)malloc(sizeof(struct toto));
    tmp->m=val;
    tmp->suivant=p->suivant;
    p->suivant=tmp;
    return c;
    //car c est un pointeur; les changements sont bien sauvegardés
  }
}

Polynome suppTete(Polynome p, Monome m){
  Polynome t=p;
  p=p->suivant;
  free(t);
  return p;
}

Polynome appartientMonome(Polynome p, Monome m){
    while(degMon(m)<degMon(monCourant(p)) && !estVidePoly(p)){
      p=p->suivant;
    }
    if (!estVidePoly(p)){
      if (coefMon(m)==coefMon(monCourant(p))){
        return p;
      }
      else return NULL;
    }
    else return NULL;
}

Polynome suppMonPoly(Polynome p, Monome m){
  Polynome c=p;
  if(estVidePoly(p)){
    return p;
  }
  else {
    while (degMon(m)<degMon(monCourant(p->suivant)) && (!estVidePoly(p->suivant))){
      p=p->suivant;
    }
    if (estVidePoly(p->suivant)){
      return c;
    }
    else{
      if (degMon(m)==degMon(monCourant(p->suivant))){
        if (coefMon(m)==coefMon(monCourant(p->suivant))){

        }
      }
    }
  }
}

Polynome delPoly (Polynome p){
  Polynome tmp;
  while (!estVidePoly(p)){
    tmp=p;
    p=p->suivant;
    free(tmp);
  }
  return NULL;
}

float maxCoef(Polynome p){
  float max= -1000;
  while(!estVidePoly(p)){
    if (max<coefMon(p->m)){
      max=p->m.coef;
    }
    p=p->suivant;
  }
  return max;
}

float sommeCoef (Polynome p){
  float sum=0;
  while(!estVidePoly(p)){
    sum+=coefMon(p->m);
    p=p->suivant;
  }
  return sum;
}

Polynome derivPoly(Polynome p){
  Polynome deriv=creerPolynome();
  if (p->m.degre == 0){
    p=p->suivant;
  }
  //car la dérivée d'une constante est nulle
  while(!estVidePoly(p)){
    Monome d;
    p->m.coef=p->m.coef*p->m.degre;
    d.degre=p->m.degre-1;
    deriv=inserMonPoly(deriv,p);
  }
  return deriv;
}
