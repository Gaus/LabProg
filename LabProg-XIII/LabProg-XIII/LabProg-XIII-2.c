#include <stdio.h>
#include <math.h>
#include <float.h>

#define F_ONE(x) (x*x - 1.3*log(x + 0.5) - 2.8*x + 2.35)
#define F_TWO(x) (exp(x)*sin(x)*sin(x))
#define F_THREE(x) (exp(-2.0 * (2.0 / 3000.0 + 1.0 / 1000.0)*x) - 2.0 * exp(-2.0 * (1.0 / 3000.0 + 1.0 / 1000.0)*x) - 2.0 * exp(-(4.0 / 3000.0 + 1.0 / 1000.0)*x) + 4.0 * exp(-(2.0 / 3000.0 + 10.0 / 1000.0)*x))

double sum(double h);
double calc_radical();
double calc_integral();

double sum(double h)
{
	double x = 0;
	double s = 0;
	char k = 0;

	s = F_THREE(0) + F_THREE(10000.0);
	for (x = h; x < 10000.0; x += h)
	{
		k = !k;
		s += F_THREE(x) * (k + 1) * 2.0;
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

	while (1)
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
	unsigned int n = 1000;

	h = 10000.0 / n;
	prevS = (h/3)*sum(h);

	n *= 2;
	h = 10000.0 / n;
	nextS = (h / 3)*sum(h);

	while (fabs(nextS - prevS) > 5e-4)
	{
		n *= 2;
		h = 10000.0 / n;
		prevS = nextS;
		nextS = (h / 3)*sum(h);
	}
	return nextS;
}

void main()
{
	printf("Корень уравнения: %.9f\n\n", calc_radical());
	printf("Значение интеграла: %.5f\n\n", calc_integral());
}