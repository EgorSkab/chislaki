#include "functions.h"

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
	cout << u8"Вектор ответов: ";
	printMatrix(solution);

	vector<float> neviazka = calculateNevizku(matrixA, matrixB, solution);
	cout << u8"Вектор невязки: ";
	printMatrix(neviazka);

	pair<float, int> fault = maximum(neviazka);

	cout << u8"Норма: " << fault.first << endl;
	cout << u8"Относительная погрешность: " << fault.first / solution[fault.second] << endl;
}
