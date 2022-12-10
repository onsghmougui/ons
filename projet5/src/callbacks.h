#include <gtk/gtk.h>


void
on_entryProf_user_activate             (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_radiobuttonFemme_user_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonHomme_user_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonEtranger_user_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonTun_user_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_comboboxApp_user_move_active        (GtkComboBox     *combobox,
                                        GtkScrollType    arg1,
                                        gpointer         user_data);

void
on_buttonAfficher_user_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonValider_user_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_user_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonAjouter_user_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonModifier_user_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonSupprimer_user_clicked        (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonEnregistrer_user_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercher_user_clicked       (GtkButton       *objet,
                                        gpointer         user_data);
