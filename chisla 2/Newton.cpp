#include "Newton.h"

// Функции, для которых мы решаем систему уравнений
double f1(vector<double> X) {
    return 2 * pow(X[0], 2) - X[0] * X[1] - 5 * X[0] + 1.0;
}
double f2(vector<double> X) {
    return X[0] + 3 * log10(X[0]) - pow(X[1], 2);
}

// Частные производные для исходных функций
double df1_dx1(vector<double> X) {
    return 4.0 * X[0] - X[1] - 5.0;
}
double df2_dx1(vector<double> X) {
    return 1.0 + 3.0 / (X[0] * log(10));
}
double df1_dx2(vector<double> X) {
    return -X[0];
}
double df2_dx2(vector<double> X) {
    return -2.0 * X[1];
}

vector<double> calculateNewton(vector<double> currentSolution, const double& epsilon1, const double& epsilon2, const int& maxIterations, const bool& print, const int& statsEvery) {
    if (print) {
        cout << "-------------------------------------------------\n";
        cout << "Начальное приближение: " << currentSolution[0] << " , " << currentSolution[1] << "\n\n";
    }
    for (int i = 0; i < maxIterations; i++) {
        double F1 = f1(currentSolution);
        double F2 = f2(currentSolution);
        vector<double> F = { -F1, -F2 };
        vector<double> delta_x;
        vector<double> storage(2);

        //вычисление матрицы Якоби
        vector<vector<double>> J(2, vector<double>(2));
        J[0][0] = df1_dx1(currentSolution);
        J[0][1] = df1_dx2(currentSolution);
        J[1][0] = df2_dx1(currentSolution);
        J[1][1] = df2_dx2(currentSolution);

        //вычисление невязки
        delta_x = calculate(J, F);

        if (delta_x.empty()) {
            cout << "Невозможно найти решение данным методом.";
            return {};
        }

        // Уточнение решения
        storage = currentSolution;
        storage[0] += delta_x[0];
        storage[1] += delta_x[1];

        //вычисление погрешности
        double delta1 = maximum({ abs(F1), abs(F2) }).first;
        double delta2 = maximum({ abs(delta_x[0]), abs(delta_x[1]) }).first;

        //вывод промежуточного значения
        if (print) {
            if (!(i % statsEvery)) {
                cout << "Итерация " << i + 1 << ":\n";
                cout << " delta1 = " << delta1 << "\n";
                cout << " delta2 = " << delta2 << "\n";
                cout << "     x1 = " << currentSolution[0] << "\n";
                cout << "     x2 = " << currentSolution[1] << "\n";
            }
        }

        currentSolution = storage;
        // Проверка критерия завершения итерации
        if (delta1 <= epsilon1 && delta2 <= epsilon2) {
            if (print) {
                cout << endl << "Решение найдено после " << i + 1 << " итераций." << endl;
                if (i % statsEvery) {
                    cout << " delta1 = " << delta1 << "\n";
                    cout << " delta2 = " << delta2 << "\n";
                }
                cout << "     x1 = " << storage[0] << endl;
                cout << "     x2 = " << storage[1] << "\n\n\n";
                break;
            }
        }
    }
    return currentSolution;
}