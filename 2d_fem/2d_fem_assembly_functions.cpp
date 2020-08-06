


	void	parser2(FILE* g_fp, int* g_parsing_flag, int* g_error_line, unsigned long long int* g_nbr_elements)
{

int	temp1;
double	val[6];
char	crt[5];
long int offset1=ftell(g_fp);
int whence=SEEK_SET;

label_d2_1:

	temp1 = fscanf(g_fp, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", &val[0], &crt[0], &val[1], &crt[1], &val[2], &crt[2], &val[3], &crt[3], &val[4], &crt[4], &val[5]);


	*g_nbr_elements = *g_nbr_elements + 1;
	*g_error_line =  *g_error_line + 1;

	if (temp1 == 11)

		{

			for (int i=0; i<5; i=i+1)
			{
				if (crt[i] == 44)
				{
					if (i==4)
					{
						i=0;
						while (i<5) {val[i]=0; i=i+1;}
						i=0;
						while (i<4) {crt[i]=0; i=i+1;}
						goto label_d2_1;
					}
				}
				else {goto before_end;}
			}
		}

	else	{
			*g_nbr_elements = *g_nbr_elements - 1;
			if (feof(g_fp)!=0) {if (temp1>0) {*g_parsing_flag=1; goto end_of_parser2;} else {*g_parsing_flag=0; goto end_of_parser2;}}
			*g_parsing_flag=1;
			goto end_of_parser2;
		}


before_end:
		*g_nbr_elements = *g_nbr_elements - 1;
		*g_parsing_flag=1;

end_of_parser2: ;

		fseek (g_fp, offset1, whence);

}



		void	elements_memory_charger(FILE* elements_file, double *elements_area, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int initn)
{

	unsigned long long int	i=1;
	double	val[6];
	char	crt[5];
	long int offset1=ftell(elements_file);
	int whence=SEEK_SET;


		while	(i<initn)
		{
			fscanf(elements_file, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", &val[0], &crt[0], &val[1], &crt[1], &val[2], &crt[2], &val[3], &crt[3], &val[4], &crt[4], &val[5]);
			i=i+1;
		}

	i=1;

		while	(i<=n)
		{
			fscanf(elements_file, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", (elements_area+6*i-6), &crt[0], (elements_area+6*i-5), &crt[1], (elements_area+6*i-4), &crt[2], (elements_area+6*i-3), &crt[3], (elements_area+6*i-2), &crt[4], (elements_area+6*i-1));
			i=i+1;
		}

	*elements_memory_descriptor=initn;
	fseek (elements_file, offset1, whence);

}



		point_d2*	local_point_sender(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, unsigned long long int e, unsigned long long int i)

{

	double	temp1, temp2, temp3;
	long long int	j,k;
	long int offset1=ftell(elements_file);
	int whence=SEEK_SET;

label1:
			j = e-*elements_memory_descriptor;
			k=6*j;

		if (j>=0 && j<n)
		{
			if (i==1)
			{
			temp2 = *(elements_memory+k);
			temp3 = *(elements_memory+k+1);
			temp_point1.set_abs(temp2);
			temp_point1.set_ord(temp3);
			return &temp_point1;
			}

			else if (i==2)
			{
			temp2 = *(elements_memory+k+2);
			temp3 = *(elements_memory+k+3);
			temp_point2.set_abs(temp2);
			temp_point2.set_ord(temp3);
			return &temp_point2;
			}

			else if (i==3)
			{
			temp2 = *(elements_memory+k+4);
			temp3 = *(elements_memory+k+5);
			temp_point3.set_abs(temp2);
			temp_point3.set_ord(temp3);
			return &temp_point3;
			}

			else {}
		}

		fseek (elements_file, offset1, whence);

		if (j>=n)
		{
			elements_memory_charger(elements_file, elements_memory, elements_memory_descriptor, n, e);
			*elements_memory_descriptor=e;
			goto label1;

		}


}



		double	Kije(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int j, unsigned long long int e)

{
	if (i!=0 && j!=0)
	{
		troissimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3));

		return		(el.bi(i)*el.bi(j)+el.ci(i)*el.ci(j))/(2*el.determinant_S());
	}

	else {return 0;}
}


		double	dij(unsigned long long int i, unsigned long long int j)
{
	if (i==j) {return 1;} else {return 0;}
}


		double	Cije(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int j, unsigned long long int e)

{
	troissimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3));

	return		(el.determinant_S()/24)*(1+dij(i, j));
}

		double	Bie(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int e)

{
	troissimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3));

	return		(el.determinant_S()/6);
}


		void	summits_file_generator (unsigned long long int* nbre_de_sommets, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, FILE* summits_file, unsigned long long* g_nbr_elements)

