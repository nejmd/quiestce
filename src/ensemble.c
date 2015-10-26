#include "ensemble.h"

ensemble_t ensemble_vide(void)
{
	return 0;
}

ensemble_t ensemble_plein(void)
{
	return 0b1111111111111111;
}

uint16_t ensemble_cardinal(ensemble_t e)
{
	uint16_t card = 0;
	for ( uint16_t i=0;i<16;i++){
		if (e%2 == 1) {
			card++;
		}
		e >>= 1;
	}
	return card;
}

bool ensemble_appartient(ensemble_t e, uint16_t numero_elt)
{
	return ((e >> numero_elt)%2==1);
}

ensemble_t ensemble_union(ensemble_t e1, ensemble_t e2)
{
	return e1 | e2;
}

ensemble_t ensemble_intersection(ensemble_t e1, ensemble_t e2)
{
	return e1 & e2;
}

ensemble_t ensemble_complementaire(ensemble_t e)
{
	return ~e;
}

void ensemble_ajouter_elt(ensemble_t *e, uint16_t numero_elt)
{
	*e = *e | (1 << numero_elt);
}

void ensemble_retirer_elt(ensemble_t *e, uint16_t numero_elt)
{
	*e = *e & (~(1 << numero_elt));
}

void ensemble_afficher(const char *msg, ensemble_t e)
{
	printf("%s: ",msg);
	for (int16_t i = 8*sizeof(uint16_t)-1; i >= 0 ;i--){
		if ((e >> i)%2 == 1){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
  
}

bool ensemble_inclusion(ensemble_t e1, ensemble_t e2)
{
	return ensemble_intersection(e1,e2) == e1;
}
