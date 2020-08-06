
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point_d1.h"
#include "deuxsimplex.h"



int main()

{

	double	a,b,x;


	cout << "Calcul des coordonnees barycentrique d'un point P en dimension 1.\n\nSaisie de l'intervalle [a;b] contenant P.\n\nEntrer a:	";
	cin >> a;
	cout << "Entrer b:	";
	cin >> b;
	cout << "Entrer l'abcisse x du point P:	";
	cin >> x ; "\n";

	point_d1	A(a), B(b), P(x);

	deuxsimplex	spl(&A, &B);

	if (spl.determinant_Si(1, &P)<0)	{cout << "\nP n'appartient pas a ABC.\n\n"; goto end;}
	if (spl.determinant_Si(2, &P)<0)	{cout << "\nP n'appartient pas a ABC.\n\n"; goto end;}

	cout << "Les coordonnees barycentriques de P sont:	\n";

	cout << "	zeta1=	"<<spl.determinant_Si(1, &P)/spl.determinant_S()<<"\n";
	cout << "	zeta2=	"<<spl.determinant_Si(2, &P)/spl.determinant_S()<<"\n";


end:	return 0;

}