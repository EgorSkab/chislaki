#pragma once
#include <cmath>

double simpson_method(double(&function)(double), const double& A, const double& B, unsigned long m);

double calculate_simpson(double(&function)(double), const double& A, const double& B, double epsilon);