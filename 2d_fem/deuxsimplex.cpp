#include "point_d1.h"

//implantation des méthodes

/* Constructeur */
deuxsimplex::deuxsimplex(point_d1 *a1, point_d1 *a2 )
{
P1=a1; P2=a2;

	if (((*P2).abscisse()-(*P1).abscisse())<0)
		{temp=P2; P2=P1; P1=temp;}
}


/* determinant_S */
double deuxsimplex::determinant_S(void)
{
	return ((*P2).abscisse()-(*P1).abscisse());
}


/* determinant_Si */
double deuxsimplex::determinant_Si(int i, point_d1 *P3 )
{
	switch (i)
	{
	case 1:
		return ((*P2).abscisse()-(*P3).abscisse());
	break;

	case 2:
		return ((*P3).abscisse()-(*P1).abscisse());
	break;
	}
}


/* Destructeur */
deuxsimplex::~deuxsimplex()
{
// Rien a faire de special !
}
