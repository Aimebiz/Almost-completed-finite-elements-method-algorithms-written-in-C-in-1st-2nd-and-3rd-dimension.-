#ifndef _POINT_H_
#define _POINT_H_


class point

{

// Methodes utilisateurs
public:

//déclaration Constructeur, destructeur
	point(double x, double y, double z);
	~point(void);

//déclaration des méthodes

	double	abscisse(void);
	double	ordonnee(void);
	double	cote(void);
	void	set_abs(double d);
	void	set_ord(double d);
	void	set_cot(double d);

// Attributs implantation
	private:
		double	abs,ord,cot ;	//abscisse, ordonnee et cote du point



};

#include "point.cpp"

#endif
