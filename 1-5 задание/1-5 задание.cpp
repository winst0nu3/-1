//1 задание
#include <stdio.h>
#include <locale.h>
#define SIZE 20
int sumMaxMin(int* arr, int size) {
    int max, min;

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max - min;
}

void example1() {
    int numbers[SIZE] = { 6,12,3,4,18,5,7,8,17,10,11,2,13,15,14,16,9,18,19,5 };
    int diff;

    diff = sumMaxMin(numbers, SIZE);

    printf("Массив: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", numbers[i]);
        if (i < SIZE - 1) printf(", ");
    }

    printf("\nMax - min = %d\n", diff);
}

int main() {
    setlocale(LC_ALL, "Russian");
    example1();
    return 0;
}
//2 задание
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define SIZE 10

void example2() {
    int arr[SIZE];
    srand(time(NULL));


    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 199 - 99;
    }

    printf("Массив со случайными числами :\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");
    example2();
    return 0;
}
//3 задание
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void task3() {
    int n;
    setlocale(LC_ALL, "Russian");
    printf("Введите размер массива: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    free(arr);
}

int main() {
    task3();
    return 0;
}
//4 задание
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 3
#define COLS 4

void task4() {
    setlocale(LC_ALL, "Russian");
    int arr[ROWS][COLS];
    int colSums[COLS] = { 0 };

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            colSums[j] += arr[i][j];
        }
    }

    printf("\nСуммы по столбцам:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Столбец %d: %d\n", j + 1, colSums[j]);
    }
}

int main() {

    task4();
    return 0;
}
//5 задание
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct student {
    char famil[25];
    char name[20];
    char facult[20];
    int Nomzach;
};

void searchStudent(struct student* base, int size, const char* type, const char* value1, const char* value2) {
    int count = 0;

    printf("\nпоиск %s: ", type);
    if (strcmp(type, "по имени") == 0) printf("%s %s\n", value1, value2);
    else printf("%s\n", value1);

    for (int i = 0; i < size; i++) {
        int found = 0;

        if (strcmp(type, "по имени") == 0) {
            found = (strcmp(base[i].famil, value1) == 0 && strcmp(base[i].name, value2) == 0);
        }
        else if (strcmp(type, "по факультету") == 0) {
            found = (strcmp(base[i].facult, value1) == 0);
        }

        if (found) {
            printf("студент %d: %s %s, %s, №%d\n",
                ++count, base[i].famil, base[i].name, base[i].facult, base[i].Nomzach);
        }
    }

    if (count == 0) printf("студент не найден\n");
}

int main() {
    setlocale(LC_ALL, "Russian");
    struct student base[5] = {
        {"Гречушников", "Валя", "ИБ", 1},
        {"Конкина", "Софья", "ВТ", 2},
        {"Бывшева", "Арина", "ВТ", 3},
        {"Пупкин", "Петр", "ИБ", 4},
        {"Борунов", "Сергей", "ИБ", 5}
    };

    searchStudent(base, 5, "по имени", "Гречушников", "Валя");
    searchStudent(base, 5, "по факультету", "ИБ", "");
    searchStudent(base, 5, "по факультету", "ВТ", "");
    searchStudent(base, 5, "по факультету", "факультет", "");

    return 0;
}
