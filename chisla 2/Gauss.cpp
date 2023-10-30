#include "Gauss.h"

void fillMatrix(vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(vector<double>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
}

void resizeMatrix(vector<vector<double>>& matrix, int newSize) {
    matrix.resize(newSize);
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        matrix[i].resize(newSize);
    }
}

void resizeMatrix(vector<double>& matrix, int newSize) {
    matrix.resize(newSize);
}

vector<double> calculate(vector<vector<double>> matrixA, vector<double> matrixB) {
    int n = matrixA.size();
    //printMatrix(matrixA);

    for (int i = 0; i < n; ++i) {
        matrixA[i].push_back(matrixB[i]);
    }
    //printMatrix(matrixA);

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrixA[j][i]) > abs(matrixA[max_row][i])) {
                max_row = j;
            }
        }

        swap(matrixA[i], matrixA[max_row]);
        //printMatrix(matrixA);

        double pivot = matrixA[i][i];
        if (pivot == 0) {
            cout << u8"Невозможно решить систему (один из коэффициентов равен 0)";
            return {};
        }
        for (int j = i; j <= n; ++j) {
            matrixA[i][j] /= pivot;
        }
        //printMatrix(matrixA);

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = matrixA[j][i];
                for (int k = i; k <= n; ++k) {
                    matrixA[j][k] -= factor * matrixA[i][k];
                }
            }
        }
        //printMatrix(matrixA);
    }

    vector<double> solution;
    for (int i = 0; i < n; ++i) {
        solution.push_back(matrixA[i][n]);
    }

    return solution;
}

void printMatrix(vector<vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(11) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printMatrix(vector<double>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cout << setw(13) << matrix[i];
    }
    cout << endl;
}

vector<double> calculateNeviazku(vector<vector<double>> matrixA, vector<double> matrixB, vector<double> solution) {
    vector<double> neviazka;

    int n = matrixA.size();
    for (int i = 0; i < n; i++) {
        neviazka.push_back(0);
        for (int j = 0; j < n; j++) {
            neviazka[i] += matrixA[i][j] * solution[j];
        }
        neviazka[i] -= matrixB[i];
    }

    return neviazka;
}

pair<double, int> maximum(const vector<double>& matrix) {
    double max = 0.0f;
    int n = matrix.size();
    int line;
    pair<double, int> res;

    for (int i = 0; i < n - 1; i++) {
        if (abs(matrix[i] > matrix[i + 1])) { max = matrix[i]; line = i; }
        else { max = matrix[i + 1]; line = i + 1; }
    }

    res.first = max;
    res.second = line;
    return res;
}