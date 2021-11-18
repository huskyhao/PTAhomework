#include <stdio.h>

int main() {
    int type[100];
    double average;
    int i,n,sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &type[i]);
    }
    for(i = 0; i < n; i++) {
        sum += type[i];
    }
    average = (double) sum / n;
    printf("%.2lf", average);

    return 0;
}
