#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"


int ET=0;
int OU =0;
utilisateur userDeleted;


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






//checkbox

//radio button







ajout_user("utilisateur.txt",u,ET,OU);


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

utilisateur user;
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


nom=lookup_widget(objet,"entryNom_user");
prenom=lookup_widget(objet,"entryPrenom_user");
jour=lookup_widget(objet,"spinbuttonJour_user");
mois=lookup_widget(objet,"spinbuttonMois_user");
annee=lookup_widget(objet,"spinbuttonAnnee_user");
cin=lookup_widget(objet,"entryCin_user");
role=lookup_widget(objet,"comboboxRole_user");
num=lookup_widget(objet,"spinbuttonNumBV_user");
vote=lookup_widget(objet,"spinbuttonVote_user");
profession=lookup_widget(objet,"entryProf_user");
appartenance=lookup_widget(objet,"comboboxApp_user");





strcpy(user.nom_user,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(user.prenom_user,gtk_entry_get_text(GTK_ENTRY(prenom)));
user.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
user.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
user.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(user.cin_user,gtk_entry_get_text(GTK_ENTRY(cin)));

strcpy(user.role_user,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));

user.num_bv_user=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num));
user.vote_user=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vote));
strcpy(user.profession_obs,gtk_entry_get_text(GTK_ENTRY(profession)));
strcpy(user.appartenance_obs,gtk_combo_box_get_active_text(GTK_COMBO_BOX(appartenance)));











modifier_user("utilisateur.txt",userDeleted.cin_user,user,ET,OU);




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
on_buttonEnregistrer_user_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonRechercher_user_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview1;

GtkWidget  *id_entry;
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
afficher_user(treeview1,"search.txt");




}

