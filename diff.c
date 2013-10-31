#include "diff.h"

/* Renvoie la représentation d'un fichier sous forme de chaîne de caractères*/
void fToString(FILE* F)
{
	int c;
	while((c = fgetc(F)) != EOF)
	{
		if(c != '\n')
		{
			printf("%c", c);
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");
}

/* Ecrit dans un fichiers de log d'erreurs, en titre le type d'erreur et le contenu de l'erreur */
void printErr(char* err_type, char* err_str)
{	
	FILE *log_err;
	log_err = fopen("LogErr.ini", "a+");
	fprintf(log_err, "[%s]\n%s\n\n", err_type, err_str);
	fclose(log_err);
	printf("Erreur [Voir le fichier de log pour plus de precisions]\n");
	putchar('\7');
}

/* Renvoie le nombre de caractères d'un fichier texte */
int fcountc(FILE* f)
{
	int c, n = 0;
	while((c = fgetc(f)) != EOF)
	{
		++n;
	}
	return n;
}

/* 
	Compare deux fichiers et renvoie:
		-1, si les fichiers sont de taille différentes
		0, si les fichiers sont complètement identiques
		si les fichiers sont identique à un n point, n est renvoyé
*/
int diff(FILE* f1, FILE* f2)
{
	if(fcountc(f1) != fcountc(f2)) { return -1; } 

	int c1 = fgetc(f1), c2 = fgetc(f2), cpt = 1;
	while(c1 != EOF && c2 != EOF)
	{
		if((char)c1 != (char)c2)
		{
			if(fcountc(f1) < fcountc(f2))
			{
				return fcountc(f2)-cpt;
			}
			else
			{
				return fcountc(f1)-cpt;
			}
		}
	
		c1 = fgetc(f1);
		c2 = fgetc(f2);
		cpt++;
	}
	return 0;
}