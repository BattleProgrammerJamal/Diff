/**
   Projet Diff
   -----------
   Fonctions / Procédures directement liées à
   la gestion des arguments en entrée et la mise
   en relation avec les options: Jamal BOUIZEM
*/

#ifndef DIFF_H
#define DIFF_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "util.h"
    #include "options.h"

    void init_diff_funcs();
    t_list* get_opts_id(int argc, char** argv);
    void execute(int argc, void** argv, void (*ptr)(int, void**));
    void run(int argc, void** argv);

#endif
