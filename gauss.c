#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, double matrix[n][n + 1]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int gauss(int n, double matrix[n][n + 1]) {
    int i, j, k;
    double glavn, temp;
    for (i = 0; i < n; i++) {//Цикл для прямого хода
        if (matrix[i][i] == 0) {
            for (j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    for (k = 0; k < n + 1; k++) {//Цикл свапа строк
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    break;
                }
            }
            if (j == n) {//Проверка, если определитель равен 0, то матрица вырожденная
                printf("Matrix virojdennaya\n");
                return 0;
            }
        }
        glavn = matrix[i][i];//Делим на некий делитель, чтобы получить 1
        for (j = i; j < n + 1; j++) {
            matrix[i][j] = matrix[i][j] / glavn;
        }
        for (j = i + 1; j < n; j++) {//Вычитание строк
            glavn = matrix[j][i];
            for (k = i; k < n + 1; k++) {
                matrix[j][k] -= glavn * matrix[i][k];
            }
        }
        printf("Step %d:\n", i + 1);//Вывод матрицы по шагам
        printMatrix(n, matrix);
    }
    for (i = n - 1; i >= 0; i--) {//Цикл для обратного хода
        for (j = i - 1; j >= 0; j--) {
            glavn = matrix[j][i];
            for (k = i; k < n + 1; k++) {
                matrix[j][k] -= glavn * matrix[i][k];
            }
        }
    }
    printf("Treygolnaya matrix:\n");//Выводим треугольную или конечную матрицу(если не получилась треугольная)
    printMatrix(n, matrix);
    return 1;
}
int main() {
    int n, i, j;
    printf("Vvedite size kvadratnoi matrix: ");
    scanf("%d", &n);
    double matrix[n][n + 1];
    printf("Vvedite elements rasshirennoi matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Isxodnaya matrix:\n");
    printMatrix(n, matrix);
    if (gauss(n, matrix)) {
        printf("Results:\n");
        for (i = 0; i < n; i++) {
            printf("x%d = %.1f\n", i + 1, matrix[i][n]);
        }
    }
    return 0;
}
