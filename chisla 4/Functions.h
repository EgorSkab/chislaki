#pragma once
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<double, double>> readFromFile(const string& fileName, int& N);
