
#ifndef _DEUXSIMPLEX_H_
#define _DEUXSIMPLEX_H_

#include "point_d1.h"


class deuxsimplex

{

// Methodes utilisateurs
public:

//d�claration Constructeur, destructeur
	deuxsimplex(point_d1 *a1, point_d1 *a2);
	~deuxsimplex();

//d�claration des m�thodes
	double	determinant_S(void);
	double	determinant_Si(int i, point_d1 *P3);

// Attributs implantation
	private:
		point_d1	*P1,*P2,*temp;


};

#include "deuxsimplex.cpp"


#endif