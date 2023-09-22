#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<float>> &matrix);

void fillMatrix(vector<float> &matrix);

void resizeMatrix(vector<vector<float>> &matrix, int newSize);

void resizeMatrix(vector<float> &matrix, int newSize);

vector<float> calculate(vector<vector<float>>& matrixA, vector<float>& matrixB);

void printMatrix(vector<vector<float>> matrix);