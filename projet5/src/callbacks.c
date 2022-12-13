#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"

float h,f;
int ET=0;
int OU =0;
utilisateur userDeleted;
utilisateur ToUse;

void
on_entryProf_user_activate             (GtkEntry        *entry,
                                        gpointer         user_data)
{

}


void
on_radiobuttonFemme_user_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
ET=1;


}


void
on_radiobuttonHomme_user_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
ET=2;

}


void
on_checkbuttonEtranger_user_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
OU=1;


}


void
on_checkbuttonTun_user_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
OU=2;

}


void
on_comboboxApp_user_move_active        (GtkComboBox     *combobox,
                                        GtkScrollType    arg1,
                                        gpointer         user_data)
{

}


void
on_buttonAfficher_user_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
utilisateur u;
GtkWidget *fenetre_ajout_user;
GtkWidget *fenetre_affichage_user;
GtkWidget *treeview_user;

fenetre_ajout_user = lookup_widget(objet,"ajout_user");

gtk_widget_hide(fenetre_ajout_user);
fenetre_affichage_user=lookup_widget(objet,"affichage_user");
fenetre_affichage_user=create_affichage_user();

gtk_widget_show(fenetre_affichage_user);

treeview_user=lookup_widget(fenetre_affichage_user,"treeview_user");
afficher_user(treeview_user,"utilisateur.txt");

}



void
on_buttonValider_user_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom1;
GtkWidget *prenom1;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *cin1;
GtkWidget *role1;
GtkWidget *num_bv1;
GtkWidget *vote1;
GtkWidget *profession1;
GtkWidget *appartenance1;
ToUse=chercher_user("utilisateur.txt",userDeleted.cin_user);

utilisateur u;



//associer les objets avec des variables

nom1=lookup_widget(objet,"entryNom_user");
prenom1=lookup_widget(objet,"entryPrenom_user");
jour1=lookup_widget(objet,"spinbuttonJour_user");
mois1=lookup_widget(objet,"spinbuttonMois_user");
annee1=lookup_widget(objet,"spinbuttonAnnee_user");
cin1=lookup_widget(objet,"entryCin_user");
role1=lookup_widget(objet,"comboboxRole_user");
num_bv1=lookup_widget(objet,"spinbuttonNumBV_user");
vote1=lookup_widget(objet,"spinbuttonVote_user");
profession1=lookup_widget(objet,"entryProf_user");
appartenance1=lookup_widget(objet,"comboboxApp_user");

//recuperer les valeurs de entry
strcpy(u.nom_user,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(u.prenom_user,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(u.cin_user,gtk_entry_get_text(GTK_ENTRY(cin1)));
strcpy(u.profession_obs,gtk_entry_get_text(GTK_ENTRY(profession1)));






//recuperer les valeurs de spin button


u.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour1));
u.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois1));
u.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee1));
u.num_bv_user=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(num_bv1));
u.vote_user=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(vote1));


//recuperer les valeurs de combobox

strcpy(u.role_user,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role1)));
strcpy(u.appartenance_obs,gtk_combo_box_get_active_text(GTK_COMBO_BOX(appartenance1)));


	if(ET==2)
	strcpy(u.genre_user,"Homme");
	if(ET==1)
	strcpy(u.genre_user,"Femme");
	if(OU==2)
	strcpy(u.nationalite_obs,"Tunisienne");
	if(OU==1)
	strcpy(u.nationalite_obs,"Etrangere");



//checkbox

//radio button


if(u.cin_user=="")strcpy(u.cin_user,ToUse.cin_user);
if((strcmp(u.genre_user,"Homme")!=0)&&(strcmp(u.genre_user,"Femme")))strcpy(u.genre_user,ToUse.genre_user);


GtkWidget* msg=lookup_widget(objet,"verifcin");


if(verif_EXIST(u.cin_user)==0) {
if((strlen(u.cin_user)!=8))gtk_widget_show(msg);
else ajout_user("utilisateur.txt",u,ET,OU);

}
else {
if (strcmp(u.role_user,"observateur")!=0)

		{
			strcpy(u.nationalite_obs,"-1");
			strcpy(u.profession_obs,"-1");
			strcpy(u.appartenance_obs,"-1");
	 	}
		
modifier_user("utilisateur.txt",u.cin_user,u,ET,OU);}


}



void
on_treeview_user_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gint* jour;
gint* mois;
gint* annee;
gchar* cin;
gchar* role;
gchar* genre;
gint* numBV;
gint* vote;
gchar* nationalite;
gchar* profession;
gchar* appartenance;



GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&jour,3,&mois,4,&annee,5,&cin,6,&role,7,&genre,8,&numBV,9,&vote,10,&nationalite,11,&profession,12,&appartenance,-1);

strcpy(userDeleted.nom_user,nom);
strcpy(userDeleted.prenom_user,prenom);
userDeleted.date.jour=jour;
userDeleted.date.mois=mois;
userDeleted.date.annee=annee;
strcpy(userDeleted.cin_user,cin);
strcpy(userDeleted.role_user,role);
strcpy(userDeleted.genre_user,genre);
userDeleted.num_bv_user=numBV;
userDeleted.vote_user=vote;
strcpy(userDeleted.nationalite_obs,nationalite);
strcpy(userDeleted.profession_obs,profession);
strcpy(userDeleted.appartenance_obs,appartenance);



afficher_user(treeview,"utilisateur.txt");
}

}

void
on_buttonAjouter_user_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
utilisateur u;
GtkWidget *fenetre_ajout_user;
GtkWidget *fenetre_affichage_user;
GtkWidget *treeview_user;

fenetre_affichage_user = lookup_widget(objet,"affichage_user");
gtk_widget_hide(fenetre_affichage_user);

fenetre_ajout_user=lookup_widget(objet,"ajout_user");
fenetre_ajout_user=create_ajout_user();
gtk_widget_show(fenetre_ajout_user);

treeview_user=lookup_widget(fenetre_affichage_user,"treeview_user");
afficher_user(treeview_user,"utilisateur.txt");


}


void
on_buttonModifier_user_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{


GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *cin;
GtkWidget *role;
GtkWidget *num;
GtkWidget *vote;
GtkWidget *profession;
GtkWidget *appartenance;
GtkWidget *fenetre;
GtkWidget *homme;
GtkWidget *femme;
GtkWidget *tunisian;
GtkWidget *etrangere;

GtkWidget *fenetre_ajout_user;
GtkWidget *fenetre_affichage_user;
GtkWidget *treeview_user;

fenetre_affichage_user = lookup_widget(objet,"affichage_user");


fenetre_ajout_user=lookup_widget(objet,"ajout_user");
fenetre_ajout_user=create_ajout_user();
gtk_widget_show(fenetre_ajout_user);


utilisateur user=chercher_user("utilisateur.txt",userDeleted.cin_user);

nom=lookup_widget(fenetre_ajout_user,"entryNom_user");
prenom=lookup_widget(fenetre_ajout_user,"entryPrenom_user");
jour=lookup_widget(fenetre_ajout_user,"spinbuttonJour_user");
mois=lookup_widget(fenetre_ajout_user,"spinbuttonMois_user");
annee=lookup_widget(fenetre_ajout_user,"spinbuttonAnnee_user");
cin=lookup_widget(fenetre_ajout_user,"entryCin_user");
role=lookup_widget(fenetre_ajout_user,"comboboxRole_user");
num=lookup_widget(fenetre_ajout_user,"spinbuttonNumBV_user");
profession=lookup_widget(fenetre_ajout_user,"entryProf_user");
appartenance=lookup_widget(fenetre_ajout_user,"comboboxApp_user");
homme=lookup_widget(fenetre_ajout_user,"radiobuttonHomme_user");
femme=lookup_widget(fenetre_ajout_user,"radiobuttonFemme_user");
tunisian=lookup_widget(fenetre_ajout_user,"checkbuttonTun_user");
etrangere=lookup_widget(fenetre_ajout_user,"checkbuttonEtranger_user");


gtk_entry_set_text(GTK_ENTRY(nom),user.nom_user);
gtk_entry_set_text(GTK_ENTRY(prenom),user.prenom_user);
gtk_entry_set_text(GTK_ENTRY(cin),user.cin_user);
gtk_entry_set_text(GTK_ENTRY(profession),user.profession_obs);
int i;
if(strcmp(user.appartenance_obs,"gauche")==0)i=0;
if(strcmp(user.appartenance_obs,"droite")==0)i=1;
if(strcmp(user.appartenance_obs,"autre")==0)i=2;


 gtk_combo_box_set_active(GTK_COMBO_BOX(appartenance),i);






int j;
if(strcmp(user.role_user,"observateur")==0)j=0;
if(strcmp(user.role_user,"electeur")==0)j=1;
if(strcmp(user.role_user,"admin")==0)j=2;
if(strcmp(user.role_user,"agentBV")==0)j=3;
if(strcmp(user.role_user,"autres")==0)j=4;

 gtk_combo_box_set_active(GTK_COMBO_BOX(role),j);
 gtk_spin_button_set_value(jour,user.date.jour);
 gtk_spin_button_set_value(mois,user.date.mois);
 gtk_spin_button_set_value(annee,user.date.annee);



if(strcmp(user.nationalite_obs,"Tunisienne")==0) {   gtk_toggle_button_set_active(GTK_RADIO_BUTTON(tunisian),TRUE);gtk_toggle_button_set_active(GTK_RADIO_BUTTON(etrangere),FALSE);}
           
	


else if(strcmp(user.nationalite_obs,"Etrangere")==0) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(etrangere),TRUE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(tunisian),FALSE);}
           
	else {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(tunisian),FALSE); gtk_toggle_button_set_active(GTK_CHECK_BUTTON(etrangere),FALSE);}


