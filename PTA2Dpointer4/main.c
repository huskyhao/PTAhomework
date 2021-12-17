#include<stdio.h>
int getString( char * source , char *strPtr[] );
int main() {
    char str[100005];
    char *strPtr[1005]={0};
    int i, num ;
    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);
    return 0;
}
/* 请在这里填写答案 */
int getString( char *source ,char *strPtr[] ) {
    int number = 0;
    int in_word = 0;
    while(*source) {
        if(*source == ' ') {
            *source = '\0';
            in_word = 0;
            source++;
        } else
            if(in_word) {
                source++;
            } else{
                in_word = 1;
                *strPtr = source;
                strPtr++;
                number++;
            }
    }
    return number;
}