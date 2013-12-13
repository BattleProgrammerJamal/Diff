/**
   Projet Diff
   -----------
   Fonctions / Procédures utilitaires: Jamal BOUIZEM et Julie M'KPI
*/

#include "util.h"

int length(char* str)
{
	int cpt = 0;
	for(cpt = 0; *str++ != '\0'; ++cpt);
	return cpt;
}

void to_upper_case(char* input)
{
	int i = 0;
	for(i = 0; i < length(input); ++i)
	{
		if(input[i] <= 122 && input[i] >= 97)
		{
			input[i] = (int)input[i] - 32;
		}
	}
	printf("%s", input);
}

void to_lower_case(char* input)
{
	int i = 0;
	for(i = 0; i < length(input); ++i)
	{
		if(input[i] <= 90 && input[i] >= 65)
		{
			input[i] = (int)input[i] + 32;
		}
	}
	printf("%s", input);
}

void to_lower_case_s(char* input)
{
	int i = 0;
	for(i = 0; i < length(input); ++i)
	{
		if(input[i] <= 90 && input[i] >= 65)
		{
			input[i] = (int)input[i] + 32;
		}
	}
}

void capitalize(char* input)
{
	int i = 0;
	to_lower_case_s(input);
	if(input[0] <= 122 && input[0] >= 97) { input[0] = (int)input[0] - 32; }
	for(i = 0; i < length(input); ++i)
	{
		if(input[i] == 32)
		{
			if(input[i+1] <= 122 && input[i+1] >= 97)
			{
				input[i+1] = (int)input[i+1] - 32;
			}
		}
	}
	printf("%s", input);
}

int isOnlyAlphanumeric(char* str)
{
	int i = 0;
	for(i = 0; i < length(str); ++i)
	{
		if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))
		{
			return 1;
		}
	}
	return 0;
}

int nb_mots(char* str)
{
	int i = 0, cpt = 0;
	for(i = 1; i < length(str); ++i)
	{
		if(isOnlyAlphanumeric(&str[i-1]))
		{
			if(str[i] == '.' || str[i] == ',' || str[i] == ' ')
			{
				++cpt;
			}
		}
	}
	return cpt;
}

int str_pos(char ch, char* str)
{
	int i = 0;
	for(i = 0; i < length(str); ++i) { if(ch == str[i]) { return i; } }
	return -1;
}

int str_search(char *string, char *pattern)
{
	int i = 0, j = 0, k = 0, max = length(pattern) - 1;

	for(i = 0; i < length(string); ++i)
	{
		if(string[i] == pattern[0])
		{
			k = 0;
			for(j = i; j < i+max; ++j)
			{
				if(string[j] != pattern[k]) { return -1; }
				++k;
			}
			return 1;
		}
	}

	return -1;
}

void str_replace_first(char *string, char *pattern, char *replacement)
{
	int i = 0, j = 0, k = 0, max = length(pattern) - 1, trouve = 0, fin = 0;
	char buff[255];
	sprintf(buff, "%s", string);

	for(i = 0; i < length(buff) && trouve != 1; ++i)
	{
		if(buff[i] == pattern[0])
		{
			k = 0;
			fin = 0;
			for(j = i; j <= i+max; ++j)
			{
				if(buff[j] != pattern[k]) { fin = 1; break; }
				buff[j] = replacement[k];
				++k;
				if(k == max) { trouve = 1; }
			}
		}
	}

	if(trouve == 1 && !fin) { sprintf(string, "%s", buff); }
	printf("%s", string);
}

char* str_cat(const char* v1, const char* v2)
{
	char* str = 0;
	str = (char*)malloc(sizeof(v1)*sizeof(v2));
	sprintf(str, "%s%s", v1, v2);
	return str;
}

char* str_cpy(const char* s1)
{
	char* str = 0;
	str = (char*)malloc(sizeof(s1));
	sprintf(str, "%s", s1);
	return str;
}

void str_revert(char* input)
{
	char ch;
	int i = length(input)-1, j = 0;
	while(i >= j)
	{
		ch = input[i];
		input[i] = input[j];
		input[j] = ch;
		++j;
		--i;
	}
}

int str_cmp(const char* a, const char* b)
{
    for(;;++a, ++b)
    {
        if(*a == '\0' || *b == '\0')
        {
            return (*a == *b)? 0 : *a != '\0' ? 1 : -1;
        }
        if(*a != *b)
        {
            return *a > *b ? 1 : -1;
        }
    }
}

void tab_pop(int n, char** tab)
{
    int i = 0;
    for(i = 0; i < n-1; ++i)
    {
        tab[i] = tab[i+1];
    }
    tab[i] = "\0";
}

int fCountLines(FILE* f)
{
    if(f != 0)
    {
        int i = 0;
        char buff[255];

        while(fgets(buff, 255, (FILE*)f) != 0)
        {
            ++i;
        }

        rewind(f);
        return i;
    }
    else
    {
        printf("Fichier mal alloue ! \n");
        return(-1);
    }
}

