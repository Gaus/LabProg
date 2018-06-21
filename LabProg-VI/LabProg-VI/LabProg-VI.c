#include <stdio.h>
unsigned perfnum(unsigned long long);
unsigned perfnum(unsigned long long n)
{
	unsigned s = 0;
	unsigned j;
	for (j = 1; j < n; j++)
	{
		if (n % j == 0)
		{
			s += j;
		}
	}
	return ((s == n) ? 1 : 0);
}
void main(void)
{
	unsigned n;
	unsigned N;
	printf("Введите N: ");
	scanf("%llu", &N);
	if (N < 6)
	{
		printf("Ошибка: таких чисел не существует");
	}
	else
	{
		for (n = 6; n <= N; n++)
		{
			if (perfnum(n) != 0)
			{
				printf("%llu\n", n);
			}
		}
	}
}