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

// Функція для сортування одного рядка (сортуванням бульбашкою)
void sortRow(float row[], int cols) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                float temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

// Сортування всіх рядків матриці
void sortMatrixRows(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        sortRow(matrix[i], cols);
    }
}

int main() {
    srand(time(NULL)); // ініціалізація генератора випадкових чисел
    char choice;

    do {
        // Введення розмірів матриці
        int rows = getInt("Введіть кількість рядків: ");
        int cols = getInt("Введіть кількість стовпців: ");

        // Оголошення матриці
        float matrix[rows][cols];

        // Генерація та вивід початкової матриці
        generateMatrix(rows, cols, matrix);
        printf("\nПочаткова матриця:\n");
        printMatrix(rows, cols, matrix);

        // Сортування рядків матриці
        sortMatrixRows(rows, cols, matrix);
        printf("\nМатриця після сортування кожного рядка по зростанню:\n");
        printMatrix(rows, cols, matrix);

        // Меню: повторити чи завершити
        printf("\n1 - Виконати ще раз\n0 - Вийти\nВаш вибір: ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // очищення буфера

    } while (choice == '1');

    printf("Програму завершено.\n");
    return 0;
}
