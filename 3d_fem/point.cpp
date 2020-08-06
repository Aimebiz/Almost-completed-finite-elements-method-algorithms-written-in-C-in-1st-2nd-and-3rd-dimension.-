/* Constructeur */
	point::point(double x, double y, double z)
{
	abs=x;
	ord=y;
	cot=z;
}


/* abscisse */
	double	point::abscisse(void)
{
	return abs;
}

/* ordonnee */
	double	point::ordonnee(void)
{
	return ord;
}

/* cote */
	double	point::cote(void)
{
	return cot;
}

/* Destructeur */
	point::~point(void)
{

}

	void	point::set_abs(double d)
{
		abs=d;
}

	void	point::set_ord(double d)
{
		ord=d;
}

	void	point::set_cot(double d)
{
		cot=d;
}