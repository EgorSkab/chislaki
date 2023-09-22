#include "Header.h"

void fillMatrix(vector<vector<float>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cin >> matrix[i][j];
		}
	}
}

void fillMatrix(vector<float>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		cin >> matrix[i];
	}
}

void resizeMatrix(vector<vector<float>>& matrix, int newSize) {
	matrix.resize(newSize);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(newSize);
	}
}

void resizeMatrix(vector<float>& matrix, int newSize) {
	matrix.resize(newSize);
}

vector<float> calculate(vector<vector<float>>& matrixA, vector<float>& matrixB) {
    int n = matrixA.size();

    for (int i = 0; i < n; ++i) {
        matrixA[i].push_back(matrixB[i]);
    }

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrixA[j][i]) > abs(matrixA[max_row][i])) {
                max_row = j;
            }
        }

        swap(matrixA[i], matrixA[max_row]);

        float pivot = matrixA[i][i];
        for (int j = i; j <= n; ++j) {
            matrixA[i][j] /= pivot;
        }

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                float factor = matrixA[j][i];
                for (int k = i; k <= n; ++k) {
                    matrixA[j][k] -= factor * matrixA[i][k];
                }
            }
        }
    }

    vector<float> solution;
    for (int i = 0; i < n; ++i) {
        solution.push_back(matrixA[i][n]);
    }

    return solution;
}

void printMatrix(vector<vector<float>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << setw(11) << matrix[i][j];
		}
		cout << endl;
	}
}