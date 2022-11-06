#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <stdio.h>
typedef struct {
	int jour;
	int mois;
	int annee;
}date_user;
typedef struct 
{
	 char nometprenom_user[50];
	char role_user[50];
	char genre_user[50];
	char nationalite_obs[50];
	char appartenance_obs[50];
	char profession_obs[50];
	int cin_user;
	int num_bv_user;
	int vote_user;
	date_user date;
}utilisateur;
int ajout_user(char * filename, utilisateur u);
int modifier_user(char * filename,int cin,utilisateur nouv);
int supprimer_user(char * fileuser,int cin);
utilisateur chercher_user(char * fileuser, int cin);
#endif
