#include "functions.h"

void fillMatrix(vector<vector<float>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(vector<float>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
}

void resizeMatrix(vector<vector<float>>& matrix, int newSize) {
    matrix.resize(newSize);
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        matrix[i].resize(newSize);
    }
}

void resizeMatrix(vector<float>& matrix, int newSize) {
    matrix.resize(newSize);
}

vector<float> calculate(vector<vector<float>> matrixA, const vector<float>& matrixB) {
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

        float pivot = matrixA[i][i];
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
                float factor = matrixA[j][i];
                for (int k = i; k <= n; ++k) {
                    matrixA[j][k] -= factor * matrixA[i][k];
                }
            }
        }
        printMatrix(matrixA);
    }

    vector<float> solution;
    for (int i = 0; i < n; ++i) {
        solution.push_back(matrixA[i][n]);
    }

    return solution;
}

void printMatrix(const vector<vector<float>>& matrix) {
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

void printMatrix(const vector<float>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cout << setw(13) << matrix[i];
    }
    cout << endl;
}

vector<float> calculateNevizku(const vector<vector<float>>& matrixA, const vector<float>& matrixB, const vector<float>& solution) {
    vector<float> neviazka;

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

pair<float, int> maximum(const vector<float>& matrix) {
    float max = 0.0f;
    int n = matrix.size();
    int line = 0;
    pair<float, int> res;

    for (int i = 0; i < n; i++) {
        if (abs(max < matrix[i])) { max = matrix[i]; line = i; }
    }

    res.first = max;
    res.second = line;
    return res;
}

double relative_fault(vector<vector<float>> matrixA, const vector<float>& solution) {
    int n = matrixA.size();
    vector<float> matrixB(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixB[i] += matrixA[i][j] * solution[j];
        }
    }

    vector<float> new_solution = calculate(matrixA, matrixB);

    vector<float> delta;
    for (int i = 0; i < n; i++) {
        delta.push_back(abs(new_solution[i] - solution[i]));
    }

    return maximum(delta).first / maximum(solution).first;
}
