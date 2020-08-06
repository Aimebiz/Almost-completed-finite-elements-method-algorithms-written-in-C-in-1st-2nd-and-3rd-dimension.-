

	void	parser3(FILE* g_fp, int* g_parsing_flag, int* g_error_line, unsigned long long int* g_nbr_elements)
{

int	temp1;
double	val[12];
char	crt[11];
long int offset1=ftell(g_fp);
int whence=SEEK_SET;

label_d3_1:

	temp1 = fscanf(g_fp, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", &val[0], &crt[0], &val[1], &crt[1], &val[2], &crt[2], &val[3], &crt[3], &val[4], &crt[4], &val[5], &crt[5], &val[6], &crt[6], &val[7], &crt[7], &val[8], &crt[8], &val[9], &crt[9], &val[10], &crt[10], &val[11]);

	*g_nbr_elements = *g_nbr_elements + 1;
	*g_error_line =  *g_error_line + 1;

	if (temp1 == 23)

		{

			for (int i=0; i<11; i=i+1)
			{
				if (crt[i] == 44)
				{
					if (i==10)
					{
						i=0;
						while (i<11) {val[i]=0; i=i+1;}
						i=0;
						while (i<10) {crt[i]=0; i=i+1;}
						goto label_d3_1;
					}
				}
				else {goto before_end;}
			}
		}

	else	{
			*g_nbr_elements = *g_nbr_elements - 1;
			if (feof(g_fp)!=0) {if (temp1>0) {*g_parsing_flag=1; goto end_of_parser3;} else {*g_parsing_flag=0; goto end_of_parser3;}}
			*g_parsing_flag=1;
			goto end_of_parser3;
		}


before_end:
		*g_nbr_elements = *g_nbr_elements - 1;
		*g_parsing_flag=1;

end_of_parser3: ;

		fseek (g_fp, offset1, whence);

}



		void	elements_memory_charger(FILE* elements_file, double *elements_area, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int initn)
{

	unsigned long long int	i=1;
	double	val[12];
	char	crt[11];
	long int offset1=ftell(elements_file);
	int whence=SEEK_SET;


		while	(i<initn)
		{
			fscanf(g_fp, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", &val[0], &crt[0], &val[1], &crt[1], &val[2], &crt[2], &val[3], &crt[3], &val[4], &crt[4], &val[5], &crt[5], &val[6], &crt[6], &val[7], &crt[7], &val[8], &crt[8], &val[9], &crt[9], &val[10], &crt[10], &val[11]);
			i=i+1;
		}

	i=1;

		while	(i<=n)
		{
			fscanf(g_fp, "%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%c%lf%\n", (elements_area+12*i-12), &crt[0], (elements_area+12*i-11), &crt[1], (elements_area+12*i-10), &crt[2], (elements_area+12*i-9), &crt[3], (elements_area+12*i-8), &crt[4], (elements_area+12*i-7), &crt[5], (elements_area+12*i-6), &crt[6], (elements_area+12*i-5), &crt[7], (elements_area+12*i-4), &crt[8], (elements_area+12*i-3), &crt[9], (elements_area+12*i-2), &crt[10], (elements_area+12*i-1));
			i=i+1;
		}

	*elements_memory_descriptor=initn;
	fseek (elements_file, offset1, whence);

}



		point*	local_point_sender(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, unsigned long long int e, int i)

{

double	temp1, temp2, temp3;
long long int	j,k;
	long int offset1=ftell(elements_file);
	int whence=SEEK_SET;

label1:
			j = e-*elements_memory_descriptor;
			k=12*j;

		if (j>=0 && j<n)
		{
			if (i==1)
			{
			temp1 = *(elements_memory+k);
			temp2 = *(elements_memory+k+1);
			temp3 = *(elements_memory+k+2);
			temp_point1.set_abs(temp1);
			temp_point1.set_ord(temp2);
			temp_point1.set_cot(temp3);
			return &temp_point1;
			}

			else if (i==2)
			{
			temp1 = *(elements_memory+k+3);
			temp2 = *(elements_memory+k+4);
			temp3 = *(elements_memory+k+5);
			temp_point2.set_abs(temp1);
			temp_point2.set_ord(temp2);
			temp_point2.set_cot(temp3);
			return &temp_point2;
			}

			else if (i==3)
			{
			temp1 = *(elements_memory+k+6);
			temp2 = *(elements_memory+k+7);
			temp3 = *(elements_memory+k+8);
			temp_point3.set_abs(temp1);
			temp_point3.set_ord(temp2);
			temp_point3.set_cot(temp3);
			return &temp_point3;
			}

			else if (i==4)
			{
			temp1 = *(elements_memory+k+9);
			temp2 = *(elements_memory+k+10);
			temp3 = *(elements_memory+k+11);
			temp_point4.set_abs(temp1);
			temp_point4.set_ord(temp2);
			temp_point4.set_cot(temp3);
			return &temp_point4;
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
		quatresimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 4));

		return		(el.bi(i)*el.bi(j)+el.ci(i)*el.ci(j)+el.di(i)*el.di(j))/(6*el.determinant_S());
	}

	else {return 0;}
}


		double	dij(unsigned long long int i, unsigned long long int j)
{
	if (i==j) {return 1;} else {return 0;}
}


		double	Cije(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int j, unsigned long long int e)

{
	quatresimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 4));

	return		(el.determinant_S()/120)*(1+dij(i, j));
}

		double	Bie(FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor, unsigned long long int n, unsigned long long int i, unsigned long long int e)

