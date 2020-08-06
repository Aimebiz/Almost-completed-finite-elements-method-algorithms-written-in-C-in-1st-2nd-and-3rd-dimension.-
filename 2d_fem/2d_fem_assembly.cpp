
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point_d2.h"
#include "troissimplex.h"
#include "2d_fem_assembly_global_vars.cpp"
#include "2d_fem_assembly_header.h"



int main()

{



//for (int i=0; i<256; i=i+1) {printf("%c",i); cout<<"	"<<i<<"\n";}

	g_fp = fopen("elements.txt","r");

	if (g_fp==0)
		{cout<<"Erreur le fichier elements.txt est introuvable."; goto end;}

//verifier le formatage du fichier elements.txt

	parser2(g_fp, &g_parsing_flag, &g_error_line, &g_nbr_elements);

	if (g_parsing_flag==1)
		{cout<<"Erreur dans le fichier elements.txt dans l'entree numero "<<g_error_line<<"."; goto end;}

	if (g_nbr_elements==0)
		{cout<<"Erreur le fichier elements.txt ne contient pas d'element."; goto end;}


	cout<<"Le nombre d'elements entres est "<<g_nbr_elements<<" .";
	cout<<"\n\n";


	if (g_nbr_elements<=nbredelements)
		{elements_memory_charger(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 1);}
	else
		{elements_memory_charger(g_fp, elements_memory, &elements_memory_descriptor, nbredelements, 1); flag=1;}

//cout<<"\n"<<elements_memory_descriptor<<"\n";

	//for (int i=0; i<=17; i=i+1) {cout<<elements_memory[i]<<"\n";}

// test de local_point_sender()

	if (g_nbr_elements<=nbredelements)
		{pointtest = *local_point_sender(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 3, 2);}
	else
		{pointtest = *local_point_sender(g_fp, elements_memory, &elements_memory_descriptor, nbredelements, 2, 2);}

	pointtest = *local_point_sender(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 1, 1);
	cout<<pointtest.abscisse()<<" , "<<pointtest.ordonnee()<<"\n";


// test de Kije()

	cout<<"K123 = "<<Kije(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 1, 2, 3)<<"\n";

//generer le fichier des points sommets
	//remove("summits.txt");
	summitsfp = fopen("summits.txt","w+");
	summits_file_generator (&nbre_de_sommets, g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, summitsfp, &g_nbr_elements);


cout<<"Le nombre de points sommets est "<<nbre_de_sommets<<".\n";

//charger des points sommets en memoire
	summits_memory_charger(summitsfp, summits_memory, &summits_memory_descriptor, 7, 1);
	for (int i=1; i<=14; i=i+1) {cout<<summits_memory[i-1]<<"\n";}

//cout<<"\n"<<summits_memory_descriptor<<"\n";


	pointtest = *summit_address(summitsfp, summits_memory, &summits_memory_descriptor, 3, 1);
	cout<<pointtest.abscisse()<<" , "<<pointtest.ordonnee()<<"\n";

integer = ind_loc_d1(/*p*/5, /*e*/3, summitsfp, summits_memory, &summits_memory_descriptor, g_fp, elements_memory, &elements_memory_descriptor);
cout<<"\n"<<integer<<"\n";




cout<<"\n\n\n";

//assembler les elements


/*	j'ai laisse tomber cette fonction pour une autre Kij_d1_2

	Kij_d1(R2_simplex_i, Kij, nbr_pts_d1);

cout<<"Les Kij sont:\n\n";

	for (double i=1; i<=g_nbr_elements; i=i+1)
	{
		k = i;
		for (double j=1; j<=3*g_nbr_elements; j=j+1)
		{
			l = j;
			cout<<"K"<<i<<","<<j<<" = "<<Kij[(k-1)*g_nbr_elements+l-1]<<"\n";
			if (j==g_nbr_elements) {cout<<"\n";}
		}
	}
cout<<"\n\n\n";

*/


	fclose(g_fp);
	fclose(summitsfp);

end:	return 0;

}