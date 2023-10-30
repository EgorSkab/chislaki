#include "Newton.h"
#include "Gauss.h"

int main() {
    setlocale(LC_ALL, "rus");

    calculateNewton({ 3, 2 }, 1e-9, 1e-6, 100, true, 5);
    calculateNewton({ 3, -2 }, 1e-9, 1e-6, 100, true, 5);
    calculateNewton({ 7645892376450937, 8472054623829841 }, 1e-9, 1e-6, 100, true, 10);
    calculateNewton({ 80654562035, -973456976525 }, 1e-9, 1e-6, 100, true, 10);
}