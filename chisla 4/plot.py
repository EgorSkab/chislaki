import matplotlib.pyplot as plt
import numpy as np
import array
import sys


def evaluate_polynomial(coefficients, x):
    result = 0
    for i, coef in enumerate(coefficients):
        result += coef * (x ** i)
    return result


def plot_polynomial(coefficients):
    x_values = np.linspace(0, 1, 100)  # Интервал x для построения графика
    y_values = [evaluate_polynomial(coefficients, x) for x in x_values]

    plt.plot(x_values, y_values)
    plt.title('Зависимость скорости течения от глубины реки')
    plt.xlabel('глубина')
    plt.ylabel('скорость')
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    coefficients = array.array('f', [])
    for param in sys.argv:
        if param == "plot.py":
            continue
        coefficients.append(float(param))

    plot_polynomial(coefficients)
