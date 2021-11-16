#include<stdio.h>

void printFactor( int, int );

int main()
{
    int a,b,i ;

    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;

    return 0;
}
int isPrime(int n) {
    int i;
    int isPrime = 1;
    for(i = 2; i < n && isPrime == 1;i++) {
        if(n % i == 0) {
            isPrime = 0;
        }
    }
    return isPrime;
}
int findprime(int num) {
    int i;
    int charge = 1;
    for(i = 2; i < num && charge == 1; i++) {
        if(num % i == 0) {
            charge = 0;
        }
    }
    return i - 1;
}
void printFactor(int num, int first) {
    if(first == 1) {
        printf("%d=",num);
        first = 0;
    }
    if(isPrime(num) == 1) {
        printf("%d\n",num);
    } else {
        printf("%d*", findprime(num));
        printFactor(num / findprime(num),first);
    }

}