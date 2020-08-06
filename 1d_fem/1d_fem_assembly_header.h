#ifndef _1d_fem_assembly_H_
#define _1d_fem_assembly_H_


#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point_d1.h"
#include "deuxsimplex.h"
#include "1d_fem_assembly_global_vars.cpp"

//cette function renvoit bie, elle ne depend pas de e

	double	bie_1d(unsigned long long int i, unsigned long long int e);

/*cette function renvoit la longueur d'un element Le. elle utilise une zone memoire globale
de point et sa fonction de gestion ulterieurement definie*/

	double Le1(unsigned long long int e);

//cette function renvoit Kije

	double	Kije1(unsigned long long int i, unsigned long long int j, unsigned long long int e);

//cette function renvoit Bie

	double	Bie1(unsigned long long int i, unsigned long long int e);

//cette function verifie si le fichier des points sommets des elements est bien formatte

	void	parser1(int*, unsigned long long int*);

/*cette fonction verifie si les points sommets des elements sont ordonnes dans l'ordre croissant
de leurs abscisses*/

	void	range_checker1(FILE* point_file_d1);

/*cette fonction recharge n points dansla zone memoire globale des n points a partir du
numero global de point qui lui est passe en parametre. A son retour on doit ajuster la
variable globale contenant ce numeronommee point_d1_memory_descriptor*/

	void	points_memory_charger1(FILE* point_file_d1, double* point_area_d1, unsigned long long int n, unsigned long long int initn);

/*cette fonction gere la zone memoire globale de n points et renvoit sur demande avec
parametre un numero global de point, l'adresse en memoire du point s'il y etait precharge
sinon il recharge la memoire globale des 100 points avant de renvoyer l'adresse du point.
Entre temps il ajuste le pointeur sur la zone memoire des points entre autre la variable
point_d1_memory_descriptor passee par adresse.
ici, precharged_points_flag represente un pointeur sur une variable specifiant le numero du
premier element d'un tableau defini ci-dessous.
cpf1 represente un pointeur sur le fichier contenant les abscisses, point_area_d1 represente
un tableau utilise pour precharger les abscisses et n represente le nombre d'entrees dans ce
tableau.

ces deux fonctions renvoient en effet le point de plus petite abscisse d'un element chacun dans
une variable globale differente*/

	point_d1*	point_address_d1_1(FILE* cpf1, double* point_area_d1, unsigned long long int* precharged_points_flag,  unsigned long long int i, unsigned long long int n, unsigned long long int e);
	point_d1*	point_address_d1_2(FILE* cpf1, double* point_area_d1, unsigned long long int* precharged_points_flag,  unsigned long long int i, unsigned long long int n, unsigned long long int e);

/*Ici en dimension 1, le numero d'un element sera le numero global de son sommet de plus
petit abscisse.*/


/*cette fonction gere aussi la zone memoire globale des 100 points et renvoit sur demande
avec parametres un numero global de point et un numero d'element, le numero local dans cet 
element de ce point s'il y appartient et 0 sinon*/

	int	ind_loc_d1(double i, double e);

/*cette fonction assemble les elements et sauve les Rij et Kij dans des fichiers formattes.
elle se sert d'une zone memoire pouvant contenir 100 doubles pour le stockage temporaire
en memoire des valeurs*/

	void	Kij_d1(double R2_simplex_i[nbredepoints], double Kij[nbredepoints*nbredepoints], double nbr);

/*fonction pas prete*/

		void	Rij_d1(double R2_simplex_i[nbredepoints], double Kij[nbredepoints*nbredepoints], double nbr);

/*cette fonction renvoit les Kij sans assembler les elements peut importe la complexite*/

		double	Kij_d1_2(unsigned long long int q, unsigned long long int r, unsigned long long int* nbre);

/*cette fonction impose les conditions aux limites*/

	void	boundary_conditions_d1(void);

/*cette fonction calcule les valeurs aux noeuds et les sauve dans un fichier*/

	void	points_values_d1(void);

/*ceci est une structure utilisee par la fonction qui suit pour renvoyer deux points sommets
d'un element*/

		struct struct_U_at_summits_d1
	{
		double	U_at_summit1_d1;
		double	U_at_summit2_d2;
	};

/*cette fonction gere une zone memoire globale de 100 valeurs aux noeuds et renvoit sur
demande avec parametres un numero global d'element, les valeurs respectifs aux noeuds 1er
et 2eme de cet element sous forme de la precedente structure*/

	struct_U_at_summits_d1	U_at_summits_d1(int e);

/*cette fonction renvoit la valeur de la fonction inconnue en un point d'abscisse precise*/

	double	point_value_d1(double x);

#include "1d_fem_assembly_functions.cpp"

#endif