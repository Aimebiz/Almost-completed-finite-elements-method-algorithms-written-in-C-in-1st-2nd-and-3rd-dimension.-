


		double	bie_1d(unsigned long long int i, unsigned long long int e)
{

	if (i==1) {return -1;}
	else 	{
		if (i==2) {return 1;}
		else {return 0;}

		}
	}

		double Le1(unsigned long long int e)
{
	deuxsimplex	e_e_d1(point_address_d1_1(gfp, points_memory, &point_d1_memory_descriptor, 1, nbredepoints, e), point_address_d1_2(gfp, points_memory, &point_d1_memory_descriptor, 2, nbredepoints, e+1));
	return	e_e_d1.determinant_S();
	}

		double	Kije1(unsigned long long int i, unsigned long long int j, unsigned long long int e)
{
	if (i!=0 && j!=0) {return (bie_1d(i,1)*bie_1d(j,1))/Le1(e);} else {return 0;}	//here j is fixed to 1 cause bie_1d() doesn't depend on it.
	}

		double	Bie1(unsigned long long int i, unsigned long long int e)
{
	return Le1(e)/2;
	}



/*for the following function, temp_d1_1 stand for error code and nbr_pts_d1 for the number
of entries in the file points_sommets_d1.txt*/

		void	parser1(int* temp_d1_1, unsigned long long int* nbr_pts_d1)
{
	FILE *points_sommets_d1_fp;
	double	temp_d1_2[1];
	int	temp_d1_4=0;

	points_sommets_d1_fp = fopen("points_sommets_d1.txt","r");

	if (points_sommets_d1_fp==0)
		{*temp_d1_1=0; goto end_of_parser1;}


//at this point check the file format


label_d1_1:


	temp_d1_4 = fscanf(points_sommets_d1_fp, "%lf%\n", &temp_d1_2);
	*nbr_pts_d1 = *nbr_pts_d1 + 1;
	if (temp_d1_4 == 1)
		{
			goto label_d1_1;
			}
	else	{
			*nbr_pts_d1 = *nbr_pts_d1 - 1;
			if (feof(points_sommets_d1_fp)!=0) {*temp_d1_1=1; goto end_of_parser1;}
			*temp_d1_1=3;
			goto end_of_parser1;
			}

end_of_parser1:		fclose(points_sommets_d1_fp);

	}




		void	range_checker1(FILE* point_file_d1, int* i)
{

range_checker1_1:

	double	temp_d1_1;
	double	temp_d1_2;

	if (feof(point_file_d1)!=0)
		{
			*i=2;
			goto end_range_checker1;
		}

	fscanf(point_file_d1, "%lf%\n", &temp_d1_1);

	if (feof(point_file_d1)!=0)
		{
			*i=1;
			goto end_range_checker1;
		}

range_checker1_2:

	if (feof(point_file_d1)!=0)
		{
			goto end_range_checker1;
		}

	fscanf(point_file_d1, "%lf%\n", &temp_d1_2);

	if (temp_d1_2 > temp_d1_1)
		{
			temp_d1_1 = temp_d1_2;
			goto range_checker1_2;
			}

	else {*i=0;}

end_range_checker1: ;

	}

		void	points_memory_charger1(FILE* point_file_d1, double *point_area, unsigned long long int n, unsigned long long int initn)
{

	unsigned long long int	i=1;
	double	temp;
	FILE*	fp;

	fp = point_file_d1;

		while	(i<initn)
		{
			fscanf(point_file_d1, "%lf", &temp);
			i=i+1;
		}

	i=1;

		while	(i<=n)
		{
			fscanf(point_file_d1, "%lf", (point_area+i-1));
			i=i+1;
		}

	point_file_d1 = fp;

	}

		point_d1*	point_address_d1_1(FILE* cpf1, double* point_area_d1, unsigned long long int* precharged_points_flag, unsigned long long int i, unsigned long long int n, unsigned long long int e)
{


cpf1=gfp;
double	temp, temp2;
unsigned long long int	j;

label1:
			j = e-*precharged_points_flag;
			temp = *point_area_d1;


		if (j>=0 && j<n)
		{

			temp2 = *(point_area_d1+j);
			temp_point1.set_abs1(temp2);
			return &temp_point1;
			}

		if (j>=n)
		{

gfp = fopen(pointsfile,"r");

			points_memory_charger1(cpf1, point_area_d1, n, e);
			*precharged_points_flag=e;
fclose(gfp);
			goto label1;

			}

		*point_area_d1 = temp;


	}


		point_d1*	point_address_d1_2(FILE* cpf1, double* point_area_d1, unsigned long long int* precharged_points_flag, unsigned long long int i, unsigned long long int n, unsigned long long int e)
{


double	temp, temp2;
unsigned long long int	j;

label1:
			j = e-*precharged_points_flag;
			temp = *point_area_d1;


		if (j>=0 && j<n)
		{

			temp2 = *(point_area_d1+j);
			temp_point2.set_abs1(temp2);
			return &temp_point2;

			}

		else
		{

gfp = fopen(pointsfile,"r");

			points_memory_charger1(cpf1, point_area_d1, n, e);
			*precharged_points_flag=e;
fclose(gfp);
			goto label1;

			}

		*point_area_d1 = temp;

	}

		int	ind_loc_d1(double i, double e)
{
	if (i==e)	{return	1;}
	if (i==e+1)	{return	2;}	else {return 0;}

	}


