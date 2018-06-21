#include <stdio.h>
unsigned int i;
unsigned int N;
unsigned int R, S;
void main()
{
	printf("Введите конечный элемент: ");
	scanf("%u", &N);
	while (i <= N)
	{
		S += i;
		i++;
	}
	R = N*(N + 1) / 2;
	printf("Конечная сумма элементов: %u\n", S);
	printf("Контрольное значение: %u\n", R);
	if (S == R)
	{
		printf("Истина");
	}
	else
	{
		printf("Ложь");
	}
}