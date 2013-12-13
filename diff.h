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

    #define NB_FONCTIONS 7

    #define DIFF_NORMAL 0
    #define DIFF_BRIEF 1
    #define DIFF_REPORT_IDENTICAL_FILES 2
    #define DIFF_SIDE_BY_SIDE 3
    #define DIFF_EXPAND_TABS 4
    #define DIFF_IGNORE_CASE 5
    #define DIFF_HELP 6

    extern void (*diff_funcs[NB_FONCTIONS])(int, void**);

    void init_diff_funcs();
    t_list* get_opts_id(int argc, char** argv);
    void execute(int argc, void** argv, void (*ptr)(int, void**));
    void run(int argc, void** argv);

#endif
