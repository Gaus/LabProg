#include <stdio.h>
unsigned int a;
unsigned long long b, c, d;
unsigned long long a28;
int x, y, z;
int min, max;
void main()
{
	printf("������ a: ");
	scanf("%d", &a);
	b = a*a, c = b*b, d = c*c, a28 = d*d*d*c;
	printf("�������: %llu\n\n", a28);

	printf("������ x, y, z: ");
	scanf("%d %d %d", &x, &y, &z);
	max = (x > y && x > z) ? x : ((y > x && y > z) ? y : z);
	min = ((x + y + z) / 2 < x*y*z) ? (x + y + z) / 2 : x*y*z;
	min = min*min + 1;
	printf("�������: %d, %d\n", max, min);
}