#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[1000];
    int array[1000], count = 0;

    // Открываем файл для чтения
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Считываем строку из файла
    fscanf(fp, "%[^\n]", input);
    fclose(fp);

    // Извлекаем числа из строки и помещаем их в массив
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            array[count++] = atoi(&input[i]);
            while (isdigit(input[i + 1])) {
                i++;
            }
        }
    }

    // Сортируем массив array по возрастанию
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Открываем файл для записи
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Записываем отсортированный массив в файл
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d ", array[i]);
    }

    fclose(fp);

    return 0;
}