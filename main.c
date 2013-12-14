/**
   Projet Diff
   -----------
   Point d'entr�e, utilise les
   fonctions d�finie dans diff.c/h
   pour rediriger vers telle ou telle
   fonctionnalit�e du Diff: Jamal BOUIZEM
*/

#include "main.h"

int main(int argc, char** argv)
{
    if(argc <= 6 && argc >= 3)
    {
        init_diff_funcs();
        tab_pop(argc, argv);
        run(argc, (void**)argv);
    }
    else
    {
        printf("operateur manquant \n");
        printf("Essayer l\'option \'--help\' pour de plus amples renseignements. \n");
        return(1);
    }

    return(0);
}
