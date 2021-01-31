#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ones[9] = {"bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
char *tens[9] = {"on","yirmi","otuz","kirk","elli","atmis","yetmis","seksen","doksan"};
char *others[6] = {"bin","milyon","milyar","trilyon","katrilyon","katrilyar"};
int digits3[7];

void NumToText(unsigned long val, char *text)
{
	int hundred;
	int ten;
	int one;
	int i, j;
	int check = 0;
	
	if(val == 0)
	{
		printf("sifir\n");
		exit(EXIT_SUCCESS);
	}
	
	for (i = 0; val > 0; i++)
	{
		digits3[i] = val % 1000;
		val /= 1000;
			
	} 
	
	*text = '\0';
	
	while(--i >= 0)
	{
		hundred = digits3[i] / 100;
		ten = (digits3[i] / 10) % 10;
		one = digits3[i] % 10;
		
		//printf("%d. three digits: %d hundred: %d ten: %d one: %d\n",i+1,digits3[i], hundred, ten, one);
		
		if (hundred)
		{
			if (hundred != 1)
			{
				strcat(text, ones[hundred - 1]);
				strcat(text, " ");
			}
			strcat(text, "yuz");
			if (ten || one)
				strcat(text, " ");
			check = 1;
				
		}
		if (ten)
		{
			strcat(text, tens[ten - 1]);
			if(one)
				strcat(text, " ");
			check = 1;
		}
		if (one)
		{
			if (i != 1 || digits3[i] != 1)
			{
				strcat(text, ones[one - 1]);
			}
			check = 1;
		}
		if(i != 0)
		{
			if (one || ten || hundred)
				strcat(text, " ");
			if (!(hundred == 0 && ten == 0 && one == 0))
				strcat(text, others[i - 1]);
			for (j = i - 1; j >= 0; j--)
				if (digits3[j] != 0 && check)
				{
					strcat(text, " ");
					check = 0;
					break;
				}
		}
	}
}

int main(void)
{
	char numText[300];
	unsigned long val;
	
	while(1)
	{
		printf("Enter value ('0' to exit): ");
		scanf("%lu",&val);
		NumToText(val, numText);
		printf("%s\n",numText);
	}
}