char** fToString(FILE* f, const unsigned int nb_lignes)
{
    if(f != 0)
    {
        int i = 0;

        char** content = 0;
        content = (char**)malloc(sizeof(char*)*nb_lignes);

        for(i = 0; i < nb_lignes; ++i)
        {
            content[i] = (char*)malloc(sizeof(char*)*255);
        }

        for(i = 0; i < nb_lignes; ++i)
        {
            if(!feof(f))
            {
                fgets(content[i], 255, (FILE*)f);
            }
        }

        rewind(f);
        return(content);
    }
    else
    {
        printf("Fichier mal alloue ! \n");
        return;
    }
}

t_file* init_file(const char* location, const char* mode)
{
    t_file* f = 0;
    f = (t_file*)malloc(sizeof(t_file*));
    if((f->fichier = fopen(location, mode)) != 0)
    {
        f->nb_lignes = fCountLines(f->fichier);
        f->contenu = fToString(f->fichier, f->nb_lignes);
        return(f);
    }
    else
    {
        printf("Impossible d\'ouvrir le fichier ! \n");
        return;
    }
}

void free_file(t_file* f)
{
    fclose(f->fichier);
    free(f->contenu);
}

void show_file(t_file* f)
{
    int i = 0;
    for(i = 0; i < f->nb_lignes; ++i)
    {
        printf("%s", f->contenu[i]);
    }
}

t_list* list_new(int max)
{
    t_list* liste = NULL;
    liste = (t_list*)malloc(sizeof(t_list));
    liste->max = max;
    liste->elems = (int*)malloc(sizeof(int)*max);
    liste->length = 0;
    return liste;
}

void list_display(t_list* liste)
{
    int i = 0;
    if(liste->length == 0) { printf("Liste vide ! \n"); }
    for(i = 0; i < liste->length; ++i)
    {
        printf("%i\t", liste->elems[i]);
    }
}

void list_append(t_list* liste, int elem)
{
    if(liste->length < liste->max)
    {
        liste->elems[liste->length] = elem;
        liste->length++;
    }
    else
    {
        printf("Attention, liste pleine ! \n");
    }
}

void list_remove(t_list* liste)
{
    if(liste->length > 0)
    {
        if(liste->length <= liste->max)
        {
            int i = 0;
            for(i = 0; i < liste->length-1; ++i)
            {
                liste->elems[i] = liste->elems[i+1];
            }
            liste->elems[i+1] = 0;
            liste->length--;
        }
    }
    else
    {
        printf("Attention, liste vide ! \n");
    }
}

t_list* list_revert(t_list* liste)
{
    int i = 0;
    t_list* liste2 = list_new(liste->max);

    for(i = liste->length-1; i >= 0; --i)
    {
        list_append(liste2, liste->elems[i]);
    }

    return liste2;
}

void list_revert_inside(t_list* liste)
{
    if(liste->length > 0)
    {
        int i = 0, j = liste->length-1, tmp = 0;

        for(i = 0; i < liste->length/2; ++i)
        {
            tmp = liste->elems[i];
            liste->elems[i] = liste->elems[j];
            liste->elems[j] = tmp;
            --j;
        }
    }
    else
    {
        printf("Attention, liste vide ! \n");
    }
}

t_list* list_copy(t_list* liste)
{
    return liste ? copy(liste, list_new(liste->length), liste->length) : NULL;
}

t_list* copy(t_list* src, t_list* dst, int i)
{
    dst->elems[i] = src->elems[i];
    return (i && ++dst->length) ? copy(src, dst, i-1) : dst;
}

void list_insert(t_list* l, uint id, int valeur)
{
    if(l->length != l->max)
    {
        if(id >= 0 && id <= l->length)
        {
            int i = 0;
            for(i = l->length; i > id; --i)
            {
                l->elems[i] = l->elems[i-1];
            }
            l->elems[id] = valeur;
            l->length++;
        }
        else
        {
            printf("Indice hors des limites de la liste ! \n");
        }
    }
    else
    {
        printf("Liste remplie ! \n");
    }
}

void list_insert_infinite(t_list* l, uint id, int valeur)
{
    if(id > l->length)
    {
        printf("Indices non continus ! \n");
    }
    else
    {
        if(l->length < l->max)
        {
            list_insert(l, id, valeur);
        }
        else
        {
            l->max++;
            int* tmp = (int*)malloc(sizeof(int)*l->max);
            int i = 0;
            for(i = 0; i < id; ++i)
            {
                tmp[i] = l->elems[i];
            }
            tmp[id] = valeur;
            for(i = id+1; i < l->length; ++i)
            {
                tmp[i+1] = l->elems[i];
            }
            free(l->elems);
            l->elems = tmp;
            l->length++;
        }
    }
}
