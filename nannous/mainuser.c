#include <stdio.h>
#include "utilisateur.h"
#include <string.h> 
int main () 
{ utilisateur u1={"ghmougui","ons",13,11,2001,"14415746","electeur","femme",10,1};
  utilisateur u2={"oueslati","med",11,03,1980,"11236778","observateur","homme",12,1,"tunisien","gauche","prof"};
  utilisateur u3={"lejmy","alia",11,03,1980,"01657477","observateur","femme",12,1,"tunisienne","gauche","prof"};
  int x=ajout_user("utilisateur.txt",u1);
  x=ajout_user("utilisateur.txt",u2);
  x=ajout_user("utilisateur.txt",u3);
  x=modifier_user("utilisateur.txt","01657477",u2);
  x=supprimer_user("utilisateur.txt","01657477");





return 0;

}
