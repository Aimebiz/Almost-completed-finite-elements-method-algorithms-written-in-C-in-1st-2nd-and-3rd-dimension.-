#ifndef _2d_fem_global_vars_
#define _2d_fem_global_vars_


	FILE*	g_fp;
	FILE*	summitsfp;
	int	g_parsing_flag, g_error_line;
	unsigned long long int	g_nbr_elements;
	const unsigned long long int nbredelements=1000;
	double	elements_memory[6*nbredelements];

	unsigned long long int	elements_memory_descriptor;
	point_d2	temp_point1(0,0), temp_point2(0,0), temp_point3(0,0);

	point_d2	pointtest(0,0);
	int	flag;	//flag for g_nbr_elements>nbredelements

	unsigned long long int	nbre_de_sommets;

	double	summits_memory[3*nbredelements];
	unsigned long long int	summits_memory_descriptor;

	point_d2	temp_point4(0,0);
	int integer;

	double	Rij[3*nbredelements];
	double	R2_simplex_i[3*nbredelements];
	double	Kij[3*nbredelements*3*nbredelements];

#endif