#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int countCharacters(const char* filename);
int countWords(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] input_file_name\n", argv[0]);
        return 1;
    }

    const char* parameter = argv[1];
    const char* inputFile = argv[2];

    int result;
    if (strcmp(parameter, "-c") == 0) {
        result = countCharacters(inputFile);
        printf("Characters: %d\n", result);
    } else if (strcmp(parameter, "-w") == 0) {
        result = countWords(inputFile);
        printf("Words: %d\n", result);
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    return 0;
}

int countCharacters(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

int countWords(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    bool inWord = false;
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    fclose(file);
    return count;
}