#include <stdio.h>
unsigned int i;
unsigned int N;
unsigned int R, S;
void main()
{
	printf("������ ������ �����: ");
	scanf("%u", &N);
	while (i <= N)
	{
		S += i;
		i++;
	}
	R = N*(N + 1) / 2;
	printf("����筠� �㬬� ����⮢: %u\n", S);
	printf("����஫쭮� ���祭��: %u\n", R);
	if (S == R)
	{
		printf("��⨭�");
	}
	else
	{
		printf("����");
	}
}