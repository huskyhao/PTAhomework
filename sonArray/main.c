#include <stdio.h>

int main() {
    int array_1[1000];
    int array_2[1000];
    int i,test;
    int input,j;
    int in_it = 0;
    for(i = 0; i < 1000; i++) {
        array_1[i] = -1;
        array_2[i] = -1;
    }
    i = 0;
    scanf("%d", &input);
    while(input != -1) {
        array_1[i] = input;
        i++;
        scanf("%d", &input);
    }
    i = 0;
    scanf("%d", &input);
    while(input != -1) {
        array_2[i] = input;
        i++;
        scanf("%d", &input);
    }

    for(i = 0; array_1[i] != -1 && in_it == 0; i++) {
        test = 1;
        if(array_1[i] == array_2[0]) {
            for(j = 0; array_2[j] != -1; j++) {
                if(array_1[i + j] != array_2[j]) {
                    test = 0;
                }
            }
            if(test == 1) {
                in_it = 1;
            }
        }
    }


    if(in_it == 1) {
        printf("ListB is the sub sequence of ListA.");
    } else {
        printf("ListB is not the sub sequence of ListA.");
    }
    return 0;
}