{
	point_d2	pt(0, 0);
	unsigned long long int k=0;
	unsigned long long int j=0;
	long int offset1=ftell(summits_file);
	int whence=SEEK_SET;
	fseek (summits_file, offset1, whence);
	long int offset2=ftell(summits_file);
	double	val[2];	val[0]=44; val[1]=44;
	char	crt=44;
	int	c=44;


	for (unsigned long long int e=1; e<=*g_nbr_elements; e=e+1)
	{
		for ( unsigned long long int i=1; i<=3; i=i+1)
		{
			pt = *local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, i);

			fseek (summits_file, offset1, whence);

			for ( unsigned long long int l=1; l<=k; l=l+1)
			{
				if (l>0)
				{
					fscanf(summits_file, "%lf%c%lf%", &val[0], &crt, &val[1]);
					if (val[0]==pt.abscisse() && val[1]==pt.ordonnee())
					{
						j=j+1;
					
					}
				}
			}

			fseek (summits_file, offset2, whence);

			if (j==0)
			{
				fprintf(summits_file,"%g,%g\n",pt.abscisse(),pt.ordonnee());
				k = k+1;
			}

			j = 0;
			offset2=ftell(summits_file);
		}
	}

	*nbre_de_sommets=k;
	fseek (summits_file, offset1, whence);

}



		void	summits_memory_charger(FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, unsigned long long int n, unsigned long long int initn)
{

	unsigned long long int	i=1;
	double	temp1, temp2;
	char	crt=44;
	long int offset1=ftell(summits_file);
	int whence=SEEK_SET;

		while	(i<initn)
		{
			fscanf(summits_file, "%lf%c%lf", &temp1, &crt, &temp2);
			i=i+1;
		}

	i=2;

		while	(i<=2*n)
		{
			fscanf(summits_file, "%lf%c%lf", (summits_memory+i-2), &crt, (summits_memory+i-1));
			i=i+2;
		}

	fseek (summits_file, offset1, whence);
	*summits_memory_descriptor=initn;

	}





		point_d2*	summit_address(FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, unsigned long long int n, unsigned long long int i)

{

double	temp1, temp2;
unsigned long long int	j;
long int offset1=ftell(summits_file);
int whence=SEEK_SET;

label1:
			j = i-*summits_memory_descriptor;


		if (j>=0 && j<n)
		{

			temp1 = *(summits_memory+2*j);
			temp2 = *(summits_memory+2*j+1);
			temp_point4.set_abs(temp1);
			temp_point4.set_ord(temp2);
			return &temp_point4;
		}

		if (j>=n)
		{
			summits_memory_charger(summits_file, summits_memory, summits_memory_descriptor, n, i);
			*summits_memory_descriptor=i;
			goto label1;
		}

	fseek (summits_file, offset1, whence);


}



	unsigned long long int	ind_loc_d1(unsigned long long int p, unsigned long long int e, FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor)

{

point_d2	pt(0, 0), pt1(0, 0), pt2(0, 0), pt3(0, 0);
pt = *summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p);

cout<<pt.abscisse()<<"\n";
cout<<pt.ordonnee()<<"\n";
	if (pt.abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).abscisse() && pt.ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).ordonnee())
	{
		return 1;
	}

	else if (pt.abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 2)).abscisse() && pt.ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 2)).ordonnee())
	{
		return 2;
	}

	else if (pt.abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 3)).abscisse() && pt.ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 3)).ordonnee())
	{
		return 3;
	}

	else
	{
		return 0;
	}
}




		void	Kij_d1(double R2_simplex_i[3*nbredelements], double Kij[3*nbredelements*3*nbredelements], double nbr, FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor)
{

unsigned long long int e,i,j;
unsigned long long int k,l;

	for (e=1; e<3*g_nbr_elements; e=e+1)
	{
		for (i=1; i<=3*g_nbr_elements; i=i+1)
		{
			k = ind_loc_d1(i, e, summits_file, summits_memory, summits_memory_descriptor, elements_file, elements_memory, elements_memory_descriptor);
//cout<<" i = "<<i<<"	&	k,e = "<<k<<","<<e<<"\n";

			R2_simplex_i[i-1] = R2_simplex_i[i-1] + Bie(elements_file, elements_memory, elements_memory_descriptor, g_nbr_elements, k,e);

			for (j=1; j<=3*g_nbr_elements; j=j+1)
			{
			l = ind_loc_d1(j, e, summits_file, summits_memory, summits_memory_descriptor, elements_file, elements_memory, elements_memory_descriptor);
//cout<<" i,j = "<<i<<","<<j<<"	&	k,l,e = "<<k<<","<<l<<","<<e<<"\n";

			Kij[(i-1)*3*nbredelements+j-1] = Kij[(i-1)*3*nbredelements+j-1] + Kije(elements_file, elements_memory, elements_memory_descriptor, g_nbr_elements, k,l,e);

			}
		}
	}


}
