#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets_wrapper(char *buffer, size_t buflen, FILE *fp)
{
    if (fgets(buffer, buflen, fp) != 0)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        return buffer;
    }
    return 0;
}

int main(void)
{
	FILE *f;
	int choice;
	char file_name[32];
	char text[1024];
	char ch, write;
	int i = 0;
	
	printf("\n1- Create new file or overwrite an existing file\n\
2- Add to existing file\n\
3- Read from existing file\n\
4- Exit\n\
\n\
Option: \
");

	scanf("%d",&choice);
	// (clears the input buffer) 
   	while ((getchar()) != '\n');
	
	while (choice != 4)
	{
		
		switch(choice)
		{
			case 1:
				printf("Enter file name: ");
				fgets_wrapper(file_name, sizeof(file_name),stdin);
			
				if ((f = fopen(file_name, "w")) == NULL)
				{
					printf("CANNOT CREATE FILE...\n");
					exit(EXIT_FAILURE);
				}
				printf("\nFile opened.\n\n");
				AGAIN:
				printf("Do you want to write something now? y/n: ");
				scanf("%c",&write);
				// (clears the input buffer) 
   				while ((getchar()) != '\n');
				switch(write)
				{
					case 'y':
						fgets(text, sizeof(text),stdin);
						for (i = 0; text[i] != '\0'; i++)
						{
							if (fputc(text[i], f) == EOF)
							{
								printf("cannot write file...\n");
								exit(EXIT_FAILURE);
							}
						}
						break;
					case 'n':
						break;
					default:
						goto AGAIN;
				}
				
				if (ferror(f))
				{
					printf("CANNOT WRITE FILE...\n");
					exit(EXIT_FAILURE);
				}
				
				fclose(f);
				printf("\nSuccess. File closed.\n\n");
				
				break;
			case 2:
				printf("Enter file name: ");
				fgets_wrapper(file_name, sizeof(file_name),stdin);
				
				if ((f = fopen(file_name, "a")) == NULL)
				{
					printf("CANNOT CREATE FILE...\n");
					exit(EXIT_FAILURE);
				}
				printf("\nFile opened.\n\n");
				fgets(text, sizeof(text),stdin);
				for (i = 0; text[i] != '\0'; i++)
				{
					if (fputc(text[i], f) == EOF)
					{
						printf("cannot write file...\n");
						exit(EXIT_FAILURE);
					}
				}
				
				if (ferror(f))
				{
					printf("CANNOT WRITE FILE...\n");
					exit(EXIT_FAILURE);
				}
				
				fclose(f);
				printf("\nSuccess. File closed.\n\n");
				
				break;
			case 3:
				printf("Enter file name: ");
				fgets_wrapper(file_name, sizeof(file_name),stdin);
				
				if ((f = fopen(file_name, "r")) == NULL)
				{
					printf("CANNOT READ FILE...\n");
					exit(EXIT_FAILURE);
				}
				printf("\nFile opened.\n\n");
				printf("############################\n");
				while ((ch = fgetc(f)) != EOF)
					putchar(ch);
				
				if (ferror(f))
				{
					printf("CANNOT READ FILE...\n");
					exit(EXIT_FAILURE);
				}
				printf("############################\n");
				fclose(f);
				printf("\nSuccess. File closed.\n\n");

				break;
			default:
				printf("\n!! You did not choose any option !!\n\n");
				break;
		}
		printf("\n1- Create new file or overwrite an existing file\n\
2- Add to existing file\n\
3- Read from existing file\n\
4- Exit\n\
\n\
Option: \
");
		choice = 0;
		scanf("%d",&choice);
    		// (clears the input buffer) 
   		while ((getchar()) != '\n');
	}
}
