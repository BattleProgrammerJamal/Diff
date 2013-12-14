/**
   Projet Diff
   -----------
   Fonctions / Procédures directement liées à
   la gestion des arguments en entrée et la mise
   en relation avec les options: Jamal BOUIZEM
*/

#include "diff.h"

void (*diff_funcs[DIFF_NB_FUNCS])(int, void**);

void init_diff_funcs()
{
    diff_funcs[0] = diff_normal;
    diff_funcs[1] = diff_brief;
    diff_funcs[2] = diff_report_id_files;
    diff_funcs[3] = diff_side_by_side;
    diff_funcs[4] = diff_expand_tabs;
    diff_funcs[5] = diff_ignore_case;
    diff_funcs[6] = diff_help;
}

t_list* get_opts_id(int argc, char** argv)
{
    t_list* l_id = 0;
    if(argc > 0)
    {
        l_id = list_new(argc);

        int i = 0;
        for(i = 0; i < argc; ++i)
        {
            if(str_cmp(argv[i], "--normal") == 0)
            {
                list_append(l_id, DIFF_NORMAL);
            }
            else
            {
                if(str_cmp(argv[i], "-q") == 0 || str_cmp(argv[i], "--brief") == 0)
                {
                    list_append(l_id, DIFF_BRIEF);
                }
                else
                {
                    if(str_cmp(argv[i], "-s") == 0 || str_cmp(argv[i], "--report-identical-files") == 0)
                    {
                        list_append(l_id, DIFF_REPORT_IDENTICAL_FILES);
                    }
                    else
                    {
                        if(str_cmp(argv[i], "-y") == 0 || str_cmp(argv[i], "--side-by-side") == 0)
                        {
                            list_append(l_id, DIFF_SIDE_BY_SIDE);
                        }
                        else
                        {
                            if(str_cmp(argv[i], "-t") == 0 || str_cmp(argv[i], "--expand-tabs") == 0)
                            {
                                list_append(l_id, DIFF_EXPAND_TABS);
                            }
                            else
                            {
                                if(str_cmp(argv[i], "-i") == 0 || str_cmp(argv[i], "--ignore-case") == 0)
                                {
                                    list_append(l_id, DIFF_IGNORE_CASE);
                                }
                                else
                                {
                                    if(str_cmp(argv[i], "--help") == 0)
                                    {
                                        list_append(l_id, DIFF_HELP);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        l_id = list_new(1);
        list_append(l_id, 0);
    }

    return l_id;
}

void execute(int argc, void** argv, void (*ptr)(int, void**))
{
    ptr(argc, argv);
}

void run(int argc, void** argv)
{
    t_list* l = 0;
    l = get_opts_id(argc-3, argv);

    while(argc > 3)
    {
        tab_pop(argc, argv);
        --argc;
    }

    if(l->length > 0)
    {
        int i = 0;
        for(i = 0; i < l->length; ++i)
        {
            execute(argc, (void**)argv, diff_funcs[l->elems[i]]);
        }
    }
    else
    {
        execute(argc, (void**)argv, diff_funcs[0]);
    }

    free(l);
}
