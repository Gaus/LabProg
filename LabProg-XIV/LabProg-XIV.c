#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (exp(2.0 / 3.0 * log(fabs(x + 2))) - exp(2.0 / 3.0 * log(fabs(x - 2))))
#define my exp(2.0 / 3.0 * log(4))

void gout_Display();
void gout_File();

void gout_Display()
{
#define dy exp(2.0 / 3.0 * log(4)) / 12.0
#define dx (3.0 + 2.5) / 77.0

	double y;
	double x;
	char i = 0;
	char j = 0;
	while (i < 42)
	{
		printf(" ");
		i++;
	}
	printf("%cY\n", 24);
	for (y = my; y >= -my; y -= dy)
	{
		i = 0;
		for (x = -3; x <= 2.5; x += dx)
		{
			if (fabs(y - f(x)) < 0.04)
				printf("*");
			else
			{
				(j == 12) ? printf("-") : ((i == 42) ? printf("|") : printf(" "));
			}
			i++;
		}
		(j == 12) ? printf("%cX\n", 26) : printf("\n");
		j++;
	}

#undef dy
#undef dx
}

void gout_File()
{
#define dy 2*exp(2.0 / 3.0 * log(4)) / 80.0
#define n (40*f(x)/exp(2.0 / 3.0 * log(4)))
#define dx (3.0 + 2.5) / 59.0

	double y;
	double x;
	char i = 0;
	char j = 0;
	char spc = 0;
	FILE *out_G;
	out_G = fopen("Bar_Chart.txt", "wt");
	if (!out_G)
		perror("Error");
	else
	{
		fprintf(out_G, "            -2      -1.5    -1     -0.5      0     0.5      1     -1.5      2           \n");
		fprintf(out_G, "----------------------------------------------------------------------------------------\n");

		for (x = -3; x <= 2.5; x += dx)
		{
			for (y = -my; y < my; y += dy)
			{
				if (fabs(y - f(x)) < 0.03)
				{
					i = n;
					if (f(x) < 0)
					{
						spc = 38 + i;
						while (spc)
						{
							fprintf(out_G, " ");
							spc--;
						}
						fprintf(out_G, "%.4f", f(x));
						while (i <= 0)
						{
							fprintf(out_G, "|");
							i++;
						}
					}
					else
					{
						spc = 45;
						while (spc)
						{
							fprintf(out_G, " ");
							spc--;
						}
						while (i)
						{
							fprintf(out_G, "|");
							i--;
						}
						fprintf(out_G, "%.4f", f(x));
					}
					break;
				}
			}
			fprintf(out_G, "\n");
		}
	}
	fclose(out_G);

#undef dy
#undef ly
#undef dx
}

void main()
{
	gout_Display();
	gout_File();
}