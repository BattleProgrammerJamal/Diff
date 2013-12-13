/**
   Projet Diff
   -----------
   Fonctions / Procédures utilitaires: Jamal BOUIZEM et Julie M'KPI
*/

#ifndef UTIL_H
#define UTIL_H

    #include <stdio.h>
    #include <stdlib.h>

    int length(char* str);

    void to_upper_case(char* input);
    void to_lower_case(char* input);
    void to_lower_case_s(char* input);
    void capitalize(char* input);
    int isOnlyAlphanumeric(char* str);
    int nb_mots(char* str);
    int str_pos(char ch, char* str);
    void str_replace_first(char *string, char *pattern, char *replacement);
    void str_revert(char* input);
    int str_cmp(const char* a, const char* b);
    char* str_cat(const char* v1, const char* v2);
    char* str_cpy(const char* s1);
    int str_search(char *string, char *pattern);
    void tab_pop(int n, char** tab);

    int fCountLines(FILE* f);
    char** fToString(FILE* f, const unsigned int nb_lignes);

    typedef struct t_file t_file;
    struct t_file
    {
        FILE* fichier;
        int nb_lignes;
        char** contenu;
    };

    t_file* init_file(const char* location, const char* mode);
    void free_file(t_file* f);
    void show_file(t_file* f);

    typedef unsigned int uint;

    typedef struct t_list t_list;
    struct t_list
    {
        int *elems;
        int max;
        int length;
    };

    t_list* list_new(int max);
    void list_display(t_list* liste);
    void list_append(t_list* liste, int elem);
    void list_remove(t_list* liste);
    t_list* list_revert(t_list* liste);
    void list_revert_inside(t_list* liste);
    t_list* list_copy(t_list* liste);
    t_list* copy(t_list* src, t_list* dst, int i);
    void list_insert(t_list* l, uint id, int valeur);
    void list_insert_infinite(t_list* l, uint id, int valeur);

#endif
