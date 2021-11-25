#include <stdio.h>

int main() {
    int origin[10];
    int change[10];
    int trans,num,i;

    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        scanf("%d", &origin[i]);
    }
    for(i = 0; i < num; i ++) {
        scanf("%d", &change[i]);
    }
    for(i = 0; i < num; i++) {
        trans = origin[i];
        origin[i] = origin[change[i]];
        origin[change[i]] = trans;
    }
    for(i = 0; i < num; i++) {
        if(i == num - 1) {
            printf("%d\n", origin[i]);
        }else {
            printf("%d ",origin[i]);
        }
    }
    return 0;
}
