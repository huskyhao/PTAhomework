#include <stdio.h>
#include <string.h>
void input (char [],int ,char *[]);
void sort_string(char *[], int );
void output(char *[], int );
int main() {
    int num;
    char str[100000];
    char *ptr[100];
    scanf("%d",&num);
    getchar();
    input(str, num, ptr);
    sort_string(ptr, num);
    output(ptr, num);
    return 0;
}
void input(char str[100000], int num , char * ptr[100]) {
    int i;
    int len = 0;
    for(i = 0; i < num ; i++) {
        gets(&str[len]);
        ptr[i] = &str[len];
        len += (int )strlen(&str[len]) + 1;
    }
}
void sort_string(char *ptr[100], int num) {
    char * temp;
    int top,seek;
    for(top = 0; top < num - 1; top++) {
        for(seek = top + 1; seek < num; seek++) {
            if(strcmp(ptr[top], ptr[seek]) > 0) {
                temp = ptr[top];
                ptr[top] = ptr[seek];
                ptr[seek] = temp;
            }
        }
    }
}
void output(char *ptr[100], int num) {
    int i;
    for(i = 0; i < num; i++) {
        puts(ptr[i]);
    }
}
