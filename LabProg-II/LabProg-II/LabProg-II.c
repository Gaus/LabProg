#include <stdio.h>
#include <limits.h>
void main (void)
{
	signed char a1 = CHAR_MAX;
	signed short int b1;
	signed int c1;
	signed long d1;

	unsigned char a2 = CHAR_MAX;
	unsigned short int b2;
	unsigned int c2;
	unsigned long d2;

	unsigned long a3 = LONG_MAX;
	unsigned int b3;
	unsigned short int c3;
	unsigned char d3;

	signed long a4 = LONG_MAX;
	signed int b4;
	signed short int c4;
	signed char d4;

	signed char a5 = CHAR_MIN;
	signed short int b5;
	signed int c5;
	signed long d5;

	unsigned char a6 = 0;
	unsigned short int b6;
	unsigned int c6;
	unsigned long d6;

	
	unsigned long a7 = 0;
	unsigned int b7;
	unsigned short int c7;
	unsigned char d7;

	signed long a8 = LONG_MIN;
	signed int b8;
	signed short int c8;
	signed char d8;

	signed char a9 = 85472;
	signed short int b9;
	signed int c9;
	signed long d9;

	unsigned char a10 = 85472;
	unsigned short int b10;
	unsigned int c10;
	unsigned long d10;

	unsigned long a11 = 85472;
	unsigned int b11;
	unsigned short int c11;
	unsigned char d11;

	signed long a12 = 85472;
	signed int b12;
	signed short int c12;
	signed char d12;

	signed int a = INT_MAX, n1;
	unsigned int b = UINT_MAX, n2;
	signed int c = INT_MIN, n3;
	unsigned int d = 0, n4;

	b1 = a1, c1 = b1, d1 = c1;
	b2 = a2, c2 = b2, d2 = c2;
	b3 = a3, c3 = b3, d3 = c3;
	b4 = a4, c4 = b4, d4 = c4;
	b5 = a5, c5 = b5, d5 = c5;
	b6 = a6, c6 = b6, d6 = c6;
	b7 = a7, c7 = b7, d7 = c7;
	b8 = a8, c8 = b8, d8 = c8;
	b9 = a9, c9 = b9, d9 = c9;
	b10 = a10, c10 = b10, d10 = c10;
	b11 = a11, c11 = b11, d11 = c11;
	b12 = a12, c12 = b12, d12 = c12;

	n1 = a + 1, n2 = b + 1, n3 = c - 1, n4 = d - 1;

	printf("signed char = %d > signed short int = %d > signed int = %d > signed long = %d\n", a1, b1, c1, d1);
	printf("unsigned char = %u > unsigned short int = %hu > unsigned int = %u > unsigned long = %lu\n", a2, b2, c2, d2);
	printf("unsigned long = %lu > unsigned int = %u > unsigned short int = %hu > unsigned char = %u\n", a3, b3, c3, d3);
	printf("signed long = %d > signed int=%d > signed short int=%d > signed char=%d\n\n", a4, b4, c4, d4);

	printf("signed char = %d > signed short int = %d > signed int = %d > signed long = %d\n", a5, b5, c5, d5);
	printf("unsigned char = %u > unsigned short int = %hu > unsigned int = %u >	unsigned long = %lu\n", a6, b6, c6, d6);
	printf("unsigned long = %lu > unsigned int = %u > unsigned short int = %hu > unsigned char = %u\n", a7, b7, c7, d7);
	printf("signed long = %d > signed int = %d > signed short int = %d > signed char = %d\n\n", a8, b8, c8, d8);


	printf("signed char = %d > signed short int = %d > signed int = %d > signed long = %d\n", a9, b9, c9, d9);
	printf("unsigned char = %u > unsigned short int = %hu > unsigned int = %u > unsigned long = %lu\n", a10, b10, c10, d10);
	printf("unsigned long = %lu > unsigned int = %u > unsigned short int = %hu > unsigned char = %u\n", a11, b11, c11, d11);
	printf("signed long = %d > signed int = %d > signed short int = %d > signed char = %d\n\n", a12, b12, c12, d12);

	printf("signed long = %d, signed int = %d, signed short int = %d, signed char = %d\n", n1, n2, n3, n4);	
}
