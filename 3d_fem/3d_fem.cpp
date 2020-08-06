
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point.h"
#include "quatresimplex.h"



int main()

{

	double	Px,Py,Pz,Ax,Ay,Az,Bx,By,Bz,Cx,Cy,Cz,Dx,Dy,Dz ;


	cout << "Calcul des coordonnees barycentrique d'un point P en dimension 3.\n\nSaisie des points A, B, C et D encadrant P.\n\nEntree du point A:\n	abscisse:	";
	cin >> Ax;
	cout << "	ordonnee:	";
	cin >> Ay;
	cout << "	cote:		";
	cin >> Az;

	cout << "Entree du point B:\n";
	cout << "	abscisse:	";
	cin >> Bx;
	cout << "	ordonnee:	";
	cin >> By;
	cout << "	cote:		";
	cin >> Bz;

	cout << "Entree du point C:\n";
	cout << "	abscisse:	";
	cin >> Cx;
	cout << "	ordonnee:	";
	cin >> Cy;
	cout << "	cote:		";
	cin >> Cz;

	cout << "Entree du point D:\n";
	cout << "	abscisse:	";
	cin >> Dx;
	cout << "	ordonnee:	";
	cin >> Dy;
	cout << "	cote:		";
	cin >> Dz;

	cout << "Entree du point P:\n";
	cout << "	abscisse:	";
	cin >> Px;
	cout << "	ordonnee:	";
	cin >> Py;
	cout << "	cote:		";
	cin >> Pz;

	point	P(Px,Py,Pz),A(Ax,Ay,Az),B(Bx,By,Bz),C(Cx,Cy,Cz),D(Dx,Dy,Dz);

	quatresimplex	spl(&A, &B, &C, &D);


	if (spl.determinant_Si(1, &P)<0)
		{cout << "P n'appartient pas a ABCD"; goto end;}
	else if (spl.determinant_Si(2, &P)<0)
		{cout << "P n'appartient pas a ABCD"; goto end;}
	else if (spl.determinant_Si(3, &P)<0)
		{cout << "P n'appartient pas a ABCD"; goto end;}
	else
		{ if (spl.determinant_Si(4, &P)<0) {cout << "P n'appartient pas a ABCD"; goto end;}}
	

	cout << "Les coordonnees barycentrique de P sont:	\n";

	cout << "	zeta1=	"<<spl.determinant_Si(1, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta2=	"<<spl.determinant_Si(2, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta3=	"<<spl.determinant_Si(3, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta4=	"<<spl.determinant_Si(4, &P)/spl.determinant_S()<<"\n";

	//cout << "	det(S)=	"<<spl.determinant_S()<<"\n";


end:	return 0;

}