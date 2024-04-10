#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main() {
    char word1[MAX_SIZE];
    char word2[MAX_SIZE];
    char common_chars[26] = {0}; // массив для хранения количества встреч каждой буквы
    char output[MAX_SIZE];
    int i;

    FILE *input_file = fopen("input.txt", "r");
    fscanf(input_file, "%s %s", word1, word2);
    fclose(input_file);

    // Подсчитываем количество встреч каждой буквы в обоих словах
    for (i = 0; i < strlen(word1); i++) {
        common_chars[word1[i] - 'a']++;
    }
    for (i = 0; i < strlen(word2); i++) {
        common_chars[word2[i] - 'a']++;
    }

    FILE *output_file = fopen("output.txt", "w");
    for (i = 0; i < 26; i++) {
        if (common_chars[i] == 1) {
            fprintf(output_file, "%c ", 'a' + i);
        }
    }
    fclose(output_file);

    return 0;
}