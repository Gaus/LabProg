#include <stdio.h>
void main()
{
	int mas[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		mas[i] = -i;
		printf("mas[%i] = %i\n", mas[i], i);
	}
}