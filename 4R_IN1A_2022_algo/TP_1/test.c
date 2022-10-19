#include "tp1.h"
#include <stdio.h>

int main(int argc, char * argv[]){
      int i, j;
        char r;

        if(argc==2){
                sscanf(argv[1], "%d %c %d", &i, &r, &j);
                printf("%d\n", calcule(i,j,r));
                return 0;

        }else if(argc > 2 || argc < 4){
                if(sscanf(argv[1]," %d", &i) != 1){
                        printf("erreur - le premier arg n'est pas un chiffre\n");
                        return 0;
                }
                else if(sscanf(argv[2]," %d", &j) != 1){
                        printf("erreur - le deuxieme arg n'est pas un chiffre\n");
                        return 0;
                }
                else if(sscanf(argv[3]," %c", &r) != 1){
                        printf("erreur - le troisieme arg n'est pas un operande\n");
                        return 0;
                }
                sscanf(argv[2]," %d", &j);
                sscanf(argv[3]," %c", &r);
                printf("retour : %d \n", calcule(i, j,r));
                return 0;
        }
        else{
                printf("Je manque d'information\n");
                return 0;
        }



int tab_i[] = {5,9,7};
char tab_c[] = {'a','b','c'};
char *tab= "bur";
print_int_tab(tab_i, 3);
print_char_tab(tab_c, 3);
print_string(tab);

t_Date moi = { 2028,05,18 };
t_Date pas_moi = {2028,05,5};

t_Identite id1 = { "Pierre", "Berne"};
t_Identite id2 = { "Louis", "Bernfe"};
t_Identite id3 = { "Jean", "Bert"};
t_Identite id4 = { "Bidule", "net"};

Annuaire esiee = { { NULL }, 0 };	

t_Eleve *eleve1 = saisie_eleve(id1, moi);
t_Eleve *eleve2 = saisie_eleve(id2, pas_moi);
t_Eleve *eleve3 = saisie_eleve(id3, pas_moi);
t_Eleve *eleve4 = saisie_eleve(id4, moi);

esiee.liste[0] = *eleve1; esiee.cpt+=1;
esiee.liste[esiee.cpt] = *eleve2; esiee.cpt+=1;
esiee.liste[esiee.cpt] = *eleve3; esiee.cpt+=1;
esiee.liste[esiee.cpt] = *eleve4; esiee.cpt+=1;
int i = 0;
while (i < esiee.cpt){
	printf("---\n Eleve no%d\n",i);
	afficher_eleve(&esiee.liste[i]);
	printf("\n");
	i++;
}

printf("Eleve %s present au no %d\n", eleve3->id.nom, cherche_eleve("Jean", &esiee));
printf("Il y a %d eleves nes le %d/%d/%d", anniversaires(moi, &esiee), moi.annee, moi.mois, moi.jour);

return 0;
}

