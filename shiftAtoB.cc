#include <stdio.h>

#define MAX_SIZE 1001

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int i;

    FILE *input_file = fopen("input.txt", "r");
    fscanf(input_file, "%[^\n]", input); // Считываем строку до символа новой строки
    fclose(input_file);

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            output[i] = 'b'; // Заменяем 'a' на 'b'
        } else if (input[i] == 'b') {
            output[i] = 'a'; // Заменяем 'b' на 'a'
        } else if (input[i] == 'A') {
            output[i] = 'B'; // Заменяем 'A' на 'B'
        } else if (input[i] == 'B') {
            output[i] = 'A'; // Заменяем 'B' на 'A'
        } else {
            output[i] = input[i]; // Оставляем остальные символы без изменений
        }
    }
    output[i] = '\0'; // Добавляем завершающий нулевой символ

    FILE *output_file = fopen("output.txt", "w");
    fprintf(output_file, "%s", output);
    fclose(output_file);

    return 0;
}