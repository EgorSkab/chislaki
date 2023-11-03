#pragma once
#include <cmath>

double simpson_method(double(&function)(const double&), const double& A, const double& B, const unsigned long& m);

double calculate_simpson(double(&function)(const double&), const double& A, const double& B, const double& epsilon);
