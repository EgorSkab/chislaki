#include "Header.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	vector<vector<float>> matrixA;
	vector<float> matrixB;
	int matrixSize;

	cout << u8"Введите размерность матрицы: ";
	cin >> matrixSize;

	resizeMatrix(matrixA, matrixSize);
	resizeMatrix(matrixB, matrixSize);

	cout << u8"Введите матрицу коэффициентов:" << endl;
	fillMatrix(matrixA);
	cout << u8"Введите дополнение матрицы (ответы):" << endl;
	fillMatrix(matrixB);

	vector<float> solution = calculate(matrixA, matrixB);
	for (int i = 0; i < solution.size(); i++) {
		cout << setw(11) << solution[i];
	}
	//printMatrix(matrixA);
}