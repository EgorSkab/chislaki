#pragma once
#include <cmath>

double trapezoid_method(double(&function)(double), const double& A, const double& B, unsigned long n);

double calculate_trapezoid(double(&function)(double), const double& A, const double& B, double epsilon);