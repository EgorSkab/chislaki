#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<float>>& matrix);

void fillMatrix(vector<float>& matrix);

void resizeMatrix(vector<vector<float>>& matrix, int newSize);

void resizeMatrix(vector<float>& matrix, int newSize);

vector<float> calculate(vector<vector<float>> matrixA, const vector<float>& matrixB);

void printMatrix(const vector<vector<float>>& matrix);

void printMatrix(const vector<float>& matrix);

vector<float> calculateNevizku(const vector<vector<float>>& matrixA, const vector<float>& matrixB, const vector<float>& solution);

pair<float, int> maximum(const vector<float>& matrix);
