/* ptrindex.c - Copyright (C) 2016 Aaron Ryan Klingler
   returns the first index of a pointer in a pointer, -1 if none
*/

#include <string.h>

int ptrindex(char *a, char *b)
{
	if (argc != 3)
		return;

	char *result = strstr(a, b);
	if (result == NULL)
		return -1;
	else
		return (int) (result - a);
}
