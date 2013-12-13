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
    if(argc <= 6 && argc >= 4)
    {
        init_diff_funcs();
        tab_pop(argc, argv);
        run(argc, argv);
    }
    else
    {
        printf("Pas assez ou trop d'arguments ! \n");
        return(1);
    }

    return(0);
}
