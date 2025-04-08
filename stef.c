#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6  // Заданная точность

// Функция f(x) = 3 - sqrt(x) - 0.5 * ln(x)
double f(double x) {
    return 3 - sqrt(x) - 0.5 * log(x);
}

// Метод Стеффенсена для нахождения корня уравнения.
double steffensen(double x0) {
    double x_next;
    
    while (1) {
        double fx = f(x0);
        double fx_plus_fx = f(x0 + fx);
        
        if (fabs(fx) < EPSILON)  // Если уже достаточно близко к 0, завершаем
            return x0;

        // Формула из предоставленного материала
        x_next = x0 - (fx * fx) / (f(x0) + fx_plus_fx - fx);

        if (fabs(x_next - x0) < EPSILON)  // Условие остановки
            return x_next;

        x0 = x_next;  // Переход к следующей итерации
    }
}

int main() {
    double a = 1.0, b = 3.0; // Интервал, содержащий корень
    double x0 = (a + b) / 2; // Начальное приближение (середина интервала)
    
    double root = steffensen(x0);
    
    printf("Найденный корень: %.6f\n", root);
    
    return 0;
}

