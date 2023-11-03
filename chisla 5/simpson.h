#pragma once
#include <cmath>

double simpson_method(double(&function)(double), const double& A, const double& B, const unsigned long& m);

double calculate_simpson(double(&function)(double), const double& A, const double& B, const double& epsilon);
