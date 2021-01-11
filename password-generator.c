#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	char ch;
	int pass_len;
	
	printf("Enter password length: ");
	scanf("%d",&pass_len);
	
	srand(time(0));
	
	for(i = 0; i < pass_len; i++) 
	{
		switch(rand() % 3)
		{
			case 0:
				ch = 'A' + rand() % 26;
				printf("%c",ch);
				break;
			case 1:
				ch = 'a' + rand() % 26;
				printf("%c",ch);
				break;
			case 2:
				ch = '0' + rand() % 10;
				printf("%c",ch);
				break;
		}
	}
	printf("\n");
}
