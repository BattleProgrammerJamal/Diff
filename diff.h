#ifndef DIFF_H
#define DIFF_H

	#include <stdlib.h>
	#include <stdio.h>
	
	void fToString(FILE* f);
	int fcountc(FILE* f);
	void printErr(char* err_type, char* err_str);
	int diff(FILE* f1, FILE* f2);

#endif