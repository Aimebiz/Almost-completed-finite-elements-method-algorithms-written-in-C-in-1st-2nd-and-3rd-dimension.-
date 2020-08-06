class Cercle
{
// Methodes utilisateurs
public:

//d�claration Constructeur, destructeur
Cercle();
~Cercle();

//d�claration des m�thodes
void Move(float deltax, float deltay);
void Zoom(float scale);
float Area();

// Attributs implantation
private:
float cX, cY; // Position centre
float cR; // Rayon
};


//implantation des m�thodes

/* Constructeur */
Cercle::Cercle()
{
cX = cY = 0.0; // A l�origine par defaut
cR = 1.0; // Rayon unite
}

/* Deplacement */
void Cercle::Move(float deltax, float deltay)
{
cX += deltax;
cY += deltay;
}
/* Echelle */
void Cercle::Zoom(float scale)
{
cR *= scale;
}
/* Surface */
float Cercle::Area()
{
return 3.14159 * cR * cR;
}
/* Destructeur */
Cercle::~Cercle()
{
// Rien a faire de special !
}