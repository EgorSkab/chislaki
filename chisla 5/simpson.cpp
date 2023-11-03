#include "simpson.h"

double simpson_method(double(&function)(const double&), const double& A, const double& B, const unsigned long& n) { 
	unsigned int m = n / 2;	
	double h = (B - A) / n; 
	double f1 = 0;
	double f2 = 0;

	for (int i = 1; i <= m; ++i) {
		f1 += function(A + (double(i) * 2 - 1) * h);
	}

	for (int i = 1; i <= m - 1; ++i) {
		f2 += function(A + (double(i) * 2) * h);
	}

	return h * (function(A) + 4 * f1 + 2 * f2 + function(B)) / 3;
}

double calculate_simpson(double(&function)(const double&), const double& A, const double& B, const double& epsilon) {
	long n = 10;
	double intg1 = 0;
	double intg2 = simpson_method(function, A, B, n);

	while (abs(intg1 - intg2) > 15 * epsilon) {
		n *= 2;
		intg1 = intg2;
		intg2 = simpson_method(function, A, B, n);
	}

	return intg2;
}

//ïààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààààø
//òû òóò???
