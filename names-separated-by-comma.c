/*
 *	Print names entered in a single string, 
 *	separated by commas, 
 *	using Dynamic Memory Functions
 *	Author: Malik Tekin
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initiated = 0;

char *InitiateString(char *str, int len)
{
		str = (char *)realloc(str, len + 1);
		return str;
}

char *AddName(char *str, char *name)
{
	int name_len = strlen(name);
	int str_len;
	int temp;
	
	if (!(initiated))
	{
		str = InitiateString(str, name_len);
		strcpy(str, name);
		initiated = 1;
	}
	else
	{
		str_len = strlen(str);
		temp = (char *)realloc(str, str_len + name_len + 3); // ',' + ' ' + '\0' -> 3 byte
		if (temp == NULL)
		{
			printf("Cannot allocate memory!!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			str = temp;
			strcat(str, ", ");
			strcat(str, name);
		}
	}
	
	return str;	
}

int main()
{
	char name[64];
	char *names = NULL;
	
	while(1)
	{
		printf("Please enter a name or \"exit\": ");
		gets(name);
		if(!(strcmp(name, "exit")))
			break;
		else
			names = AddName(names, name);
	}
	puts(names);
	
	return 0;
}
