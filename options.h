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

    void diff_normal(int argc, void** argv);
    void diff_brief(int argc, void**argv);
    void diff_report_id_files(int argc, void**argv);
    void diff_side_by_side(int argc, void**argv);
    void diff_expand_tabs(int argc, void**argv);
    void diff_ignore_case(int argc, void**argv);
    void diff_help(int argc, void**argv);

#endif

