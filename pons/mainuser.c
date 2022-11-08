#include <stdio.h>
#include <string.h>
#include "utilisateur.h"
int main()
{
    utilisateur u1= {"nometprenom1",14154755,13,11,2001,"observateur","femme",10,1,"tunisienne","professeur","droite"},
    u2= {"nometprenom2",14436611,30,02,2000,"agent bv","homme",2,1,"tunisienne","ingenieur","gauche"};
    int x=ajout_user("utilisateur.txt", u1);
   
    x=modifier_user("utilisateur.txt",14415771,u2);
    utilisateur u3=chercher_user("utilisateur.txt",14412543);
    if(u3.cin_user!=-1)
    {
	printf("utilisateur existe déja");}
    else {
	printf("utilisateur n'existe pas");}
    
    x= supprimer_user("utilisateut.txt",14412543);
    return 0;
}
