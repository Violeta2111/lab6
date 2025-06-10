#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANDOM -100
#define MAX_RANDOM 100
#define MIN_SIZE 1
#define MAX_SIZE 100

// Перевірений ввід цілого числа з діапазоном
int inputIntInRange(const char *msg, int min, int max) {
    int value;
    char term;
    while (1) {
        printf("%s", msg);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            printf("Помилка! Введіть ціле число.\n");
            while (getchar() != '\n'); // очищення буфера
        } else if (value < min || value > max) {
            printf("Помилка! Число повинно бути в межах [%d; %d].\n", min, max);
        } else {
            return value;
        }
    }
}

// Генерація випадкової матриці
void generateMatrix(double matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = MIN_RANDOM + rand() % (MAX_RANDOM - MIN_RANDOM + 1);
        }
    }
}

// Вивід матриці
void printMatrix(double matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Сортування одного рядка
void sortRow(double row[], int cols) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                double temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

// Перевірка, що рядок відсортований
int isSorted(double row[], int cols) {
    for (int i = 0; i < cols - 1; i++) {
        if (row[i] > row[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int repeat;

    do {
        printf("=== Сортування рядків матриці ===\n");

        int rows = inputIntInRange("Введіть кількість рядків (1-100): ", MIN_SIZE, MAX_SIZE);
        int cols = inputIntInRange("Введіть кількість стовпців (1-100): ", MIN_SIZE, MAX_SIZE);

        double matrix[MAX_SIZE][MAX_SIZE];

        generateMatrix(matrix, rows, cols);

        printf("\nЗгенерована матриця:\n");
        printMatrix(matrix, rows, cols);

        for (int i = 0; i < rows; i++) {
            sortRow(matrix[i], cols);
            if (!isSorted(matrix[i], cols)) {
                printf("Увага! Рядок %d не відсортовано правильно.\n", i);
            }
        }

        printf("\nМатриця після сортування кожного рядка:\n");
        printMatrix(matrix, rows, cols);

        repeat = inputIntInRange("Хочете повторити програму? (1 - так, 0 - ні): ", 0, 1);

    } while (repeat == 1);

    printf("Програму завершено.\n");
    return 0;
}
