#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

#define M_PI 3.1415926535897932384626433832795

double pow(double x, int m)
{
	int rez = 1;

	for (int i = 1; i <= m; i++) {
		rez *= x;
	}

	return rez;
}
int factorial(int m)
{
	int rez = 1;
	for (int i = 1; i <= m; i++)
	{
		rez *= i;
	}
	return rez;
}
double my_exp_bad(double x, int n)
{
	double rez = 0;
	for (int i = 1; i <= n; i++)
	{
		rez += pow(x, i) / factorial(i);
	}
	return rez;
}
double my_exp(double x, int n)
{
	double rez = 1;
	double a = 1;
	for (int i = 1; i < n; i++)
	{
		a = a * x / i;
		rez += a;
	}
	return rez;
}
double my_sin(double x, int n)
//a(i+1)=a(i)*(-1)*x*x/(2i)*(2i+1)
//привести значение x к диапазону [0,2*pi] цикл вайвл в котором от х вычитать 2пи или пи пока не попадем в диапазон от нуля до двух пи
//sin(2*pi*k+y)=sin(x)
{
	double a = x;
	double rez = x;

	while (x < 0 || x > 2 * M_PI)
	{
		if (x > 0)
			x = x - 2 * M_PI;
		else
			x = x + 2 * M_PI;
	}


	for (int i = 1; i < n; i++)
	{
		a = a * (-1 * x * x / (2 * i * (2 * i + 1)));
		rez += a;
	}

	return rez;
}
double my_cos(double x, int n)
{
	double a = 1;
	double rez = 1;

	while (x < 0 || x > 2 * M_PI)
	{
		if (x > 0)
			x = x - 2 * M_PI;
		else
			x = x + 2 * M_PI;
	}


	for (int i = 1; i < n; i++)
	{
		a = a * (-1 * x * x / ((2 * i + 1) * (2 * i + 2)));
		rez += a;
	}

	return rez;
}
double my_log(double x, int n)
//a(i)=x числитель i-го слагаемого
//a(i+1)=a(i)*x*(-1)
{
	x--;
	double rez = x;
	double a = x;

	for (int i = 2; i <= n; i++)
	{
		a = a * (-1) * x;
		rez += a / i;
	}
	return rez;
}
double my_log2(double x, int n)
//a(i)=x числитель i-го слагаемого
//a(i+1)=a(i)*x*(-1)
//ln(1+x/1-x)=2(x+x^3/3+x^5/5+...
//не обязательно 
{
	x = (x - 1) / (x + 1);

	double rez = x;
	double a = x;

	for (int i = 1; i < n; i++)
	{
		a = a * x * x;
		rez += a / (2 * i + 1);
	}
	rez *= 2;
	return rez;
}