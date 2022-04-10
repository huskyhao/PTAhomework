#include <stdio.h>
#include <ctype.h>
void Task1(FILE *);
void Task2(FILE *);
void Task3(FILE *);
int main() {
    int mode;
    FILE* fp = NULL;
    fp = fopen("dict.dic","r");
    scanf("%d",&mode);
    switch (mode) {
        case 1:
            Task1(fp);
            break;
        case 2:
            Task2(fp);
            break;
        case 3:
            Task3(fp);
        default:
            break;
    }
    return 0;
}
void Task1(FILE* fp) {
    int ch;
    int capital,lowercase,digit,others;
    capital = lowercase = digit = others = 0;
    ch = fgetc(fp);
    while(ch != EOF) {
        if(isupper(ch)) {
            capital++;
        } else
            if(islower(ch)) {
                lowercase++;
            } else
                if(isdigit(ch)) {
                    digit++;
                } else{
                    others++;
                }
        ch = fgetc(fp);
    }
    printf("Task1:\ncapital: %d\nlowercase: %d\ndigit: %d\nothers: %d",
           capital,lowercase,digit,others);
}
void Task2(FILE* fp) {
    int ch;
    int line_len,longest,shortest,count;
    line_len = longest = shortest = count = 0;
    ch = fgetc(fp);
    while(ch != EOF) {
        if(ch != '\n') {
            count++;
        } else {
            line_len++;
            if(longest == 0 && shortest == 0) {
                longest = shortest = count;
            } else {
                if(count > longest) {
                    longest = count;
                }
                if(count < shortest) {
                    shortest = count;
                }
            }
            count = 0;
        }
        ch = fgetc(fp);
    }
    printf("Task2:\nline: %d\n%d characters in max line.\n"
           "%d characters in min line.",line_len,longest,shortest);
}
void Task3(FILE* fp) {
    int Upper[26] = {},Lower[26] = {};
    int ch;
    int i;
    ch = fgetc(fp);
    while (ch != EOF) {
        if(isupper(ch)) {
            Upper[ch - 'A']++;
        }
        if(islower(ch)) {
            Lower[ch - 'a']++;
        }
        ch = fgetc(fp);
    }
    printf("Task3:\nCAPITAL:\n");
    for(i = 0; i < 26; i++) {
        printf("%c:%d\n",'A' + i,Upper[i]);
    }
    printf("LOWERCASE:\n");
    for(i = 0; i < 26; i++) {
        printf("%c:%d\n",'a' + i,Lower[i]);
    }
}