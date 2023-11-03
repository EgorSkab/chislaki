#pragma once
#include <cmath>

double trapezoid_method(double(&function)(double), const double& A, const double& B, const unsigned long& n);

double calculate_trapezoid(double(&function)(double), const double& A, const double& B, const double& epsilon);
