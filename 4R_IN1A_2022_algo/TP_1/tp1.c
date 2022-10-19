#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include <string.h>
/
void print_message(char* message){
        printf("%s\n", message);
}

int calcule(int a, int b, char op){
        char def;
        switch (op) {
                case '+':
                        return a+b;
                        break;
                case '-':
                        return a-b;
                        break;
                case '/' :
                        return a/b;
                        break;
                case 'x':
                        return a*b;
                        break;
                default:
                        printf("Operande inconnu, taper nouvel operande:\n");
                        scanf("%c", &def);
                        calcule(a,b,def);

        }
}

int nb_partition(int n, int t){

        if(n == 0) return 1;
        if(n < 0) return 0;
        if(n > 0 && t == 1) return 1;
        if(n > 0 && t > 1){
                return nb_partition(n-t, t) + nb_partition(n, t-1);
        }
}

void print_int_tab(int * tab, int size){
        int i = 0;
        for(;i<size; i++){
                printf("%d\n",*(tab+i));
        }
}

void print_char_tab(char * tab, int size){
        int i = 0;
        for(;i<size; i++){
                printf("%c\n",*(tab+i));
        }
}

void print_string(char* tab){
        printf("%s\n", tab);
}


int est_bissextile(t_Date d1){
        /**condition d'une annee bissextile selon Wikipedia : **/
        if((d1.annee % 4 == 0  && d1.annee % 100 != 0) || (d1.annee % 400 == 0)) return 1;
        return 0;
}
int nb_jour_par_an(t_Date d1){
        return 365+ est_bissextile(d1);
}
int nb_jours_par_mois(t_Date d1){
        if(d1.mois <= 0 || d1.mois > 12){ return -1; }
        else if(d1.mois == 1 || d1.mois == 3 || d1.mois == 5 || d1.mois ==  7 || d1.mois == 8 || d1.mois ==  10 || d1.mois ==  12 ){ return 31; }
        return 30;
}

char * nom_jour(t_Date d1){
	char * jour;
	jour = malloc(10*sizeof(char));
        /** D'après l'algorithme de Mike Keith **/
        char * lundi = "lundi", *mardi = "mardi", *mercredi = "mercredi", *jeudi = "jeudi", *vendredi = "vendredi", *samedi = "samedi", *dimanche= "dimanche";
        int day = (d1.jour+=d1.mois<3?d1.annee--:d1.annee-2,23*d1.mois/9+d1.jour+4+d1.annee/4-d1.annee/100+d1.annee/400)%7;
        if(day == 0) strcpy(jour,dimanche);
        else if(day == 1) strcpy(jour,lundi);
        else if (day == 2) strcpy(jour,mardi);
        else if (day == 3) strcpy(jour,mercredi);
        else if (day == 4) strcpy(jour, jeudi);
        else if (day == 5) strcpy(jour,vendredi);
        else if (day == 6) strcpy(jour,samedi);
	return jour;
}


int cmp_dates(t_Date d1, t_Date d2){

	if( d1.mois == d2.mois && d1.annee == d2.annee && d1.jour == d2.jour) return 0;
	return d1.jour - d2.jour;
}

int cmp_identites(t_Identite id1, t_Identite id2){
	if(strcmp(id1.nom,id2.nom)==0 && strcmp(id1.prenom, id2.prenom)==0) return 0;
	return strcmp(id1.nom,id2.nom) + strcmp(id1.prenom, id2.prenom);
}
int cmp_adresses(t_Adresse ad1, t_Adresse ad2){
	if(strcmp(ad1.ville,ad2.ville)==0 && ad1.code_postal==ad2.code_postal) return 0;
	return ad1.code_postal - ad2.code_postal;
}

t_Eleve* saisie_eleve(t_Identite id, t_Date naiss){
	t_Eleve *eleve; 
	eleve = (t_Eleve*) malloc(sizeof(t_Eleve));
	eleve->id = id;
	eleve->naiss = naiss;
	return eleve;
}
void afficher_eleve(t_Eleve * e){
	printf("Date : jour : %d\n",e->naiss.jour);
	printf("Date : mois : %d\n",e->naiss.mois);
	printf("Date : annee : %d\n",e->naiss.annee);
	printf("Id : prenom : %s\n",e->id.nom);
	printf("Id : nom : %s\n",e->id.prenom);
}

int cherche_eleve(char * nom, Annuaire * annuaire){
	int i =0;
	while(i < annuaire->cpt){
		if(strcmp(nom, annuaire->liste[i].id.nom) == 0){
			return i;
		}
		i++;
	}
	return -1;
}

int anniversaires(t_Date d1, Annuaire * annuaire){
	int ret=0, i=0;
	
	while(i < annuaire->cpt){
		if(cmp_dates(d1, annuaire->liste[i].naiss) == 0){
			ret+=1;
		}
		i++;
	}
	return ret;
}

