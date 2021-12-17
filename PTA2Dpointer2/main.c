#include<stdio.h>
#define MAXLEN 110
int isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0
int getResult( char word[] ) ;
int main() {
    char word[MAXLEN] ;
    scanf("%s" , word ) ;
    printf("%d\n" , getResult( word ) );
    return 0;
}
/* 请在这里填写答案 */
int isPrime(int n) {
    int i;
    int res;
    int prime = 1;
    for(i = 2; i < n; i++) {
        if(n % i == 0) {
            prime = 0;
        }
    }
    if(prime) {
        res = n;
    } else {
        res = -1;
    }
    return res;
}
int getResult(char word[MAXLEN]) {
    int letter[26] = {0};
    int i,res = -1;
    int max,min;
    for(i = 0; word[i]; i++) {
        letter[word[i] - 'a']++;
    }//确定每个单词出现次数
    max = letter[0];
    for(i = 0; i < 26; i++) {
        if(letter[i] > max && letter[i]) {
            max = letter[i] ;
        }
    }//找到出现次数最多的
    min = max;
    for(i = 0; i < 26; i++) {
        if(letter[i] < min && letter[i]) {
            min = letter[i];
        }
    }//找到出现次数最少的
    if(isPrime(max - min)) {
        res = max - min;
    }
    return res;
}