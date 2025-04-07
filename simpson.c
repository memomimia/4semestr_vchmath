#include <stdio.h>
#include <math.h>

// Подынтегральная функция (пример: e^(-x^2))
double f(double x) {
    return exp(-x * x);
}

// Функция вычисления интеграла методом Симпсона
// с использованием представленных формул
double simpson_integral(double a, double b, int n) {
    if (n % 2 != 0) n++; // Убедимся, что n четное
    
    double h = (b - a) / n;
    double sum = f(a) + f(b); // y0 + yn
    
    // Суммируем по формуле Симпсона
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        // Коэффициенты 4 для нечетных и 2 для четных точек
        sum += (i % 2 == 1) ? 4 * f(x) : 2 * f(x);
    }
    
    return (h / 3) * sum;
}

// Функция вычисления интеграла с заданной точностью
double integrate_epsilon(double a, double b, double epsilon) {
    int n = 2; // Начальное количество интервалов (должно быть четным)
    double I_prev, I_current = simpson_integral(a, b, n);
    
    do {
        n *= 2;
        I_prev = I_current;
        I_current = simpson_integral(a, b, n);
    } while (fabs(I_current - I_prev) > epsilon);
    
    return I_current;
}

int main() {
    double a, b, epsilon;
    
    printf("Введите нижний предел интегрирования a: ");
    scanf("%lf", &a);
    printf("Введите верхний предел интегрирования b: ");
    scanf("%lf", &b);
    printf("Введите требуемую точность epsilon: ");
    scanf("%lf", &epsilon);
    
    if (a >= b) {
        printf("Ошибка: a должно быть меньше b!\n");
        return 1;
    }
    if (epsilon <= 0) {
        printf("Ошибка: epsilon должен быть положительным!\n");
        return 1;
    }
    
    double result = integrate_epsilon(a, b, epsilon);
    printf("\nРезультат интегрирования: %.6lf\n", result);
    
    return 0;
}