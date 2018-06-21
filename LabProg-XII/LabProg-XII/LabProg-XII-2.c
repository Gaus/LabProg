#include <stdio.h>
#include <math.h>

double s;
double x = 0;
char N = 0;

double series(char n, double arg);
float fact(char n);
int max_N();
void print_table(char n);

double series(char n, double arg)
{
	double a;
	a = (pow(arg, 2 * n) / fact(2 * n + 1));
	s = (n % 2) ? (s - a) : (s + a);
	return s;
}

float fact(char n)
{
	return (n < 2) ? 1 : n * fact(n - 1);
}

int max_N()
{
	double F = 0;
	double x1 = 2.3;
	double x2 = 4.9;
	int N1 = 1;
	int N2 = 1;

	s = 1;
	F = sin(x1) / x1;
	while (fabs(F - series(N1, x1)) > 1e-6)
	{
		N1++;
	}

	s = 1;
	F = sin(x2) / x2;
	while (fabs(F - series(N2, x2)) > 1e-6)
	{
		N2++;
	}
	return (N1 > N2) ? N1 : N2;
}

void print_table(char n)
{
	while (n)
	{
		series(n, x);
		n--;
	}
	printf("%.6Lf\t", s);
}

void main()
{
	N = max_N();

	printf("\t.0\t\t.1\t\t.2\t\t.3\t\t.4\t\t.5\t\t\t.6\t\t.7\t\t.8\t\t.9\n\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", i);
		for (int j = 0; j < 10 && x <= 5; j++)
		{
			s = 1;
			print_table(N);
			x += 0.1;
		}
		printf("\n\n");
	}
}