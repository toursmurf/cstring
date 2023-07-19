#include <stdio.h>
#include "string.h"

//compile  gcc -o string_test  string.c string_test.c
int main(void)
{
	String str, str1;

	string(&str,  "abcdefg");

	printf("first str=>%s, length=>%d\n", str.str, str.length);

	string_append(&str, "hhgg");
	printf("string append str=>%s, length=>%d\n", str.str, str.length);

	string_append(&str, "  Nanumri");
	printf("string append str=>%s, length=>%d\n", str.str, str.length);

	string_append(&str, "  accef ");
	printf("string append str=>%s, length=>%d\n", str.str, str.length);

	string_append(&str, "   aabbbCCCCdddddd TTTTAAAAAsssssxyzZZzzzzYYyyy&&**^^&&");
	printf("string append   str=>%s, length=>%d\n", str.str, str.length);


	string_trim(&str);
	printf("split blank     str=>%s, str.length=>%d\n", str.str, str.length);

	string_tolower(&str);
	printf("change lower letter str=>%s, str.length=>%d\n", str.str, str.length);

	string_toupper(&str);
	printf("change upper letter str=>%s, str.length=>%d\n", str.str, str.length);

	string_copy(&str, &str1);
	printf("copy object    str1=>%s, strl.length=>%d\n", str1.str, str1.length);

	string_delloc(&str1); //free object
	string_delloc(&str); //free object

	return 1;
}