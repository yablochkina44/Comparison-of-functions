#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include"fun.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void main()
{

	int n;
	double start, end, step;
	double fun;
	int toch;
	double (*foo)(double) = NULL;
	double (*my_foo)(double, int) = NULL;

	setlocale(LC_ALL, "Rus");

	menu();
	scanf_s("%i", &n);

	switch (n) 
	{
	case 1:
		my_foo = my_exp;
		foo = exp;
		break;
	case 2:
		my_foo = my_sin;
		foo = sin;
		break;
	case 3:
		my_foo = my_cos;
		foo = cos;
		break;
	case 4:
		my_foo = my_log;
		foo = log;
		break;
	}

	printf("start, end, step: ");
	scanf_s("%lf %lf %lf", &start, &end, &step);

	printf("”кажите точность: ");
	scanf_s("%d", &toch);

	table(start, end, step, toch, foo, my_foo);


	FILE* file = fopen("test.txt", "w");


	fclose(file);


}