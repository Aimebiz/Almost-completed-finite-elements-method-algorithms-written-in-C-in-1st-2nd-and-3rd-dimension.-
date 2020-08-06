#include <io.h>
#include <stdio.h>
#include <float.h>
#include "Cercle.h"
int main()
{
float S; // Variable locale
Cercle toto; // Instance de cercle
/* Deplace toto */
toto.Move(150, 0);
/* Affiche sa surface */
S = toto.Area();
printf("Surface = %f\n", S);
/* Zoom et reaffiche */
toto.Zoom(1.5);
S = toto.Area();
printf("Surface apres zoom = %f\n", S);
return 0;
}