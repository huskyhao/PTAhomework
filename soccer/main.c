#include <stdio.h>
#define  MAX        48
int getScore(char * s) ;

int main()
{
    char  input[MAX] ;
    int   score ;
    scanf("%s",input);
    score = getScore(input) ;
    printf("%d\n",score) ;

    return 0;
}

/* 请在这里填写答案 */
int getScore(char * s) {
    int i;
    int sum = 0;
    for(i = 0; *(s + i); i++) {
        switch (*(s + i)) {
            case 'W': sum += 3;break;
            case 'D': sum += 1;break;
            default: break;
        }
    }
    return sum;
}