//	j'ai laisse tomber cette fonction malgre qu'elle boxe pour une autre Kij_d1_2

		void	Kij_d1(double R2_simplex_i[nbredepoints], double Kij[nbredepoints*nbredepoints], double nbr)
{

unsigned long long int e,i,j;
int k,l;

	for (e=1; e<nbr_pts_d1; e=e+1)
	{
		for (i=1; i<=nbr_pts_d1; i=i+1)
		{
			k = ind_loc_d1(i,e);
//cout<<" i = "<<i<<"	&	k,e = "<<k<<","<<e<<"\n";

			R2_simplex_i[i-1] = R2_simplex_i[i-1] + Bie1(k,e);

			for (j=1; j<=nbr_pts_d1; j=j+1)
			{
			l = ind_loc_d1(j,e);
//cout<<" i,j = "<<i<<","<<j<<"	&	k,l,e = "<<k<<","<<l<<","<<e<<"\n";

			Kij[(i-1)*nbredepoints+j-1] = Kij[(i-1)*nbredepoints+j-1] + Kije1(k,l,e);

			}
		}
	}


}



/*	j'ai defini cette fonction pour me passer de la memorisation des Kij par l'assemblage
difficile a operer par la fonction Kij_d1 predefinie*/


		double	Kij_d1_2(unsigned long long int q, unsigned long long int r, unsigned long long int* nbre)
{
	if	(q-r==-1)			{return Kije1(1,2,q);}
	else if	(q-r==1)			{return Kije1(2,1,r);}
	else if	(q==r && q!=1 && q!=*nbre)	{return Kije1(2,2,q-1)+Kije1(1,1,r);}
	else if	(q==r && q==1)			{return Kije1(1,1,1);}
	else if (q==r && q==*nbre)		{return Kije1(2,2,*nbre-1);}
	else if	(q-r>1)				{return 0;}
	else					{return 0;}

	}



/*	j'ai defini cette fonction pour me passer de la memorisation des Rij par l'assemblage*/


		void	Rij_d1(double R2_simplex_i[nbredepoints], double Kij[nbredepoints*nbredepoints], double nbr)
{


unsigned long long int e,i;
int k;

	for (e=1; e<nbr_pts_d1; e=e+1)
	{
		for (i=1; i<=nbr_pts_d1; i=i+1)
		{
			k = ind_loc_d1(i,e);
//cout<<" i = "<<i<<"	&	k,e = "<<k<<","<<e<<"\n";

			R2_simplex_i[i-1] = R2_simplex_i[i-1] + Bie1(k,e);
		}

	}

	}

		double	Rij_memory_d1(int i, int j)
{

	}

		double Kij_memory_d1(int i, int j)
{

	}

		void	boundary_conditions_d1(void)
{

	}

		struct_U_at_summits_d1	U_at_summits_d1(int e)
{

	}

		void	points_values_d1(void)
{

	}

		double	point_value_d1(double x)
{

	}
