#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[256];

char is_to(char *s);

char is_to(char *s)
{
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		s[i] = (islower(s[i])) ? (toupper(s[i])) : (tolower(s[i]));
	}
	return s;
}

void main()
{
	int i = 0;
	char k = 0;
	char delim[] = "\n ";
	char *str;
	char *word[50] = { 0 };

	FILE *in_Txt;
	FILE *out_Txt;
	in_Txt = fopen("Inp_File.txt", "rt");

	if (!in_Txt)perror("Error");
	else
	{
		out_Txt = fopen("Out_File.txt", "wt");
		while (fgets(s, 127, in_Txt))
		{
			k = !k;
			if (!k)fputs(s, out_Txt);
			else
			{
				is_to(s);
				str = strtok(s, delim);
				while (str)
				{
					word[i] = str;
					str = strtok(NULL, delim);
					i++;
				}

				do
				{	
					i--;
					fputs(word[i], out_Txt);
					(i) ? fputs(" ", out_Txt) : fputs("\n", out_Txt);
				}
				while (i > 0);
			}
		}
		fclose(in_Txt);
		fclose(out_Txt);
	}
}