#include <stdio.h>
#include <math.h>

#define TOCHNOST 0.01//Точность
#define MAX_ITER 500//Максимальное количество итераций

int zeidel(int n, double A[n][n], double B[n], double PRIBL_X[n]) {
    double NEW_PRIBL[n];//Новое приближение
    int iter = 0;//Счетчик итераций
    double razn = TOCHNOST + 1;//разница для входа в цикл

    while (razn > TOCHNOST && iter < MAX_ITER) {//Цикл проверки
        razn = 0.0;//Сбрасываем разницу на каждой итерации
        for (int i = 0; i < n; i++) {
            NEW_PRIBL[i] = B[i];//Новое приближение равно B[i]
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    NEW_PRIBL[i] -= A[i][j] * PRIBL_X[j];//Вычитаем произведение неглавных элементов
                }
            }
            NEW_PRIBL[i] /= A[i][i];//Делим на главный элемент
            razn += fabs(NEW_PRIBL[i] - PRIBL_X[i]);//Считаем разницу
            PRIBL_X[i] = NEW_PRIBL[i];//Обновляем текущее приближение
        }
        iter++;//Увеличиваем счетчик итераций
    }

    if (iter == MAX_ITER) {//Проверка на максимальное количество итераций
        printf("Достигнуто максимальное количество итераций. Решение может быть неточным.\n");
    }
    return iter;
    
}

int main() {
    int n; // Размерность матрицы
    printf("Введите размерность матрицы: ");
    scanf("%d", &n); // Ручной ввод размерности
    double A[n][n];//Основная матрица
    double B[n];//Вектор правых частей
    double PRIBL_X[n];//Вектор приближений

    printf("Введите коэффициенты матрицы A:\n", n, n);//Ввод коэффициентов матрицы A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Введите вектор правых частей B:\n");//Вводим вектор правых частей В
    for (int i = 0; i < n; i++) {
        printf("B[%d] = ", i);
        scanf("%lf", &B[i]);
    }    
    for (int i = 0; i < n; i++) {//начальное приближение равно нулю
        PRIBL_X[i] = 0.0;
    }
    int iteration = zeidel(n, A, B, PRIBL_X);//Применение метода Зейделя
    

    printf("Решение системы:\n");
    for (int i = 0; i < n; i++) {
        printf("PRIBL_X[%d] = %lf\n", i, PRIBL_X[i]);
    }
    printf("Количество итераций: %d",iteration);
    
    return 0;
}