#ifndef _3d_fem_assembly_H_
#define _3d_fem_assembly_H_


#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point.h"
#include "quatresimplex.h"
#include "3d_fem_assembly_global_vars.cpp"

/*cette fonction analyse le fichier des elements nomme elements.txt. dans ce fichier, les
elements sont specifies ligne par ligne ou separe par un caractere d'espacement c valide
selon le model x1,y1,z1,x2,y2,z2,x3,y3,z3. les espaces c valides sont autorises dans le fichier*/


	void	parser3(FILE* g_fp, int* g_parsing_flag, int* g_error_line, unsigned long long int* g_nbr_elements);

/*cette fonction recharge n elements dansla zone memoire globale des n elements a partir du
numero d'element qui lui est passe en parametre. A son retour on doit ajuster la
variable globale contenant ce numero nommee elements_memory_descriptor. En memoire, chaque
element est un ensemble ordonne de 9 doubles.*/

	void	elements_memory_charger(FILE* elements_file, double *elements_area, unsigned long long int elements_memory_descriptor, unsigned long long int n, unsigned long long int initn);

/*cette fonction recoit en parametre un numero d'element e, un entier i, un pointeur sur le
fichier des elements, un pointeur sur elements_memory, un pointeur sur 
elements_memory_descriptor, la valeur de nbredelements
et renvoit un pointeur
sur un point en dimension 3 de meme coordonnees que le point sommet de numero local i dans cet
element. le pointeur renvoye est un pointeur sur une variable globale point en dimension 3.
au prealable 4 variables globales correspondant aux differentes valeurs de i ont ete declarees
pour eviter des erreurs par exemple lors de la construction d'un trois simplex a partir de ces
4 differents points. ces variables sont temp_point1, temp_point2, temp_point3 et temp_point3.*/

	point*	local_point_sender(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, unsigned long long int e, int i);

/*cette fonction renvoit les Kije*/

		double	Kije1(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int j, unsigned long long int e);

/*cette fonction renvoit delta i,j*/

		double	dij(unsigned long long int i, unsigned long long int j);


/*cette fonction renvoit les Cije*/

		double	Cije1(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int j, unsigned long long int e);

/*cette fonction renvoit les Bie*/

		double	Bie(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int e);

/*cette fonction etablit dans un fichier une liste des points sommets des elements*/

		void	summits_file_generator (unsigned long long int* nbre_de_sommets, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, FILE* summits_file, unsigned long long* g_nbr_elements);

/*cette fonction recharge la memoire des points sommets*/

		void	summits_memory_charger(FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, unsigned long long int n, unsigned long long int initn);

//cette fonction renvoit un sommet de numero global specifie

		point*	summit_address(FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, unsigned long long int n, unsigned long long int i);

/*cette fonction renvoit sur demande avec parametres un numero global de point et un numero
d'element, le numero local dans cet element de ce point s'il y appartient et 0 sinon*/

		int	ind_loc_d1(unsigned long long int p, unsigned long long int e, FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor);

#include "3d_fem_assembly_functions.cpp"

#endif