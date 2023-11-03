#include "functions.h"

double function1(const double& x) { return sqrt(1 + pow(x, 3)); }
double function2(const double& x) { return 1 / (pow(log10(x), 2) + 1); }
double function3(const double& x) { return sqrt(x + pow(x, 3)); }
double function4(const double& x) { return (1 + pow(x, 2)) / (1 + pow(x, 3)); }
double function5(const double& x) { return sqrt(pow(sin(x), 2) / (1 + pow(x, 3))); }
double function6(const double& x) { return exp(x / 2) / sqrt(x + 1); }
double function7(const double& x) { return sqrt(1 + 2 * pow(x, 3)); }
double function8(const double& x) { return 1 / (pow(log10(x), 2) + 1); }
