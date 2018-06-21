#include <stdio.h>

char s[256];
char len;
char ltr;
int sum;
void str_Calc(char *s);

void str_Calc(char *s)
{
	int i = 0;
	ltr = 0;
	sum = 0;
	while (s[i] != '\0')
	{
		(s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') ? (ltr++) : (ltr);
		sum += s[i];
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
}

void main()
{
	size_t fsize;

	FILE *in_Txt;
	FILE *out_Bin;

	in_Txt = fopen("Inp_File.txt", "rt");
	out_Bin = fopen("Out_File.bin", "wb");
	if (!in_Txt)
		perror("Ошибка");
	else
	{
		while (fgets(s, 256, in_Txt))
		{
			len = strlen(s);
			str_Calc(s);

			fwrite(&len, sizeof(char), 1, out_Bin);
			fwrite(&ltr, sizeof(char), 1, out_Bin);
			fwrite(&sum, sizeof(int), 1, out_Bin);
			fwrite(&s, sizeof(char), 1, out_Bin);

			printf("%s ", s);
			printf("%u ", len);
			printf("%u ", ltr);
			printf("%d\n", sum);
		}
		fclose(in_Txt);
		fseek(out_Bin, 0, SEEK_END);
		fsize = ftell(out_Bin);
		fclose(out_Bin);
		printf("\nРазмер файла Out_File.bin: %d Байт\n", fsize);
	}
}