char ch[50];
sprintf(ch,"%d",user.num_bv_user);
gtk_entry_set_text(GTK_ENTRY(num),ch);





//modifier_user("utilisateur.txt",userDeleted.cin_user,user,ET,OU);




}


void
on_buttonSupprimer_user_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
supprimer_user("utilisateur.txt",userDeleted.cin_user);
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview_user;


w1=lookup_widget(objet,"affichage_user");
fenetre_afficher=create_affichage_user();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);

gtk_widget_show(fenetre_afficher);

treeview_user=lookup_widget(fenetre_afficher,"treeview_user");

afficher_user(treeview_user,"utilisateur.txt");






}


void
on_buttonEnregistrer_user_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;


w1=lookup_widget(objet,"affichage_user");
fenetre_afficher=create_affichage_user();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview_user");
afficher_user(treeview1,"utilisateur.txt");
}


void
on_buttonRechercher_user_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;

GtkWidget  *id_entry;
GtkWidget *output;
char id[10];
id_entry = lookup_widget (objet,"entryRechercher_user");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(id_entry)));

utilisateur u=chercher_user("utilisateur.txt",id);
 FILE *f=fopen("search.txt","w");
if(f!=NULL){
fprintf(f,"%s %s %d %d %d %s %s %s %d %d %s %s %s  \n",u.nom_user,u.prenom_user,u.date.jour,u.date.mois,u.date.annee,u.cin_user,u.role_user,u.genre_user,u.num_bv_user,u.vote_user,u.nationalite_obs,u.profession_obs,u.appartenance_obs);}
		
    fclose(f);


w1=lookup_widget(objet,"affichage_user");
fenetre_afficher=create_affichage_user();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview_user");

output=lookup_widget(fenetre_afficher,"com");
if(strcmp(u.cin_user,id)!=0)
gtk_widget_show(output);
else afficher_user(treeview1,"search.txt");




}



void
on_buttonPreced_user_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonPreced_stat_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_statistiques_user;
GtkWidget *fenetre_affichage_user;
GtkWidget *treeview1;


fenetre_statistiques_user = lookup_widget(objet,"Statistiques_user");
gtk_widget_hide(fenetre_statistiques_user);

fenetre_affichage_user=lookup_widget(objet,"affichage_user");
fenetre_affichage_user=create_affichage_user();

gtk_widget_show(fenetre_affichage_user);
treeview1=lookup_widget(fenetre_affichage_user,"treeview_user");

afficher_user(treeview1,"utilisateur.txt");



}


void
on_buttonAff_stat_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *VB;
GtkWidget *TH;
GtkWidget *TF;
VB=lookup_widget(objet,"TVB");
TH=lookup_widget(objet,"TH");
TF=lookup_widget(objet,"TF");

char tph[20],tpf[20],tvb[20];
TPHF("utilisateur.txt",&h,&f);
float Tvb=TVB("utilisateur.txt");
sprintf(tph,"%.2f",h);
strcat(tph,"%");
sprintf(tpf,"%.2f",f);
strcat(tpf,"%");
sprintf(tvb,"%.2f",Tvb);
strcat(tvb,"%");
gtk_label_set_text(GTK_LABEL(VB),tvb);
//gtk_label_set_text(GTK_LABEL(TH),tph);
//gtk_label_set_text(GTK_LABEL(TF),tpf);
gtk_widget_show(TH);
gtk_widget_show(TF);

}


void
on_buttonStat_user_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affichage_user;
GtkWidget *fenetre_statistiques_user;


fenetre_affichage_user = lookup_widget(objet,"affichage_user");
gtk_widget_hide(fenetre_affichage_user);

fenetre_statistiques_user=lookup_widget(objet,"Statistiques_user");
fenetre_statistiques_user=create_Statistiques_user();
gtk_widget_show(fenetre_statistiques_user);


}

