#include <stdio.h>
unsigned int sum, i, j, m;
unsigned int num = 10;
unsigned int a[10][12];
void main()
{
	
	for (i = 0; i < 10; i++)
	for (j = 0; j < 12; j++)
	{
		m = num;
		do
		{
			sum += m % 10;
			m = m / 10;
		} 
		while (m > 0);
		if (sum == 10)
		{
			a[i][j] = num;
			printf("%d\t", a[i][j]);
		}
		else (j--);
		num++, sum = 0;
	}
}