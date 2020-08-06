
#include <io.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "point.h"
#include "quatresimplex.h"
#include "3d_fem_assembly_global_vars.cpp"
#include "3d_fem_assembly_header.h"



int main()

{



//for (int i=0; i<256; i=i+1) {printf("%c",i); cout<<"	"<<i<<"\n";}

	g_fp = fopen("elements.txt","r");

	if (g_fp==0)
		{cout<<"Erreur le fichier elements.txt est introuvable."; goto end;}

//verifier le formatage du fichier elements.txt

	parser3(g_fp, &g_parsing_flag, &g_error_line, &g_nbr_elements);

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

	//for (int i=0; i<=35; i=i+1) {cout<<elements_memory[i]<<"\n";}



// test de local_point_sender()

	if (g_nbr_elements<=nbredelements)
		{pointtest = *local_point_sender(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 3, 1);}
	else
		{pointtest = *local_point_sender(g_fp, elements_memory, &elements_memory_descriptor, nbredelements, 3, 1);}

	cout<<pointtest.abscisse()<<" , "<<pointtest.ordonnee()<<" , "<<pointtest.cote()<<"\n";


// test de Kije()

	cout<<"K123 = "<<Kije(g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, 1, 2, 3)<<"\n";


//generer le fichier des points sommets
	//remove("summits.txt");
	summitsfp = fopen("summits.txt","w+");
//cout<<g_nbr_elements<<"\n";
	summits_file_generator (&nbre_de_sommets, g_fp, elements_memory, &elements_memory_descriptor, g_nbr_elements, summitsfp, &g_nbr_elements);


cout<<"Le nombre de points sommets est "<<nbre_de_sommets<<".\n";

//charger des points sommets en memoire
	summits_memory_charger(summitsfp, summits_memory, &summits_memory_descriptor, 10, 1);
	for (int i=1; i<=30; i=i+1) {cout<<summits_memory[i-1]<<"\n";}

//cout<<"\n"<<summits_memory_descriptor<<"\n";


	pointtest = *summit_address(summitsfp, summits_memory, &summits_memory_descriptor, 5, 9);
	cout<<pointtest.abscisse()<<" , "<<pointtest.ordonnee()<<" , "<<pointtest.cote()<<"\n";


	fclose(g_fp);
	fclose(summitsfp);

end:	return 0;

}
