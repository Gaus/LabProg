#include <stdio.h>

char s[256];
int sum_Calc();

int sum_Calc(char *s)
{
	int even = 0;
	int odd = 0;
	int i = 0;
	while (*(s + 2*i))
	{
		even += *(s + 2 * i + 1);
		odd += *(s + 2 * i);
		i++;
	}
	return (odd > even) ? (odd - even) : (even - odd);
}

void main()
{
	FILE *text;
	text = fopen("Inp_File.txt", "rt");
	if (!text)
		perror("Žè¨¡ª ");
	else
	{
		while (fgets(s, 256, text))
			printf("%d\n", sum_Calc(s));
		fclose(text);
	}
}