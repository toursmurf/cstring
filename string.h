#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct  _string {
	char *str;
	size_t line;
	size_t length;
	size_t size;
}String;

