#pragma once
#include "Newton.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<double>>& matrix);

void fillMatrix(vector<double>& matrix);

void resizeMatrix(vector<vector<double>>& matrix, int newSize);

void resizeMatrix(vector<double>& matrix, int newSize);

vector<double> calculate(vector<vector<double>> matrixA, vector<double> matrixB);

void printMatrix(vector<vector<double>>& matrix);

void printMatrix(vector<double>& matrix);

vector<double> calculateNeviazku(vector<vector<double>> matrixA, vector<double> matrixB, vector<double> solution);

pair<double, int> maximum(const vector<double>& matrix);