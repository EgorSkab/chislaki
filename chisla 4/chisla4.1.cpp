﻿#include "Functions.h"
#include "Gauss.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	vector<pair<double, double>> F = readFromFile("json.txt", N);

	for (int i = 0; i < N; i++) {
		cout << F[i].first << "  " << F[i].second << endl;
	}

	int m = 0;
	cout << "Input the m value: ";
	cin >> m;

	vector<vector<double>> SUMX(m + 1);
	for (int i = 1; i <= m; ++i) {
		SUMX[i].resize(m + 1);
		for (int j = 0; j <= m; ++j) {
			double sum = 0;
			for (int k = 0; k < N; ++k) {
				sum += pow(F[k].first, i + j);
			}
			SUMX[i][j] = sum;
		}
	}
	SUMX[0].resize(m + 1);
	SUMX[0][0] = N;

	vector<double> PRAW(m + 1);
	for (int l = 0; l <= m; ++l) {
		for (int i = 0; i < N; ++i) {
			PRAW[l] += F[i].second * pow(F[i].first, l);
		}
	}

	vector<double> A = calculate(SUMX, PRAW);

	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << "   ";
	}

	string command = "python plot.py ";
	for (int i = 0; i < A.size(); ++i) {
		to_string(A[i])[to_string(A[i]).find('.')] = ',';
		command += to_string(A[i]) + ' ';
	}

	const char* str = command.c_str();
	system(str);
	delete[] str;
	return 0;
}
