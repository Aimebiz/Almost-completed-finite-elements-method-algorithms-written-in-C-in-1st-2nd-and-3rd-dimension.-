
#ifndef _TROISSIMPLEX_H_
#define _TROISSIMPLEX_H_

#include "point.h"


class quatresimplex

{

// Methodes utilisateurs
public:

//déclaration Constructeur, destructeur
	quatresimplex(point *a1, point *a2, point *a3, point *a4);
	~quatresimplex();

//déclaration des méthodes
	double	determinant_S(void);
	double	determinant_Si(int i, point *P5);
	double	bi(int i);
	double	ci(int i);
	double	di(int i);

// Attributs implantation
	private:
		point	*P1,*P2,*P3,*P4,*temp;


};

#include "quatresimplex.cpp"


#endif