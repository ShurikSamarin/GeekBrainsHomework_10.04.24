#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int main() {
    char input[MAX_SIZE];
    char longest_word[MAX_SIZE];
    int max_length = 0;

    FILE *input_file = fopen("input.txt", "r");
    fscanf(input_file, "%[^\n]", input); // Считываем строку до символа новой строки
    fclose(input_file);

    char *group = strtok(input, " "); // Разбиваем строку на группы по пробелам

    while (group != NULL) {
        int length = strlen(group);
        if (length > max_length) {
            max_length = length;
            strcpy(longest_word, group);
        }
        group = strtok(NULL, " ");
    }

    FILE *output_file = fopen("output.txt", "w");
    fprintf(output_file, "%s", longest_word);
    fclose(output_file);

    return 0;
}