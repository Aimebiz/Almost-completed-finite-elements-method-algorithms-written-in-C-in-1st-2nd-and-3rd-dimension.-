
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point_d1.h"
#include "deuxsimplex.h"
#include "1d_fem_assembly_global_vars.cpp"
#include "1d_fem_assembly_header.h"



int main()

{

//verifier le fichier des points
	parser1(&temp_d1_1, &nbr_pts_d1);

	if (temp_d1_1==0)
		{cout<<"Erreur le fichier points_sommets_d1.txt est introuvable."; goto end;}
	if (temp_d1_1==3)
		{cout<<"Erreur dans le fichier points_sommets_d1.txt a partir de l'entree numero "<<nbr_pts_d1<<"."; goto end;}

cout<<"\n";
cout<<"Le nombre de points entres est "<<nbr_pts_d1<<".\n\n";

//verifier que le fichier des points est range dans l'ordre croissant des abscisses
	FILE* points_sommets_d1_fp;
	points_sommets_d1_fp = fopen("points_sommets_d1.txt","r");
	temp_d1_1=3;
	range_checker1(points_sommets_d1_fp, &temp_d1_1);

	if (temp_d1_1==0)
		{cout<<"Erreur les elements du fichier points_sommets_d1.txt sont mal ordonnes."; goto end;}
	if (temp_d1_1==1)
		{cout<<"Erreur sur le nomnbre de points dans le fichier points_sommets_d1.txt."; goto end;}
	if (temp_d1_1==2)
		{cout<<"Erreur aucun point n'a ete entre dans le fichier points_sommets_d1.txt."; goto end;}
	fclose(points_sommets_d1_fp);

//charger nbredepoints points en memoire

	points_sommets_d1_fp = fopen(pointsfile,"r");

	gfp=points_sommets_d1_fp;

	points_memory_charger1(points_sommets_d1_fp,points_memory, nbredepoints, 1);

	point_d1_memory_descriptor=1;

	fclose(points_sommets_d1_fp);

cout<<"\n";
cout<<"Les abscisses entrees sont:"<<"\n\n";

	points_sommets_d1_fp = fopen(pointsfile,"r");


	for (i=0; i<=(nbr_pts_d1 - 1); i=i+1)
	{
		if ((i+1)>(point_d1_memory_descriptor-1) && (i+1)<=nbredepoints) {cout<<points_memory[i]<<"\n";}
		else {
			fclose(points_sommets_d1_fp);
			points_sommets_d1_fp = fopen(pointsfile,"r");
			o=o+1;
			points_memory_charger1(points_sommets_d1_fp,points_memory, nbredepoints, o*nbredepoints+1);
			for (p=0; p<=nbredepoints-1; p=p+1)
			{if (o*nbredepoints+1+p<=nbr_pts_d1) {cout<<points_memory[p]<<"\n";}}
			point_d1_memory_descriptor=point_d1_memory_descriptor+o*nbredepoints;
			i=o*nbredepoints;
			fclose(points_sommets_d1_fp);
			}
	}


cout<<"\n\n\n";

cout<<"Les bie sont:\n\n";

cout<<"bie1 = "<<bie_1d(1,1)<<"\n";
cout<<"bie2 = "<<bie_1d(2,1)<<"\n\n\n";

cout<<"Les Le sont:\n\n";

	for (double i=1; i!=nbr_pts_d1; i=i+1)
	{
		cout<<"Le"<<i<<" = "<<Le1(i)<<"\n";
	}
cout<<"\n\n\n";

cout<<"Les Kije sont:\n\n";

for (double e=1; e!=nbr_pts_d1; e=e+1)
{
	m = e;
	for (double i=1; i<=2; i=i+1)
	{
		k = i;
		for (double j=1; j<=2; j=j+1)
		{
			l = j;
			cout<<"K"<<i<<","<<j<<","<<e<<" = "<<Kije1(k,l,m)<<"\n";
		}
	}
	cout<<"\n";
}
cout<<"\n\n\n";

//assembler les elements


/*	j'ai laisse tomber cette fonction pour une autre Kij_d1_2

	Kij_d1(R2_simplex_i, Kij, nbr_pts_d1);

cout<<"Les Kij sont:\n\n";

	for (double i=1; i<=nbr_pts_d1; i=i+1)
	{
		k = i;
		for (double j=1; j<=nbr_pts_d1; j=j+1)
		{
			l = j;
			cout<<"K"<<i<<","<<j<<" = "<<Kij[(k-1)*nbredepoints+l-1]<<"\n";
			if (j==nbr_pts_d1) {cout<<"\n";}
		}
	}
cout<<"\n\n\n";

*/


cout<<"Les Kij sont:\n\n";

	for (unsigned long long int i=1; i<=nbr_pts_d1; i=i+1)
	{
		for (unsigned long long int j=1; j<=nbr_pts_d1; j=j+1)
		{
			cout<<"K"<<i<<","<<j<<" = "<<Kij_d1_2(i, j, &nbr_pts_d1)<<"\n";
			if (j==nbr_pts_d1) {cout<<"\n";}
		}
	}


//imposer les conditions aux limites aux fichiers des Kij et Rij
	boundary_conditions_d1();
//calculer les valeurs aux noeuds en les sauvant dans un fichier
	points_values_d1();
//renvoyer en exemple la valeur de la fonction inconnue au noeud 2

//cout<<point_value_d1(2);


end:	return 0;

}