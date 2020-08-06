#ifndef _POINT_D1_H_
#define _POINT_D1_H_


class point_d1

{

// Methodes utilisateurs
public:

//déclaration Constructeur, destructeur
	point_d1(double x);
	~point_d1(void);

//déclaration des méthodes

	double	abscisse(void);
	void	set_abs1(double d);

// Attributs implantation
	private:
		double	abs;	//abscisse du point



};

#include "point_d1.cpp"

#endif
