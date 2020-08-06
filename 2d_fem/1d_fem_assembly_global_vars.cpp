#ifndef _1d_fem_global_vars_
#define _1d_fem_global_vars_

	const unsigned long long int nbredepoints=1000;
	#define pointsfile "points_sommets_d1.txt"
	double	bie_1d_memory[2] = {-1,1};
	unsigned long long int	nbr_pts_d1=0;	//compteur du nombre de points sommets entre dans points_sommets_d1.txt
	int	temp_d1_1;	//returned by function parser1()
	double	points_memory[nbredepoints];
	unsigned long long int	point_d1_memory_descriptor;

	point_d1	temp_point1(0), temp_point2(1);
	double* j=points_memory;
	double	Rij[nbredepoints];
	double	R2_simplex_i[nbredepoints];
	double	Kij[nbredepoints*nbredepoints];
	int	k,l,m;
	FILE*	gfp;	//global pointer to a file
	unsigned long long int i,p;
	unsigned long long int o=0;

#endif