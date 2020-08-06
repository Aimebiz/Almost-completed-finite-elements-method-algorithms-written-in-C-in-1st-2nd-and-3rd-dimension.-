
/* Constructeur */
	point_d1::point_d1(double x)
{
	abs=x;
}


/* abscisse */
	double	point_d1::abscisse(void)
{
	return abs;
}


/* Destructeur */
	point_d1::~point_d1(void)
{

}

	void	point_d1::set_abs1(double d)
{
		abs=d;
}