#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputString[1001], outputString[1001];
    int i, j, k;

    // Открытие файла для чтения
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла input.txt\n");
        return 1;
    }

    // Чтение строки из файла
    fgets(inputString, 1001, inputFile);
    fclose(inputFile);

    // Удаление пробелов из строки
    j = 0;
    for (i = 0; inputString[i] != '\0'; i++) {
        if (!isspace(inputString[i])) {
            outputString[j] = inputString[i];
            j++;
        }
    }
    outputString[j] = '\0';

    // Удаление повторяющихся символов
    for (i = 0; i < strlen(outputString); i++) {
        for (k = i + 1; k < strlen(outputString); k++) {
            if (outputString[i] == outputString[k]) {
                for (j = k; j < strlen(outputString); j++) {
                    outputString[j] = outputString[j + 1];
                }
                k--;
            }
        }
    }

    // Открытие файла для записи
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла output.txt\n");
        return 1;
    }

    // Запись результата в файл
    fprintf(outputFile, "%s", outputString);
    fclose(outputFile);

    return 0;
}