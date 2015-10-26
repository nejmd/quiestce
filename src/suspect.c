#include "suspect.h"

struct suspect *creer_suspect(const char *name, ensemble_t attributs) {
	if (name != NULL){
		struct suspect* s = malloc(sizeof(struct suspect));
		s -> nom = malloc(sizeof(name));
		strcpy(s->nom,name);
		s -> attributs = attributs;
		s -> suiv = NULL;
		s -> prec = NULL;
		return s;
	}else{
		return 0;
	}
}

struct liste_suspects *creer_liste_suspects(void) {
	struct liste_suspects* l = malloc(sizeof(struct liste_suspects));
	l -> nb_suspects = 0;
	l -> tete = NULL;
	l -> queue = NULL;
	return l;
}

void detruire_liste_suspects(struct liste_suspects **l)
{
	if (*l != NULL){
		struct suspect *suspect_tmp = (*l)-> tete;

		// On parcout la liste en enlevant les suspects un par un
		while (suspect_tmp != NULL){
			struct suspect *suspect_tmp_suiv = suspect_tmp -> suiv;
			free(suspect_tmp -> nom);
			free(suspect_tmp);
			suspect_tmp = suspect_tmp_suiv;
		}
		free(*l);
		*l = NULL;
	}
}

void ajouter_suspect(struct liste_suspects *liste, struct suspect *suspect)
{
	if (suspect != NULL){
		suspect -> suiv = NULL;
		suspect -> prec = liste -> queue;
		if (liste -> queue != NULL){
			liste -> queue -> suiv = suspect;
		}
		liste -> queue = suspect;
		if (liste -> tete == NULL){
			liste -> tete = suspect;
		}
		liste -> nb_suspects++;
	}
}

void retirer_suspect(struct liste_suspects *liste, struct suspect *suspect)
{
	if(suspect != NULL){
		if ( suspect -> suiv != NULL ){
			suspect -> suiv -> prec = suspect -> prec;
		}
  
		if (suspect -> prec != NULL){
			suspect -> prec -> suiv = suspect -> suiv;
		}

		if (liste -> tete == suspect){
			liste -> tete = suspect -> suiv;
		}

		if (liste -> queue == suspect){
			liste -> queue = suspect -> prec;
		}

		liste -> nb_suspects--;
		free(suspect -> nom);
		free(suspect);
	}
}

void affiche_liste_suspects(struct liste_suspects *l)
{
	if (l != NULL){
		printf("Nombre des suspects: %d \n",l -> nb_suspects);
		struct suspect *suspect_tmp = l -> tete;
		while (suspect_tmp != NULL){
			char msg[256]; 
			strcpy(msg," --> ");
			strcat(msg, suspect_tmp->nom);
			ensemble_afficher(msg,suspect_tmp -> attributs);
			suspect_tmp = suspect_tmp -> suiv;
		}
		printf("\n");
	}
}

void supprimerParAttributs(struct liste_suspects *l,ensemble_t attributsRecherches,ensemble_t questionsPosees)
{
	if (l != NULL){
		struct suspect *suspect_tmp = l -> tete;
		// On parcourt la liste et on retire les suspects qui n'ont pas les attributs recherchés
		while (suspect_tmp != NULL){
			struct suspect *suspect_tmp_suiv = suspect_tmp -> suiv; 
			if (ensemble_intersection(questionsPosees,attributsRecherches) != ensemble_intersection(questionsPosees,suspect_tmp -> attributs)){
				retirer_suspect(l, suspect_tmp);
			}
			suspect_tmp = suspect_tmp_suiv;
		}
    
	}
}


