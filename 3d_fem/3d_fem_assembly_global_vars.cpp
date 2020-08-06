#ifndef _3d_fem_global_vars_
#define _3d_fem_global_vars_


	FILE*	g_fp;
	FILE*	summitsfp;
	int	g_parsing_flag, g_error_line;
	unsigned long long int	g_nbr_elements;
	const unsigned long long int nbredelements=1000;
	double	elements_memory[12*nbredelements];

	unsigned long long int	elements_memory_descriptor;
	point	temp_point1(0,0,0), temp_point2(0,0,0), temp_point3(0,0,0), temp_point4(0,0,0);

	point	pointtest(0,0,0);
	int	flag;	//flag for g_nbr_elements>nbredelements

	unsigned long long int	nbre_de_sommets;

	double	summits_memory[4*nbredelements];
	unsigned long long int	summits_memory_descriptor;

	point	temp_point5(0,0,0);

#endif