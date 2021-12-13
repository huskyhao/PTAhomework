#include <stdio.h>
#define SIZE 30
#define ROW 10
void input_array(char [][SIZE], int );
void get_order(int [],int );
void output(int [],char *);
int main() {
    int n;
    int order[ROW + 1] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    char sentence[ROW][SIZE];
    char * ptr;
    ptr = &sentence[0][0];
    scanf("%d",&n);
    input_array(sentence,n);
    get_order(order,n);
    output(order,ptr);
    return 0;
}
void input_array(char sentence[ROW][SIZE], int n) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%s", &sentence[i][0]);
    }
}
void get_order(int order[ROW],int n) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d",&order[i]);
    }
}
void output(int order[ROW],char *ptr) {
    int i = 0;
    while (order[i] != -1 && i < SIZE) {
        puts(ptr + order[i] * SIZE) ;
        i++;
    }
}