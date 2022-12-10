#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct
{
	int jour;
	int mois;
	int annee;
} date_user;
typedef struct 
{
	char nom_user[50];
	char prenom_user[50];
	date_user date;
	char cin_user[10];
	char role_user[50];
	char genre_user[50];
	int num_bv_user;
	int vote_user;
	char nationalite_obs[50];
	char profession_obs[50];
	char appartenance_obs[50];
}utilisateur;
void ajout_user(char * fileuser,utilisateur u,int ET,int OU);
void afficher_user(GtkWidget *liste,char * fileuser);
void modifier_user(char * fileuser,char id[],utilisateur nouv,int ET,int OU);
void supprimer_user(char * fileuser,char cin[50]);
utilisateur chercher_user(char * fileuser,char cin[]);

#endif

