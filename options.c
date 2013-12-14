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
    f1 = fopen((char*)argv[0], "r");
    f2 = fopen((char*)argv[1], "r");

    if(f1 != 0 && f2 != 0)
    {
        int n1 = 0, n2 = 0, different = 1, i = 0, ligne = 1;
        char *str = 0, *str2 = 0;
        str = (char*)malloc(sizeof(char*)*255);
        str2 = (char*)malloc(sizeof(char*)*255);
        while((fgets(str, 255, f1) != 0) && (fgets(str2, 255, f2) != 0))
        {
            str_sub(str, '\n');
            str_sub(str2, '\n');

            if(str_cmp(str, str2) == 0)
            {
                printf("%i, [%s] = [%s]", ligne, str, str2);
            }
            else
            {
                different = 1;
                n1 = nb_mots(str);
                n2 = nb_mots(str2);

                for(i = 0; str[i] != '\0' || str2[i] != '\0'; ++i)
                {
                    if(str[i] == str2[i])
                    {
                        different = 0;
                        break;
                    }
                }

                if(different == 0)
                {
                    printf("%i, [%s] d [%s]", ligne, str, str2);
                }
                else
                {
                    printf("%i, [%s] c [%s]", ligne, str, str2);
                }
            }
            putchar('\n');
            ++ligne;
        }

        free(str);
        free(str2);
        fclose(f1);
        fclose(f2);
    }
    else
    {
        printf("Unexistant(s) file(s) ! \n");
        return;
    }
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
    printf("Usage: diff [OPTION]... FICHIER1 FICHIER2\n\n");
    printf("--normal\tProduire un diff en format normal (par defaut)\n");
    printf("-q, --brief\tIndiquer seulement si les fichiers different\n");
    printf("-s, --report-identical-files\tIndiquer si les deux fichiers sont identiques\n");
    printf("-y, --side-by-side\tAffichage sur deux colonnes\n");
    printf("-t, --expand-tabs\tEtaler les tabulateurs en espaces dans la sortie\n");
    printf("-i, --ignore-case\tIgnorer les differences de casses dans le contenu des fichiers\n");
    printf("--help\tAffiche cette aide\n");
}
