#include "string.h"


int  string (String *this, char *str)
{
	size_t len;

	len = strlen(str)+1;
	this->str = malloc (len);
	memset(this->str, 0x00, sizeof(len));
	memcpy (this->str, str, len);
	this->str[len] = '\0';
	this->length = len-1;
	this->line =1;
	this->size=0;
	return 1;
}
int string_delloc (String *this)
{
	if(this->str != NULL)
	{
		free(this->str);
		this->length=0;
	}
	this->length=0;

	return 1;
}

int string_append(String *this, char *dest)
{
	size_t len, dest_len;

	len = this->length;
	dest_len = strlen(dest);
	len += dest_len;
	this->str =  realloc (this->str,  len);

	strcat (this->str, dest);
	this->str[len] = '\0';
	this->length=len;
	return 1;
}

int string_trim(String *this)
{
  char* begin;
  char *end;
  int i=0;

  begin=this->str;
  end = malloc(this->length);

  memset(end, 0x00, sizeof(end));
  while (*begin != '\0') {
    if ((isspace(*begin) || iscntrl(*begin))||(*begin==' ')||(*begin=='\t'))
      begin++;
    else {
      end[i] = *begin++;
	i++;
    }
  }

   free(this->str);

   this->str = malloc (i);
   memset(this->str, 0x00, sizeof(this->str));	
   memcpy (this->str, end, i);
  free(end);
   this->str[i] = '\0';
   this->length = i;
  return 1;
}

int string_tolower(String *this)
{
	int i;

	for(i=0; i<this->length; i++)
	{
		if(this->str[i] >= 65 && this->str[i] <= 90)
			this->str[i] += 32;
	}

	return 1;
}

int string_toupper(String *this)
{
	int i;

	for(i=0; i<this->length; i++)
	{
		if(this->str[i] >= 97 && this->str[i] <= 122)
			this->str[i] -= 32;
	}

	return 1;
}

int string_copy (String *this, String *dest)
{
	dest->length = this->length;
	
	dest->str = malloc (dest->length);

	memset(dest->str, 0x00, dest->length);
	memcpy (dest->str, this->str, dest->length);
	dest->str[dest->length] = '\0';

	return 1;
}