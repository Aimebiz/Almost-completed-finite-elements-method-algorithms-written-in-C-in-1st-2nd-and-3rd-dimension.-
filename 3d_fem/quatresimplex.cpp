#include "point.h"

//implantation des méthodes

/* Constructeur */
quatresimplex::quatresimplex(point *a1, point *a2, point *a3, point *a4 )
{
P1=a1; P2=a2; P3=a3; P4=a4;

	if ((((*P2).abscisse()-(*P1).abscisse())*(((*P3).ordonnee()-(*P1).ordonnee())*((*P4).cote()-(*P1).cote())-((*P4).ordonnee()-(*P1).ordonnee())*((*P3).cote()-(*P1).cote()))-((*P2).ordonnee()-(*P1).ordonnee())*(((*P3).abscisse()-(*P1).abscisse())*((*P4).cote()-(*P1).cote())-((*P4).abscisse()-(*P1).abscisse())*((*P3).cote()-(*P1).cote()))+((*P2).cote()-(*P1).cote())*(((*P3).abscisse()-(*P1).abscisse())*((*P4).ordonnee()-(*P1).ordonnee())-((*P4).abscisse()-(*P1).abscisse())*((*P3).ordonnee()-(*P1).ordonnee())))<0)
		{temp=P4; P4=P3; P3=temp;}

}


/* determinant_S */
double quatresimplex::determinant_S(void)
{
	return (((*P2).abscisse()-(*P1).abscisse())*(((*P3).ordonnee()-(*P1).ordonnee())*((*P4).cote()-(*P1).cote())-((*P4).ordonnee()-(*P1).ordonnee())*((*P3).cote()-(*P1).cote()))-((*P2).ordonnee()-(*P1).ordonnee())*(((*P3).abscisse()-(*P1).abscisse())*((*P4).cote()-(*P1).cote())-((*P4).abscisse()-(*P1).abscisse())*((*P3).cote()-(*P1).cote()))+((*P2).cote()-(*P1).cote())*(((*P3).abscisse()-(*P1).abscisse())*((*P4).ordonnee()-(*P1).ordonnee())-((*P4).abscisse()-(*P1).abscisse())*((*P3).ordonnee()-(*P1).ordonnee())));
}


/* determinant_Si */
double quatresimplex::determinant_Si(int i, point *P5 )
{
	switch (i)
	{
	case 1:
		return (((*P2).abscisse()-(*P5).abscisse())*(((*P3).ordonnee()-(*P5).ordonnee())*((*P4).cote()-(*P5).cote())-((*P4).ordonnee()-(*P5).ordonnee())*((*P3).cote()-(*P5).cote()))-((*P2).ordonnee()-(*P5).ordonnee())*(((*P3).abscisse()-(*P5).abscisse())*((*P4).cote()-(*P5).cote())-((*P4).abscisse()-(*P5).abscisse())*((*P3).cote()-(*P5).cote()))+((*P2).cote()-(*P5).cote())*(((*P3).abscisse()-(*P5).abscisse())*((*P4).ordonnee()-(*P5).ordonnee())-((*P4).abscisse()-(*P5).abscisse())*((*P3).ordonnee()-(*P5).ordonnee())));
	break;

	case 2:
		return -(((*P3).abscisse()-(*P5).abscisse())*(((*P4).ordonnee()-(*P5).ordonnee())*((*P1).cote()-(*P5).cote())-((*P1).ordonnee()-(*P5).ordonnee())*((*P4).cote()-(*P5).cote()))-((*P3).ordonnee()-(*P5).ordonnee())*(((*P4).abscisse()-(*P5).abscisse())*((*P1).cote()-(*P5).cote())-((*P1).abscisse()-(*P5).abscisse())*((*P4).cote()-(*P5).cote()))+((*P3).cote()-(*P5).cote())*(((*P4).abscisse()-(*P5).abscisse())*((*P1).ordonnee()-(*P5).ordonnee())-((*P1).abscisse()-(*P5).abscisse())*((*P4).ordonnee()-(*P5).ordonnee())));
	break;

	case 3:
		return (((*P4).abscisse()-(*P5).abscisse())*(((*P1).ordonnee()-(*P5).ordonnee())*((*P2).cote()-(*P5).cote())-((*P2).ordonnee()-(*P5).ordonnee())*((*P1).cote()-(*P5).cote()))-((*P4).ordonnee()-(*P5).ordonnee())*(((*P1).abscisse()-(*P5).abscisse())*((*P2).cote()-(*P5).cote())-((*P2).abscisse()-(*P5).abscisse())*((*P1).cote()-(*P5).cote()))+((*P4).cote()-(*P5).cote())*(((*P1).abscisse()-(*P5).abscisse())*((*P2).ordonnee()-(*P5).ordonnee())-((*P2).abscisse()-(*P5).abscisse())*((*P1).ordonnee()-(*P5).ordonnee())));
	break;
	case 4:
		return -(((*P1).abscisse()-(*P5).abscisse())*(((*P2).ordonnee()-(*P5).ordonnee())*((*P3).cote()-(*P5).cote())-((*P3).ordonnee()-(*P5).ordonnee())*((*P2).cote()-(*P5).cote()))-((*P1).ordonnee()-(*P5).ordonnee())*(((*P2).abscisse()-(*P5).abscisse())*((*P3).cote()-(*P5).cote())-((*P3).abscisse()-(*P5).abscisse())*((*P2).cote()-(*P5).cote()))+((*P1).cote()-(*P5).cote())*(((*P2).abscisse()-(*P5).abscisse())*((*P3).ordonnee()-(*P5).ordonnee())-((*P3).abscisse()-(*P5).abscisse())*((*P2).ordonnee()-(*P5).ordonnee())));
	break;
	}
}


/* Destructeur */
quatresimplex::~quatresimplex()
{
// Rien a faire de special !
}


double	quatresimplex::bi(int i)
{
if (i==1) {return (*P2).ordonnee()-(*P3).ordonnee();}
else if (i==2) {return (*P3).ordonnee()-(*P1).ordonnee();}
else if (i==3) {return (*P1).ordonnee()-(*P2).ordonnee();}
else {}
}


double	quatresimplex::ci(int i)
{
if (i==1) {return (*P3).abscisse()-(*P2).abscisse();}
else if (i==2) {return (*P1).abscisse()-(*P3).abscisse();}
else if (i==3) {return (*P2).abscisse()-(*P1).abscisse();}
else {}
}


double	quatresimplex::di(int i)
{
if (i==1) {return (*P3).abscisse()-(*P2).abscisse();}
else if (i==2) {return (*P1).abscisse()-(*P3).abscisse();}
else if (i==3) {return (*P2).abscisse()-(*P1).abscisse();}
else {}
}