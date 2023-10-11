#include "Source.h"

// Функции, для которых мы решаем систему уравнений
double f1(double x1, double x2) {
    return 2 * x1 * x1 - x1 * x2 - 5 * x1 + 1.0;
}
double f2(double x1, double x2) {
    return x1 + 3 * log10(x1) - x2 * x2;
}

// Частные производные для исходных функций
double df1_dx1(double x1, double x2) {
    return 4.0 * x1 + x2 - 5;
}
double df2_dx1(double x1, double x2) {
    return x1;
}
double df1_dx2(double x1, double x2) {
    return 1 + 3 / (x1 * log(10));
}
double df2_dx2(double x1, double x2) {
    return -2.0 * x2 * x2;
}