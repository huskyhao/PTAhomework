#include <stdio.h>

int main() {
    int num[20];
    int result = 0;
    int len,i;
    scanf("%d", &len);
    for(i = 0; i < len * 2; i++) {
        scanf("%d", &num[i]);
    }
    for(i = 0; i < len; i++) {
        result += num[i] * num[i + len];
    }
    printf("%d", result);
    return 0;
}
