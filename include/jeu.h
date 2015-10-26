#ifndef JEU_H
#define JEU_H

#include <strings.h>
#include <time.h>
#include <stdio.h>
#include "suspect.h"
#include "ensemble.h"


typedef struct question{
	char *msg;
	ensemble_t attributsOui,attributsNon; // Les attributs à considérer si la réponse à la question est "oui" ou "non"
	ensemble_t elimineQuestionsOui,elimineQuestionsNon; // Les questions à éliminer si la réponse à la question est "oui" ou "non"
}question;

// Echanger deux pointeurs
extern void echanger (uint8_t *a, uint8_t *b);

// Pose la question q à l'utilisateur et renvoie sa réponse: True pour "o" et False pour "n"
extern bool getReponseQuestion (question q);

#endif /* JEU_H */
