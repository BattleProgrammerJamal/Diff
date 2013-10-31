#include "main.h"

int main(int argc, char **argv)
{
	if(argc <= 3)
	{
		FILE *f1, *f2;
		f1 = fopen(argv[1], "r+");
		f2 = fopen(argv[2], "r+");
		
		if(f1 != NULL && f2 != NULL)
		{
			if(diff(f1, f2) == 0)
			{
				printf("Les fichiers [%s] et [%s] sont identiques\n", argv[1], argv[2]);
			}
			else
			{
				if(diff(f1, f2) == -1)
				{
					printf("Les fichiers [%s] et [%s] sont differents\n", argv[1], argv[2]);
				}
				else
				{
					printf("Les fichiers [%s] et [%s] sont differents (%d caracteres de differences)\n", argv[1], argv[2], diff(f1, f2));
				}
			}
		}
		else
		{
			printErr("Initialisation de fichier", "Echec de l'initialisation des fichiers ! \n");
			return 1;
		}
		
		fclose(f1);
		fclose(f2);
	}
	else
	{
		printErr("Arguments de ligne de commande", "Nombre d'arguments insuffisant ! \n");
		return 1;
	}
	return 0;
}