#ifndef _TP1_H
#define _TP1_H
#define TAILLE 10


typedef struct t_Date{
	int annee;
	int mois;
	int jour;
} t_Date;


typedef struct t_Identite{

	char nom[TAILLE];
	char prenom[TAILLE];
} t_Identite;

typedef struct t_Adresse{
	int code_postal;
	char ville[TAILLE];
} t_Adresse;

typedef struct t_Eleve{
	t_Identite id;
	t_Date naiss;
} t_Eleve;

typedef struct Annuaire{
	t_Eleve liste[TAILLE];
	int cpt;
} Annuaire;

int cmp_dates(t_Date, t_Date);
int cmp_identites(t_Identite, t_Identite);
int cmp_adresses(t_Adresse, t_Adresse);
char * nom_jour(t_Date);
t_Eleve* saisie_eleve(t_Identite, t_Date);
void afficher_eleve(t_Eleve *);
int cherche_eleve(char *, Annuaire *);
int anniversaires(t_Date, Annuaire *);


void print_message(char*);
int calcule(int, int, char);
int nb_partition(int, int);
void print_int_tab(int *, int);
void print_char_tab(char *, int);
void print_string(char*);
int est_bissextile(t_Date);
int nb_jour_par_an(t_Date);
char * nom_jour(t_Date);
#endif
