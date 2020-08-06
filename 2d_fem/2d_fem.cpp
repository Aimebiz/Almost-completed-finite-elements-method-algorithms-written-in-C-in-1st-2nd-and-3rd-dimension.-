
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point_d2.h"
#include "troissimplex.h"



int main()

{

	double	Px,Py,Ax,Ay,Bx,By,Cx,Cy ;


	cout << "Calcul des coordonnees barycentriques d'un point P en dimension 2.\n\nSaisie des points A, B et C encadrant P.\n\nEntree du point A:\n	abscisse:	";
	cin >> Ax;
	cout << "	ordonnee:	";
	cin >> Ay;

	cout << "Entree du point B:\n";
	cout << "	abscisse:	";
	cin >> Bx;
	cout << "	ordonnee:	";
	cin >> By;

	cout << "Entree du point C:\n";
	cout << "	abscisse:	";
	cin >> Cx;
	cout << "	ordonnee:	";
	cin >> Cy;

	cout << "Entree du point P:\n";
	cout << "	abscisse:	";
	cin >> Px;
	cout << "	ordonnee:	";
	cin >> Py;

	point_d2	P(Px,Py),A(Ax,Ay),B(Bx,By),C(Cx,Cy);
	troissimplex	spl(&A, &B, &C);

	if (spl.determinant_Si(1, &P)<0)
		{cout << "P n'appartient pas a ABC"; goto end;}
	else if (spl.determinant_Si(2, &P)<0)
		{cout << "P n'appartient pas a ABC"; goto end;}
	else
		{ if (spl.determinant_Si(3, &P)<0) {cout << "P n'appartient pas a ABC"; goto end;}}


	cout << "Les coordonnees barycentriques de P sont:	\n";

	cout << "	zeta1=	"<<spl.determinant_Si(1, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta2=	"<<spl.determinant_Si(2, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta3=	"<<spl.determinant_Si(3, &P)/spl.determinant_S()<<"\n";


end:	return 0;

}