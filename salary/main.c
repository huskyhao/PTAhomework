#include <stdio.h>

int main() {
    int salary,i;
    int num[7] = {0};
    int face[7] = {100,50,20,10,5,2,1};
    scanf("%d", & salary);
    for(i = 0; i < 7; i++) {
        num[i] = salary / face[i];
        salary %= face[i];
    }
    for(i = 0; i < 7; i++) {
        if(num[i] != 0) {
            printf("%d:%d\n", face[i], num[i]);
        }
    }

    return 0;
}
