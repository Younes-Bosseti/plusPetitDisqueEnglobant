#include <stdio.h>
#include <math.h>

#include "structures.h"

/**
 * Teste si deux cercles c1 et c2 sont égaux
**/
int estEgal( CERCLE c1, CERCLE c2 ){
    if( (c1.x == c2.x) && (c1.y == c2.y) && (c1.d == c2.d) )
        return 1;
    else
        return 0;
}

//calcule la distance entre les points a et b
double distance(POINT a, POINT b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


double calculer_determinant(POINT a, POINT b, POINT c){
	return 0;
}

//verifie si les coefficients de p dans l'espace engeindre par M sont negatifs (pour le dropping)
int coefficients_negatifs(POINT p,POINT T[], int nbPoints){

	return 0;
}

//retourne 1 si p appartient a conv(T), 0 sinon
int appartenance_conv(POINT p,POINT T[], int nbPoints){
	
	//TODO
	return 1;
}

//retourne 1 si p appartient a aff(T), 0 sinon
int appartenance_aff(POINT p,POINT T[], int nbPoints){
	
	//TODO
	return 0;
}

void dropping(POINT T[], int nbPoints){
	//TODO trouver le point q qu'on doit enlever
	POINT q;
	if(coefficients_negatifs(q, T, nbPoints)){
		//effacer point q du tableau
	}
	

}

void walking(POINT* c, POINT T[], int nbPoints){
	//TODO deplace c vers cc(T)

}


CERCLE algorithme_fischer(POINT S[], int nbPoints){

	POINT c = S[0];

	printf("in function c.x = %d c.y = %d\n", c.x, c.y); 

	POINT p; // le point le plus eloigne de c
	double max=0;
	for(int i=1; i<nbPoints;i++)
    {
    	POINT q = S[i];
    	printf("in function q.x = %d q.y = %d\n", q.x, q.y);
    	if(max < distance(c,q)){
    		max = distance(c,q);
    		p = q;
    	}
    }

	POINT T[1];
	T[0] = p;

	while(!appartenance_conv(c,T,1)){
		if(appartenance_aff(c,T,1)){
			dropping(T,1);
		}
		walking(&c, T,1);
	}

	CERCLE resultat;
	resultat.x = c.x;
	resultat.y = c.y;
	resultat.d = 2*distance(c,p);
	return resultat;
}
