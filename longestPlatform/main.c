#include <stdio.h>

int main() {
    int num[1000];
    int max_len = 1;
    int i,len;
    int number;
    scanf("%d", &number);
    for(i = 0; i < number; i++) {
        scanf("%d", &num[i]);
    }
    for(i = 0; i < number; i++) {
        len = 1;
        while(num[i] == num[i + 1]) {
            len++;
            i++;
        }
        if(len > max_len) {
            max_len = len;
        }
    }
    printf("%d",max_len);


    return 0;
}
