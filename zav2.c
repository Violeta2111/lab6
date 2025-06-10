#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функція для перевіреного введення цілого числа
int getInt(const char *msg) {
    int value;
    char c;
    while (1) {
        printf("%s", msg);
        if (scanf("%d%c", &value, &c) == 2 && c == '\n') {
            return value;
        } else {
            printf("❌ Некоректне значення! Введіть ціле число.\n");
            while (getchar() != '\n'); // очищення буфера
        }
    }
}

// Функція для заповнення матриці випадковими дійсними числами [-100; 100]
void generateMatrix(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ((float)(rand() % 20001) / 100) - 100; // [-100.00; 100.00]
        }
    }
}

// Функція для виводу матриці
void printMatrix(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    int rows, cols;

    // Введення розміру з перевіркою
    do {
        rows = getInt("Введіть кількість рядків (більше 0): ");
        if (rows <= 0) {
            printf("❌ Кількість рядків має бути більше 0!\n");
        }
    } while (rows <= 0);

    do {
        cols = getInt("Введіть кількість стовпців (більше 0): ");
        if (cols <= 0) {
            printf("❌ Кількість стовпців має бути більше 0!\n");
        }
    } while (cols <= 0);

    float matrix[rows][cols];

    generateMatrix(rows, cols, matrix);
    printf("\nЗгенерована матриця:\n");
    printMatrix(rows, cols, matrix);

    return 0;
}