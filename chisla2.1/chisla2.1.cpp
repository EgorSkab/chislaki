#include "Source.h"

int main() {
    setlocale(LC_ALL, "rus");
    double x01 = 3.0; // Начальное приближение для x
    double x02 = 2.0; // Начальное приближение для y

    double epsilon1 = 1e-9; // Параметр epsilon1
    double epsilon2 = 1e-6; // Параметр epsilon2
    int maxIterations = 100; // Максимальное количество итераций

    int k = 1; // Номер текущей итерации

    while (k <= maxIterations) {
        double F1 = f1(x01, x02);
        double F2 = f2(x01, x02);

        vector<vector<double>> J(2, vector<double>(2));
        J[0][0] = df1_dx1(x01, x02);
        J[0][1] = df1_dx2(x01, x02);
        J[1][0] = df2_dx1(x01, x02);
        J[1][1] = df2_dx2(x01, x02);

        vector<double> F = { F1, F2 };

        // Решение системы линейных уравнений J * delta_x = -F
        vector<double> delta_x(2);
        delta_x[0] = (J[1][1] * F[0] - J[0][1] * F[1]) / (J[0][0] * J[1][1] - J[0][1] * J[1][0]);
        delta_x[1] = (J[0][0] * F[1] - J[1][0] * F[0]) / (J[0][0] * J[1][1] - J[0][1] * J[1][0]);

        // Уточнение решения
        x01 -= delta_x[0];
        x02 -= delta_x[1];

        // Вычисление delta1 и delta2
        double delta1 = fabs(delta_x[0]);
        double delta2 = fabs(delta_x[1]);

        cout << "Итерация " << k << ":\n";
        cout << "delta1 = " << delta1 << "\n";
        cout << "delta2 = " << delta2 << "\n";
        cout << "x1 = " << x01 << "\n";
        cout << "x2 = " << x02 << "\n";

        // Проверка критерия завершения итерации
        if (delta1 < epsilon1 && delta2 < epsilon2) {
            cout << "Решение найдено после " << k << " итераций." << endl;
            cout << "x1 = " << x01 << endl;
            cout << "x2 = " << x02 << endl;
            break;
        }

        k++; // Переход к следующей итерации
    }
    //cout << "Достигнуто максимальное количество итераций. Решение не найдено." << endl;
}