{
	quatresimplex	el(local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 1), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 2), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 3), local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, 4));

	return		(el.determinant_S()/24);
}


		void	summits_file_generator (unsigned long long int* nbre_de_sommets, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor,unsigned long long int n, FILE* summits_file, unsigned long long* g_nbr_elements)

{
	point	pt(0, 0, 0);
	unsigned long long int k=0;
	unsigned long long int j=0;
	long int offset1=ftell(summits_file);
	int whence=SEEK_SET;
	fseek (summits_file, offset1, whence);
	long int offset2=ftell(summits_file);
	double	val[3];	val[0]=44; val[1]=44; val[2]=44;
	char	crt[2];
	int	c=44;


	for (unsigned long long int e=1; e<=*g_nbr_elements; e=e+1)
	{
		for ( unsigned long long int i=1; i<=4; i=i+1)
		{
			pt = *local_point_sender(elements_file, elements_memory, elements_memory_descriptor, n, e, i);

			fseek (summits_file, offset1, whence);

			for ( unsigned long long int l=1; l<=k; l=l+1)
			{
				if (l>0)
				{
					fscanf(summits_file, "%lf%c%lf%c%lf%", &val[0], &crt[0], &val[1],  &crt[1], &val[2]);
					if (val[0]==pt.abscisse() && val[1]==pt.ordonnee() && val[2]==pt.cote())
					{
						j=j+1;
					
					}
				}
			}

			fseek (summits_file, offset2, whence);

			if (j==0)
			{
				fprintf(summits_file,"%g,%g,%g\n",pt.abscisse(),pt.ordonnee(),pt.cote());
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
	double	temp1, temp2, temp3;
	char	crt[2];
	long int offset1=ftell(summits_file);
	int whence=SEEK_SET;

		while	(i<initn)
		{
			fscanf(summits_file, "%lf%c%lf%c%lf", &temp1, &crt[0], &temp2, &crt[1], &temp3);
			i=i+1;
		}

	i=3;

		while	(i<=3*n)
		{
			fscanf(summits_file, "%lf%c%lf%c%lf", (summits_memory+i-3), &crt[0], (summits_memory+i-2), &crt[1], (summits_memory+i-1));
			i=i+3;
		}

	fseek (summits_file, offset1, whence);
	*summits_memory_descriptor=initn;


}


		point*	summit_address(FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, unsigned long long int n, unsigned long long int i)

{

double	temp1, temp2, temp3;
unsigned long long int	j;
long int offset1=ftell(summits_file);
int whence=SEEK_SET;

label1:
			j = i-*summits_memory_descriptor;


		if (j>=0 && j<n)
		{

			temp1 = *(summits_memory+3*j);
			temp2 = *(summits_memory+3*j+1);
			temp3 = *(summits_memory+3*j+2);
			temp_point5.set_abs(temp1);
			temp_point5.set_ord(temp2);
			temp_point5.set_cot(temp3);
			return &temp_point5;
		}

		if (j>=n)
		{
			summits_memory_charger(summits_file, summits_memory, summits_memory_descriptor, n, i);
			*summits_memory_descriptor=i;
			goto label1;
		}

	fseek (summits_file, offset1, whence);


}



	int	ind_loc_d1(unsigned long long int p, unsigned long long int e, FILE* summits_file, double* summits_memory, unsigned long long int* summits_memory_descriptor, FILE* elements_file, double* elements_memory, unsigned long long int* elements_memory_descriptor)

{

	if ((*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).abscisse() && (*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).ordonnee())
	{
		return 1;
	}

	else if ((*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).abscisse() && (*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 2)).ordonnee())
	{
		return 2;
	}

	else if ((*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).abscisse() && (*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 3)).ordonnee())
	{
		return 3;
	}

	else if ((*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).abscisse() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 1)).abscisse() && (*summit_address(summits_file, summits_memory, summits_memory_descriptor, 3*nbredelements, p)).ordonnee() == (*local_point_sender(elements_file, elements_memory, elements_memory_descriptor, nbredelements, e, 4)).ordonnee())
	{
		return 4;
	}

	else
	{
		return 0;
	}
}
