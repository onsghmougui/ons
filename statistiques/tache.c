#include<stdio.h>
#include"utilisateur.h"
#include<string.h>
#include"tache.h"
float TVB( char * fileuser)
{
	utilisateur u;
   	float nvb,tvb,nbv;
   	FILE * f=fopen(fileuser,"r");
    	if(f!=NULL)
    	{
        	while(fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        	{	nbv++;
            		if(u.vote_user==0)
                	{	nvb+=1;
	
			}
			
        	}tvb=(nvb/nbv)*100;
    	}
    	fclose(f);
	return tvb;
}
void TPHF(char * fileuser, int *f,int *h)
{
	utilisateur u;
	int pf,ph;
   	FILE * f1=fopen(fileuser, "r");
	if(f1!=NULL)
    	{
        	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        	{
			if(u.vote_user==!-1)
			{
            			if(strcasecmp(u.genre_user,"femme")==0)
                		{	
					pf++;
				
				}
				else
				{			
					ph++;
				}
				
			}	
		}
	}
	fclose(f1);
	*f=((*f+pf)/(pf+ph))*100;
	*h=((*h+ph)/(pf+ph))*100;
}

