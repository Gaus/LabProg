#include <stdio.h>
#include <string.h>

char s[256];

char del_vowel(char *s);

char del_vowel(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
		case 'A': s[i] = '_'; break;
		case 'E': s[i] = '_'; break;
		case 'I': s[i] = '_'; break;
		case 'O': s[i] = '_'; break;
		case 'U': s[i] = '_'; break;
		case 'Y': s[i] = '_'; break;
		case 'a': s[i] = '_'; break;
		case 'e': s[i] = '_'; break;
		case 'i': s[i] = '_'; break;
		case 'o': s[i] = '_'; break;
		case 'u': s[i] = '_'; break;
		case 'y': s[i] = '_'; break;
		default: break;
		}
	}
	return s;
	char *vowel = "AEOIUYaeoiuy";
	char *a = s;
	char *b = s;
	while(*b = *a++)
	{
		strchr(vowel, *b) ? NULL : b++;
	}
	return s;
}

void main()
{
	FILE *in_Txt;
	FILE *out_Txt;
	in_Txt = fopen("Inp_File.txt", "rt");

	if (!in_Txt)perror("Error");
	else
	{
		out_Txt = fopen("Out_File.txt", "wt");
		while (fgets(s, 127, in_Txt))
		{
			del_vowel(s);
			fputs(s, out_Txt);
		}
		fclose(in_Txt);
		fclose(out_Txt);
	}
}