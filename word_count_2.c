#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// ��������  
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
        printf("�ַ�����%d\n", count);  
    } else if (strcmp(parameter, "-w") == 0) {  
        count = count_words(file);  
        printf("��������%d\n", count);  
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
    rewind(file); // �����ļ�ָ�뵽�ļ���ʼλ�ã��Ա������Լ�����ȡ  
    return count;  
}  
  
int count_words(FILE *file) {  
    int count = 0, in_word = 0;  
    int ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (isspace(ch) || strchr(",.", ch)) { // �ո�ˮƽ�Ʊ�������з��Լ����š����  
            if (in_word) {  
                in_word = 0;  
                count++;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
    if (in_word) { // ����ļ��Ե��ʽ�β��������һ�����ʼ���  
        count++;  
    }  
    rewind(file); // �����ļ�ָ�뵽�ļ���ʼλ��  
    return count;  
}

/*����һ��ע��*/
//��ע��һ�� 
