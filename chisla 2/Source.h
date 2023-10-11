#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функции, для которых мы решаем систему уравнений
double f1(double x1, double x2);
double f2(double x1, double x2);

// Частные производные для исходных функций
double df1_dx1(double x1, double x2);
double df2_dx1(double x1, double x2);
double df1_dx2(double x1, double x2);
double df2_dx2(double x1, double x2);
