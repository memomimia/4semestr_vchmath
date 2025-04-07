#include <stdio.h>

double newton(double x[], double y[], int n, double xi) {
    double result = 0;
    double f[n][n];//массив для хранения разделенных разностей
    
    // Инициализация таблицы разделенных разностей
    for (int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }
    
    // Вычисление разделенных разностей, i+1 - i 
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    result = f[0][0];
    double umnoj = 1;
    for (int j = 1; j < n; j++) {
        umnoj *= (xi - x[j-1]);
        result += f[0][j] * umnoj;
    }
    
    return result;//N(x)=f0+f0,1(x−x0)+f0,1,2(x−x0)(x−x1)
}

int main() 
{
    double x[] = {0.847, 1.546, 1.834, 2.647, 2.910};
    double y[] = {1.104, 1.042, 0.029, -0.344, -0.449};
    int n = sizeof(x) / sizeof(x[0]);
    double xi = 1.0;
    
    double ni = newton(x, y, n, xi);
    printf("Решение: N(%.1f) = %.4f\n", xi, ni);
    
    return 0;
}