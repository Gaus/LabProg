#include <stdio.h>
#include <string.h>

int k;
char s[100];
char new_s[100];
void spc_Calc(char *s);

void spc_Calc(char *s)
{
	k = 0;
	char *p;
	p = strchr(s, ' ');
	while (p)
	{
		p = strchr(p + 1, ' ');
		k++;
	}
}

void main()
{
	int len;
	int spc;
	int add_spc;
	char *ptr;

	FILE *in_Txt;
	in_Txt = fopen("Inp_File.txt", "rt");
	if (!in_Txt)
		perror("Ошибка");
	else
	{
		while (fgets(s, 127, in_Txt))
		{
			len = strlen(s);
			if (len > 100)
			{
				printf("Ошибка: Длина строки текста больше заданной\n");
				fclose(in_Txt);
				return 0;
			}
		}
		fseek(in_Txt, 0, SEEK_SET);
		while (fgets(s, 127, in_Txt))
		{
			ptr = strchr(s, '\n');
			if (ptr)
				*ptr = '\0';
			len = strlen(s);
			spc_Calc(s);
			ptr = strtok(s, "\n ");
			add_spc = (100 - (len - k)) % k;
			while (ptr)
			{
				strcat(new_s, ptr);
				spc = (100 - (len - k)) / k;
				while (spc)
				{
					strcat(new_s, " ");
					if (add_spc)
					{
						strcat(new_s, " ");
						add_spc--;
					}
					spc--;
				}
				ptr = strtok(NULL, "\n ");
			}
			puts(new_s);
			strcpy(new_s, "\0");
		}
		fclose(in_Txt);
	}
}