#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// 函数声明  
int count_chars(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return EXIT_FAILURE;  
    }  
  
    char *parameter = argv[1];  
    char *filename = argv[2];  
  
    FILE *file = fopen(filename, "r");  
    if (!file) {  
        perror(filename);  
        return EXIT_FAILURE;  
    }  
  
    int count = 0;  
    if (strcmp(parameter, "-c") == 0) {  
        count = count_chars(file);  
        printf("字符数：%d\n", count);  
    } else if (strcmp(parameter, "-w") == 0) {  
        count = count_words(file);  
        printf("单词数：%d\n", count);  
    } else {  
        fprintf(stderr, "Invalid parameter: %s\n", parameter);  
    }  
  
    fclose(file);  
    return EXIT_SUCCESS;  
}  
  
int count_chars(FILE *file) {  
    int ch, count = 0;  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  
    rewind(file); // 重置文件指针到文件开始位置，以便后面可以继续读取  
    return count;  
}  
  
int count_words(FILE *file) {  
    int count = 0, in_word = 0;  
    int ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (isspace(ch) || strchr(",.", ch)) { // 空格、水平制表符、换行符以及逗号、点号  
            if (in_word) {  
                in_word = 0;  
                count++;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
    if (in_word) { // 如果文件以单词结尾，则增加一个单词计数  
        count++;  
    }  
    rewind(file); // 重置文件指针到文件开始位置  
    return count;  
}

/*这是一个注释*/
//再注释一条 
