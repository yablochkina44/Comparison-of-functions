#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define SIZE 4
#define SIZE_TAB 20
#define SIZE_TABLE 4
#define SIZE_STR 30

void num_to_str(char* str, double number)
{
	int l;

	snprintf(str, SIZE_STR, "%lf", number);

	l = strlen(str);

	for (int i = l; i < SIZE_STR - 1; i++)
	{
		str[i] = ' ';
	}

	str[SIZE_STR - 1] = '\0';
}
void table_head(char* tab)
{
	char tabl[SIZE_STR];
	char arr[SIZE_TABLE][20] = { "x", "f(x)", "my_f(x)", "error" };
	int l;

	for (int i = 0; i < SIZE_TABLE; i++)
	{
		printf("%s", arr[i]);

		l = strlen(arr[i]);
		tabl;
		for (int j = 0; j < SIZE_STR - l - 1; j++)
		{
			tabl[j] = ' ';
		}

		tabl[SIZE_STR - l - 1] = '\0';

		printf("%s", tabl);
	}

	printf("\n");
}
void table(double a, double b, double h, int toch, double (*foo)(double), double (*my_foo)(double, int))
{
	char tab[SIZE_TAB] = "   ";
	char str[30];
	double fun, my_fun, error;

	table_head(tab);

	for (double i = a; i < b + h - 0.000001; i += h)
	{
		fun = foo(i);
		my_fun = my_foo(i, toch);
		error = fabs(fun - my_fun);

		num_to_str(str, i);
		printf("%s", str);

		num_to_str(str, fun);
		printf("%s", str);

		num_to_str(str, my_fun);
		printf("%s", str);

		num_to_str(str, error);
		printf("%s\n", str);
	}
}

void menu()
{
	char arr_head[SIZE][30] = { "1. exp\n", "2. sin\n", "3. cos\n", "4. log\n" };

	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%s", arr_head[i]);
	}
}