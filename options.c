/**
   Projet Diff
   -----------
   Gestion des options: Julie M'KPI
   Gestion de l'affichage: Amaury COLMANT
*/

#include "options.h"

void diff_normal(int argc, void** argv)
{
    FILE *f1 = 0, *f2 = 0;
    f1 = fopen((char*)argv[argc-2], "r");
    f2 = fopen((char*)argv[argc-1], "r");

    printf("Diff normal \n");

    fclose(f1);
    fclose(f2);
}

void diff_brief(int argc, void**argv)
{
    printf("Diff brief \n");
}

void diff_report_id_files(int argc, void**argv)
{
    printf("Diff report id files \n");
}

void diff_side_by_side(int argc, void**argv)
{
    printf("Diff side by side \n");
}

void diff_expand_tabs(int argc, void**argv)
{
    printf("Diff expand tabs \n");
}

void diff_ignore_case(int argc, void**argv)
{
    printf("Diff ignore case \n");
}

void diff_help(int argc, void**argv)
{
    printf("[ Diff version 1.0 ]\n");
    printf("---------------------\n");
    printf("Liste des options : \n");
    printf("--normal\tProduire un diff en format normal (par defaut)\n");
    printf("-q, --brief\tIndiquer seulement si les fichiers different\n");
    printf("-s, --report-identical-files\tIndiquer si les deux fichiers sont identiques\n");
    printf("-y, --side-by-side\tAffichage sur deux colonnes\n");
    printf("-t, --expand-tabs\tEtaler les tabulateurs en espaces dans la sortie\n");
    printf("-i, --ignore-case\tIgnorer les differences de casses dans le contenu des fichiers\n");
    printf("--help\tAffiche cette aide\n");
}
