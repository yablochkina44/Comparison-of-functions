#ifndef OOPS_H
#define OOPS_H

double pow(double x, int m);
int factorial(int m);
double my_exp_bad(double x, int n);
double my_exp(double x, int n);
double my_sin(double x, int n);
double my_cos(double x, int n);
double my_log(double x, int n);
double my_log2(double x, int n);
void num_to_str(char* str, double number);
void table_head(char* tab);
void table(double a, double b, double h, int toch, double (*foo)(double), double (*my_foo)(double, int));
void menu();

#endif // !OOPS_H
#pragma once