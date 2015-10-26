#include "jeu.h"

void echanger (uint8_t *a, uint8_t *b)
{
	uint8_t tmp = *b;
	*b = *a;
	*a = tmp;
}

bool getReponseQuestion (question q)
{
	char saisie;
	printf("\n Est-ce que le suspect %s?\n --> ", q.msg);
	saisie=getchar();
	while(saisie == '\n'){saisie=getchar();};
	if ((saisie == 'o') || (saisie == 'n')){
		return (saisie == 'o');
	}else{
    
		printf("\n Réponse invalide! Veuillez répondre \"o\" pour Oui ou \"n\" pour Non.");
		return getReponseQuestion(q);
	}
}

int main(void)
{
	
	printf("========================================================================\nProjet Fil Rouge: Qui est-ce? - DOUMA Nejmeddine - Ensimag 1A © Mai 2015\n========================================================================\n\n\n");

	/*====================================================
	 * Création des suspects
	 *====================================================*/
	struct suspect * tabSuspects [24];
	struct liste_suspects *suspects = creer_liste_suspects();

	tabSuspects[0] = creer_suspect("André", HOMME | COIFFURE_CHAUVE | CHEVEUX_BLANCS | LUNETTES);
	tabSuspects[1] = creer_suspect("Philippe", HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | LUNETTES);
	tabSuspects[2] = creer_suspect("Jean-Louis", HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | LUNETTES);
	tabSuspects[3] = creer_suspect("François", HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | CHAPEAU);
	tabSuspects[4] = creer_suspect("Robert", HOMME | BARBE | COIFFURE_COURT | CHEVEUX_NOIRS);
	tabSuspects[5] = creer_suspect("Carole", FEMME | COIFFURE_COURT | CHEVEUX_ROUX | LUNETTES | CHAPEAU);
	tabSuspects[6] = creer_suspect("Mélanie", FEMME | COIFFURE_LONG | CHEVEUX_BLONDS );
	tabSuspects[7] = creer_suspect("Fabien", HOMME| MOUSTACHE | COIFFURE_LONG | CHEVEUX_ROUX);
	tabSuspects[8] = creer_suspect("Patricia", FEMME | COIFFURE_LONG | CHEVEUX_BLANCS );
	tabSuspects[9] = creer_suspect("Baptiste", HOMME | BARBE | MOUSTACHE | COIFFURE_CHAUVE | CHEVEUX_CHATAINS);
	tabSuspects[10] = creer_suspect("Sébastien", HOMME | COIFFURE_COURT | CHEVEUX_ROUX);
	tabSuspects[11] = creer_suspect("Olivier", HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_CHATAINS);
	tabSuspects[12] = creer_suspect("Nicolas", HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX);
	tabSuspects[13] = creer_suspect("Luc", HOMME | BARBE | COIFFURE_COURT | CHEVEUX_BLONDS);
	tabSuspects[14] = creer_suspect("Simon", HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | CHAPEAU);
	tabSuspects[15] = creer_suspect("Maxime", HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_NOIRS);
	tabSuspects[16] = creer_suspect("Cédric", HOMME | COIFFURE_CHAUVE | CHEVEUX_NOIRS | LUNETTES);
	tabSuspects[17] = creer_suspect("Pierre", HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS);
	tabSuspects[18] = creer_suspect("Martin", HOMME | COIFFURE_COURT | CHEVEUX_BLANCS);
	tabSuspects[19] = creer_suspect("Elodie", FEMME | COIFFURE_LONG | CHEVEUX_CHATAINS | CHAPEAU);
	tabSuspects[20] = creer_suspect("Victor", HOMME | BARBE | COIFFURE_CHAUVE | CHEVEUX_ROUX);
	tabSuspects[21] = creer_suspect("Georges", HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | CHAPEAU);
	tabSuspects[22] = creer_suspect("Thierry", HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_BLONDS);
	tabSuspects[23] = creer_suspect("Céline", FEMME | COIFFURE_COURT | CHEVEUX_NOIRS);

	/*====================================================
	 * Ajout des suspects à la liste
	 *====================================================*/
	for (int i = 0; i < 24; i++){
		ajouter_suspect(suspects, tabSuspects[i]);
	}
	
	
	/*====================================================
	 * Création des questions
	 *====================================================*/
	question *tabQuestions  = malloc(14*sizeof(question));

	tabQuestions[0].msg ="est un homme";
	tabQuestions[0].elimineQuestionsNon = HOMME | FEMME | MOUSTACHE | BARBE;
	tabQuestions[0].elimineQuestionsOui = HOMME | FEMME;
	tabQuestions[0].attributsOui = HOMME;
	tabQuestions[0].attributsNon = FEMME;

	tabQuestions[1].msg ="est une femme";
	tabQuestions[1].elimineQuestionsNon = FEMME | HOMME;
	tabQuestions[1].elimineQuestionsOui = FEMME | HOMME | MOUSTACHE | BARBE;
	tabQuestions[1].attributsOui = FEMME;
	tabQuestions[1].attributsNon = HOMME;

	tabQuestions[2].msg ="a une moustache";
	tabQuestions[2].elimineQuestionsNon = MOUSTACHE;
	tabQuestions[2].elimineQuestionsOui = HOMME| MOUSTACHE | FEMME;
	tabQuestions[2].attributsOui = MOUSTACHE | HOMME;
	tabQuestions[2].attributsNon = ensemble_vide();

	tabQuestions[3].msg ="a une barbe";
	tabQuestions[3].elimineQuestionsNon = BARBE;
	tabQuestions[3].elimineQuestionsOui = BARBE | FEMME | HOMME;
	tabQuestions[3].attributsOui = BARBE | HOMME;
	tabQuestions[3].attributsNon = ensemble_vide();

	tabQuestions[4].msg ="est chauve";
	tabQuestions[4].elimineQuestionsNon = COIFFURE_CHAUVE;
	tabQuestions[4].elimineQuestionsOui = COIFFURE_CHAUVE | COIFFURE_LONG | COIFFURE_COURT;
	tabQuestions[4].attributsOui = COIFFURE_CHAUVE;
	tabQuestions[4].attributsNon = ensemble_vide();

	tabQuestions[5].msg ="a des cheveux longs";
	tabQuestions[5].elimineQuestionsNon = COIFFURE_LONG;
	tabQuestions[5].elimineQuestionsOui = COIFFURE_CHAUVE | COIFFURE_LONG | COIFFURE_COURT;
	tabQuestions[5].attributsOui = COIFFURE_LONG;
	tabQuestions[5].attributsNon = ensemble_vide();

	tabQuestions[6].msg ="a des cheveux courts";
	tabQuestions[6].elimineQuestionsNon = COIFFURE_COURT;
	tabQuestions[6].elimineQuestionsOui = COIFFURE_CHAUVE | COIFFURE_LONG | COIFFURE_COURT;
	tabQuestions[6].attributsOui = COIFFURE_COURT;
	tabQuestions[6].attributsNon = ensemble_vide();

	tabQuestions[7].msg ="a des cheveux noirs";
	tabQuestions[7].elimineQuestionsNon = CHEVEUX_NOIRS ;
	tabQuestions[7].elimineQuestionsOui = CHEVEUX_NOIRS | CHEVEUX_CHATAINS | CHEVEUX_BLANCS | CHEVEUX_ROUX | CHEVEUX_BLONDS ;
	tabQuestions[7].attributsOui = CHEVEUX_NOIRS;
	tabQuestions[7].attributsNon = ensemble_vide();

	tabQuestions[8].msg ="a des cheveux châtain";
	tabQuestions[8].elimineQuestionsNon = CHEVEUX_CHATAINS ;
	tabQuestions[8].elimineQuestionsOui = CHEVEUX_NOIRS | CHEVEUX_CHATAINS | CHEVEUX_BLANCS | CHEVEUX_ROUX | CHEVEUX_BLONDS ;
	tabQuestions[8].attributsOui = CHEVEUX_CHATAINS;
	tabQuestions[8].attributsNon = ensemble_vide();

	tabQuestions[9].msg ="a des cheveux blancs";
	tabQuestions[9].elimineQuestionsNon = CHEVEUX_BLANCS ;
	tabQuestions[9].elimineQuestionsOui = CHEVEUX_NOIRS | CHEVEUX_CHATAINS | CHEVEUX_BLANCS | CHEVEUX_ROUX | CHEVEUX_BLONDS ;
	tabQuestions[9].attributsOui = CHEVEUX_BLANCS;
	tabQuestions[9].attributsNon = ensemble_vide();

	tabQuestions[10].msg ="a des cheveux roux";
	tabQuestions[10].elimineQuestionsNon = CHEVEUX_ROUX ;
	tabQuestions[10].elimineQuestionsOui = CHEVEUX_NOIRS | CHEVEUX_CHATAINS | CHEVEUX_BLANCS | CHEVEUX_ROUX | CHEVEUX_BLONDS ;
	tabQuestions[10].attributsOui = CHEVEUX_ROUX;
	tabQuestions[10].attributsNon = ensemble_vide();

	tabQuestions[11].msg ="a des cheveux blonds";
	tabQuestions[11].elimineQuestionsNon = CHEVEUX_BLONDS ;
	tabQuestions[11].elimineQuestionsOui = CHEVEUX_NOIRS | CHEVEUX_CHATAINS | CHEVEUX_BLANCS | CHEVEUX_ROUX | CHEVEUX_BLONDS ;
	tabQuestions[11].attributsOui = CHEVEUX_BLONDS;
	tabQuestions[11].attributsNon = ensemble_vide();

	tabQuestions[12].msg ="porte des lunettes";
	tabQuestions[12].elimineQuestionsNon = LUNETTES ;
	tabQuestions[12].elimineQuestionsOui = LUNETTES;
	tabQuestions[12].attributsOui = LUNETTES;
	tabQuestions[12].attributsNon = ensemble_vide();

	tabQuestions[13].msg ="porte un chapeau";
	tabQuestions[13].elimineQuestionsNon = CHAPEAU ;
	tabQuestions[13].elimineQuestionsOui = CHAPEAU;
	tabQuestions[13].attributsOui = CHAPEAU;
	tabQuestions[13].attributsNon = ensemble_vide();

	/*====================================================
	 * Création d'une permutation aléatoire des questions
	 *====================================================*/

	uint8_t permutationQuestion[14];
  
	for (uint8_t i=0;i<14;i++){
		permutationQuestion[i] = i;
	}

	srand (time(NULL));
  
	for (uint8_t i=0;i<14;i++){
		echanger(&permutationQuestion[i], &permutationQuestion[rand() % 14]);
	}
	
	
	ensemble_t questionsPosees = ensemble_vide();
	ensemble_t attributsRecherches = ensemble_vide();
  
	/*====================================================
	 * La boucle du jeu
	 *====================================================*/

	uint8_t i=0;
	// Le jeu se termine s'il toutes les question ont été posées ou s'il ne reste plus qu'un seul ou aucun suspect
	while ((suspects -> nb_suspects != 0) && (suspects -> nb_suspects != 1 ) && (i<14)){
		
		if (getReponseQuestion(tabQuestions[permutationQuestion[i]])){

			// Si l'utilisateur répond "o" à la question en cours
			attributsRecherches = ensemble_union (attributsRecherches, tabQuestions[permutationQuestion[i]].attributsOui);
			questionsPosees = ensemble_union (questionsPosees, tabQuestions[permutationQuestion[i]].elimineQuestionsOui);
		}else{

			// Si l'utilisateur répond "n" à la question en cours
			attributsRecherches = ensemble_union (attributsRecherches, tabQuestions[permutationQuestion[i]].attributsNon);
			questionsPosees = ensemble_union (questionsPosees, tabQuestions[permutationQuestion[i]].elimineQuestionsNon);
		}
		//Mise à jour de la liste des suspects
		supprimerParAttributs(suspects,attributsRecherches,questionsPosees);
		// Recherche de la question suivante à poser
		while (ensemble_appartient(questionsPosees, permutationQuestion[i])){
			i++;
		}
	}
  
 
	/*====================================================
	 * Fin du jeu
	 *====================================================*/
  
	if (suspects -> nb_suspects == 1){
		printf("Coupable trouvé! C'est: %s \n", suspects -> tete -> nom);
	} else {
		printf("Aucun suspect ne correspond à vos réponses. \n");
	}
	
	// Libération de la mémoire
	detruire_liste_suspects(&suspects);

	return 0;
}
