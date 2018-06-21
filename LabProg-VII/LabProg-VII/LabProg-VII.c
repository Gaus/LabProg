#include <stdio.h>
unsigned N;
double i;
double s;
double sum;
double series(double);
double series(double s)
{
	int j;
	for (j = 0; j <= i; j++)
	{
		s += 1 / (i*i + j + 1);
	}
	return s;
}
void main(void)
{
	printf("Введите N: ");
	scanf("%u", &N);
	for (i = 0; i <= N; i++)
	{
		sum += series(s);
	}
	printf("%f\n", sum);
}