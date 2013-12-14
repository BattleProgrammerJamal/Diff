/**
   Projet Diff
   -----------
   Gestion des options: Julie M'KPI
   Gestion de l'affichage: Amaury COLMANT
*/

#ifndef OPTIONS_H
#define OPTIONS_H

    #include <stdio.h>
    #include <stdlib.h>

    #define DIFF_NORMAL 0
    #define DIFF_BRIEF 1
    #define DIFF_REPORT_IDENTICAL_FILES 2
    #define DIFF_SIDE_BY_SIDE 3
    #define DIFF_EXPAND_TABS 4
    #define DIFF_IGNORE_CASE 5
    #define DIFF_HELP 6
    #define DIFF_NB_FUNCS 7

    void diff_normal(int argc, void** argv);
    void diff_brief(int argc, void**argv);
    void diff_report_id_files(int argc, void**argv);
    void diff_side_by_side(int argc, void**argv);
    void diff_expand_tabs(int argc, void**argv);
    void diff_ignore_case(int argc, void**argv);
    void diff_help(int argc, void**argv);

#endif

