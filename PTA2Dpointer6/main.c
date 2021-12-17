#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
char * s_gets(char [],int );
void input(char **,int );
void sort(char **,int );
void output(char **,int );
void toFree(char **,int );
int main() {
    int n;
    char ** pt;
    scanf("%d", &n);
    getchar();
    pt = (char **) malloc(sizeof (char*) * n);
    input(pt,n);
    sort(pt,n);
    output(pt,n);
    toFree(pt,n);
    return 0;
}
void input(char **st,int n) {
    char temp[MAX];
    char * pt;
    int i,len;
    for(i = 0; i < n; i++) {
        pt = s_gets(temp,MAX);
        len = (int )strlen(pt);
        st[i] = (char *) malloc(sizeof (char) * len + 1);
        strcpy(st[i],temp);
    }
}
char * s_gets(char* str,int n) {
    char * ret_val;
    int i = 0;
    ret_val = fgets(str, n, stdin);
    if(ret_val) {
        while(str[i] != '\n' && str[i] != '\0') {
            i++;
        }
        if(str[i] == '\n') {
            str[i] = '\0';
        } else {
            while(getchar() != '\n');
        }
    }
    return ret_val;
}
void sort(char **st, int n) {
    int top,seek;
    char * temp;
    for(top = 0; top < n - 1; top++) {
        for(seek = top + 1; seek < n; seek++) {
            if(strcmp( st[top] ,st[seek] ) > 0) {
                temp = st[top];
                st[top] = st[seek];
                st[seek] = temp;
            }
        }
    }
}
void output(char **st, int n) {
    int i;
    for(i = 0; i < n; i++) {
        puts(st[i]);
    }
}
void toFree(char **st,int n) {
    int i;
    for(i = 0; i < n; i++) {
        free(st[i]);
    }
    free(st);
}