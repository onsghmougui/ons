#include <stdio.h>
#include "utilisateur.h"
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void ajout_user(char * fileuser,utilisateur u,int ET,int OU )
{
		
	if(ET==2)
	strcpy(u.genre_user,"Homme");
	if(ET==1)
	strcpy(u.genre_user,"Femme");
	if(OU==2)
	strcpy(u.nationalite_obs,"Tunisienne");
	if(OU==1)
	strcpy(u.nationalite_obs,"Etrangere");
	FILE * f=fopen(fileuser,"a");
	if (f!=NULL)
	{		
		if (strcasecmp(u.role_user,"observateur")!=0)

		{
			strcpy(u.nationalite_obs,"-1");
			strcpy(u.profession_obs,"-1");
			strcpy(u.appartenance_obs,"-1");
	 	}
		
		fprintf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s  \n",u.nom_user,u.prenom_user,u.date.jour,u.date.mois,u.date.annee,u.cin_user,u.role_user,u.genre_user,u.num_bv_user,u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs);
		

		fclose(f);
	}
}





void modifier_user(char * filename,char id[],utilisateur nu,int ET,int OU)
{	
int test=0;
utilisateur u;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("temp.txt","a");
if(f!=NULL && f2!=NULL)
    {
     while (fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s ",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF){
    if(strcmp(id,u.cin_user)==0){
        fprintf(f2,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",nu.nom_user,nu.prenom_user,nu.date.jour,nu.date.mois,nu.date.annee,nu.cin_user,nu.role_user,nu.genre_user,nu.num_bv_user,nu.vote_user,nu.nationalite_obs,nu.profession_obs,nu.appartenance_obs);
        test=1;
    }
    else{fprintf(f2,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,u.date.jour,u.date.mois,u.date.annee,u.cin_user,u.role_user,u.genre_user,u.num_bv_user,u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs);}
    }

    }
fclose(f);
fclose(f2);
remove(filename);
rename("temp.txt",filename);


}

void supprimer_user(char * fileuser,char cin[10])
{
	int trouve=0;

	utilisateur u;
	FILE * f=fopen(fileuser,"r");
	FILE * f2=fopen("nouv.txt","w");
	if(f!=NULL && f2!=NULL)
	{
		while(fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s ",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
		{
			if(strcmp(u.cin_user,cin)==0)
				trouve=1;
			else
				fprintf(f2,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,u.date.jour,u.date.mois,u.date.annee,u.cin_user,u.role_user,u.genre_user,u.num_bv_user,u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs);
		}
	}
	fclose(f);
	fclose(f2);
	remove(fileuser);
	rename("nouv.txt",fileuser);
}


utilisateur chercher_user(char * fileuser,char cin[])
{
	utilisateur u;
	int trouve=0;
	FILE * f=fopen(fileuser,"r");
	if(f!=NULL)
	{
		while((trouve==0) && (fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s ",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF))
		{
			if(strcmp(u.cin_user,cin)==0)
				trouve=1;
		}
	}
	fclose(f);
	/*if(trouve==0)
	strcpy(u.cin_user,"-1");*/
	return u;
}



enum
{
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	CIN,
	ROLE,
	GENRE,
	NUMBV,
	VOTE,
	NATIONALITE,
	PROFESSION,
	APPARTENANCE_POLITIQUE,
	COLUMNS,
};




void afficher_user(GtkWidget *liste,char * fileuser)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char nom[50];
	char prenom[50];
	int jour;
	int mois;
	int annee;
	char cin[10];
	char role[50];
	char genre[50];
	int num_bv;
	int vote;
	char nationalite[50];
	char profession[50];
	char appartenance[50];

	utilisateur u;
	store=NULL;
	FILE  *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	




	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("role", renderer,"text",ROLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer,"text",GENRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_bv", renderer,"text",NUMBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("vote", renderer,"text",VOTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	





	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite", renderer,"text",NATIONALITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("profession", renderer,"text",PROFESSION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("appartenance", renderer,"text",APPARTENANCE_POLITIQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





	
	
				 store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fileuser,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		while(fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s\n ",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,u.nom_user,PRENOM,u.prenom_user,JOUR,u.date.jour,MOIS,u.date.mois,ANNEE,u.date.annee,CIN,u.cin_user, ROLE,u.role_user,GENRE,u.genre_user,NUMBV,u.num_bv_user,VOTE,u.vote_user,NATIONALITE,u.nationalite_obs,PROFESSION,u.profession_obs,APPARTENANCE_POLITIQUE,u.appartenance_obs);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}




int verif_EXIST(char id[10]){
int test=0;
utilisateur u;
FILE *f=fopen("utilisateur.txt","r");
	
while(fscanf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s\n ",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
{
if(strcmp(u.cin_user,id)==0)test=1;

}
fclose(f);
return test;
}

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
/*void TPHF(char * fileuser, int *f,int *h)
{
	utilisateur u;
	int pf,ph;
   	FILE * f1=fopen(fileuser, "r");
	if(f1!=NULL)
    	{
        	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        	{
			if(u.vote_user!=-1)
			{
            			if(strcasecmp(u.genre_user,"Femme")==0)
                		{	
					pf++;
				
				}
				if(strcasecmp(u.genre_user,"Homme")==0)
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
float TPF(char * fileuser)
{
	utilisateur u;
	float tpf;
	int nb,pf;
	char ch[]="Femme";
   	FILE * f1=fopen(fileuser, "r");
	if(f1!=NULL)
    	{
        	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        	{
			if(u.vote_user!=-1)
			{	nb++;
            			if(strcasecmp(u.genre_user,ch)==0)
                		{	
					pf++;}
				
				
				
			}	
		}tpf=(pf/nb)*100;
	}	
	fclose(f1);
	return tpf;
}
float TPH(char * fileuser)
{
	utilisateur u;
	int nb,ph;
	float tph;
   	FILE * f1=fopen(fileuser, "r");
	if(f1!=NULL)
    	{
        	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        	{
			if(u.vote_user!=-1)
			{
            			nb++;
				if(strcasecmp(u.genre_user,"Homme")==0)
				{			
					ph++;
				}
				
			}	
		}tph=(ph/nb)*100;
	}	
	fclose(f1);
	return tph;
}*/
void TPHF(char *fileuser,float *h,float *f){
FILE *f1=fopen(fileuser,"r");
utilisateur u;

if(f1!=NULL){

	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        {
		if((strcmp(u.genre_user,"Homme")==0)&&(u.vote_user!=-1)&&(strcmp(u.role_user,"electeur")==0))
		*h=*h+1;
		else if((strcmp(u.genre_user,"Femme")==0)&&(u.vote_user!=-1)&&(strcmp(u.role_user,"electeur")==0))
		*f=*f+1;


	}

}

fclose(f1);
*f=*f*100/NbrElecVote(fileuser);
*h=*h*100/NbrElecVote(fileuser);

 }

int NbrElecVote(char * fileuser){
int nbrvote=0;
FILE *f1=fopen(fileuser,"r");
utilisateur u;

if(f1!=NULL){

	int test;
	while(fscanf(f1,"%s %s %d %d %d %s %s %s %d %d %s %s %s \n",u.nom_user,u.prenom_user,&u.date.jour,&u.date.mois,&u.date.annee,u.cin_user,u.role_user,u.genre_user,&u.num_bv_user,&u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs)!=EOF)
        {
		test=strcmp(u.role_user,"electeur");
		if((u.vote_user!=-1)&&(test==0))nbrvote++;

	}

}

fclose(f1);

return nbrvote;
}





