#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Перевірене зчитування числа
int getInt(const char *msg) {
    int value;
    char c;
    while (1) {
        printf("%s", msg);
        if (scanf("%d%c", &value, &c) == 2 && c == '\n') return value;
        printf("❌ Некоректне значення! Введіть ціле число.\n");
        while (getchar() != '\n');
    }
}

// Генерація
void generateMatrix(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = ((float)(rand() % 20001) / 100) - 100;
}

// Перевірка значень після генерації
int validateMatrix(int rows, int cols, float matrix[rows][cols]) {
    int valid = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] < -100.0 || matrix[i][j] > 100.0)
                valid = 0;
    return valid;
}

// Вивід
void printMatrix(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%7.2f ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int repeat;

    do {
        int rows, cols;
        do {
            rows = getInt("Введіть кількість рядків (більше 0): ");
            if (rows <= 0) printf("❌ Кількість рядків має бути > 0!\n");
        } while (rows <= 0);

        do {
            cols = getInt("Введіть кількість стовпців (більше 0): ");
            if (cols <= 0) printf("❌ Кількість стовпців має бути > 0!\n");
        } while (cols <= 0);

        float matrix[rows][cols];

        generateMatrix(rows, cols, matrix);

        // Перевірка значень
        if (!validateMatrix(rows, cols, matrix)) {
            printf("❌ Увага! В матриці знайдено значення поза межами [-100; 100]!\n");
        } else {
            printf("\n📊 Згенерована матриця (всі значення в межах [-100; 100]):\n");
        }

        printMatrix(rows, cols, matrix);

        repeat = getInt("\n🔁 Виконати програму ще раз? (1 - так, 0 - ні): ");
    } while (repeat == 1);

    printf("👋 Програму завершено.\n");
    return 0;
}
