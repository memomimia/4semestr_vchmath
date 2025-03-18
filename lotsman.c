#include <stdio.h>
#include <math.h>
#define TOCHNOST 1e-6  // Точность вычислений


double func(double x) {//Начальная функция
    return x*x*x-x-1;  // Пример: уравнение x^3 - x - 1 = 0
}
double dfunc(double x) {//Первая производная
    return 3*x*x-1 ;
}
double ddfunc(double x) {//Вторая производная 
    return 6*x;
}

double lotsman(double pribl, int *iteration) {//Функция метода лоцмана
    double x = pribl;
    int iter = 0;
    while (fabs(func(x)) > TOCHNOST) {
        double fx = func(x);
        double dfx = dfunc(x);
        double ddfx = ddfunc(x);
        if (fabs(dfx) < TOCHNOST) {//Проверка деления на 0
            printf("Производная близка к нулю, метод не применим.\n");
            return x;
        }
        double k = -dfx / ddfx;//свободный параметр  для повышения скорости сходимости процесса Ньютона.
        x = x - (2 * fx * dfx) / (2 * dfx * dfx - fx * ddfx);
        iter++;
        if (iter > 1000) { //Ограничение на количество итераций
            printf("Превышено максимальное количество итераций.\n");
            return x;
        }
    }
    *iteration = iter;
    return x;

}
int main() {
    double pribl = 1.0;  // Начальное приближение
    int iteration;
    double otvet = lotsman(pribl, &iteration);
    printf("Ответ найден за %d итераций\n", iteration);
    printf("Найденный корень: %.6f\n", otvet);
    return 0;
}
