#include <stdio.h>
int main() {
    int stack[200],input[200];
    int num;
    int i,j = 0;
    int trans;
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        scanf("%d", &input[i]);
    }
    for(i = 0; i < num; i++) {
        if(input[i] % 2 == 0) {
            stack[j] = input[i];
            j++;
        }
    }
    for(i = 0; i < num; i++) {
        if(input[i] % 2 != 0) {
            stack[j] = input[i];
            j++;
        }
    }
    for(j = 0; j < num - 1; j++) {
        printf("%d ", stack[j]);
    }
    printf("%d\n",stack[num - 1]);
    return 0;

}
