#include <stdio.h>
#include <math.h>
#include <float.h>

#define F_ONE(x) (x*x - 1.3*log(x + 0.5) - 2.8*x + 2.35)
#define F_TWO(x) (exp(x)*sin(x)*sin(x))

double sum(unsigned int n, double h);
double calc_radical();
double calc_integral();

double sum(unsigned int n, double h)
{
	double s = 0;
	for (unsigned int i = 0; i < n; i++)
	{
		s += F_TWO(h*(i + 0.5));
	}
	return s;
}

double calc_radical()
{
	double x = 0;
	double a = 1.7;
	double b = 2.7;

	double F_a = 0;
	double F_b = 0;
	double F_x = 0;
	float E = FLT_EPSILON * 2;

	while(1)
	{
		if ((b - a) < E)
			return a;
		F_a = F_ONE(a);
		F_b = F_ONE(b);
		x = (a*F_b - b*F_a) / (F_b - F_a);
		F_x = F_ONE(x);

		if (fabs(F_x) <= E)
			return x;
		((F_a > 0 && F_x > 0) || (F_a < 0 && F_x < 0)) ? (a = x) : (b = x);
	}
}

double calc_integral()
{
	double prevS;
	double nextS;
	double h = 0;
	unsigned int n = 10;

	h = 5.0 / n;
	prevS = h*sum(n, h);

	n *= 2;
	h = 5.0 / n;
	nextS = h*sum(n, h);

	while (fabs(nextS - prevS) > 5e-4)
	{
		n *= 2;
		h = 5.0 / n;
		prevS = nextS;
		nextS = h*sum(n, h);
	}
	return nextS;
}

void main()
{
	printf("Корень уравнения: %.9f\n\n", calc_radical());
	printf("Значение интеграла: %.5f\n\n", calc_integral());
}