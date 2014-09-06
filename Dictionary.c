#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

int main()
{
  again:
	int f = 0;
	fflush(stdin);

	FILE *fp;
	fp = fopen("Ox", "r");
	if (fp == NULL)
	{
		printf("Missing Module. Reinstall the Application\n");
		getch();
		return 1;
	}
	char *str;
	str = (char *)malloc(30);
	int i;
	printf("\nEnter word to Find its Meaning: ");
	fflush(stdin);
	gets(str);
	if (str[0] == '\"' || str[0] == '\'')
	{
		i = 1;
		if (str[0] == '\"')
		{
			while (str[i] != '\"')
			{
				str[i - 1] = str[i];
				i++;
			}
		}
		if (str[0] == '\'')
		{
			while (str[i] != '\'')
			{
				str[i - 1] = str[i];
				i++;
			}
		}
		str[i - 1] = ' ';
		str[i] = '\0';
	}
	str[0] = toupper(str[0]);
	char temp[2048];
	putchar('\n');
	char match[30];
	int results = 0;

	while (fgets(temp, 2048, fp) != NULL)
	{
		if ((strstr(temp, str)) != NULL)
		{
			for (i = 0; i < strlen(str); i++)
				match[i] = temp[i];

			match[i] = '\0';
			if (strcmp(str, match) == 0)
			{
				results++;
			}
		}
	}

	if (results > 1)
		printf("\n%d results found for %s\n\n", results, str);
	else
		printf("\n%d result found for %s\n\n", results, str);

	rewind(fp);
	
	while (fgets(temp, 2048, fp) != NULL)
	{
		if ((strstr(temp, str)) != NULL)
		{
			for (i = 0; i < strlen(str); i++)
				match[i] = temp[i];

			match[i] = '\0';
			if (strcmp(str, match) == 0)
			{
				printf("%s\n\n", temp);
				f = 1;
			}
		}
	}
	
	if (f == 0)
	{
		system("cls");
		printf("Match not Found. Try again\n");
		free(str);
		goto again;
	}
	else if (f != 1)
	{
		free(str);
		fclose(fp);
	}
	getch();
}
