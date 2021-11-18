#include <stdio.h>
int main() {
    int origin[1000];
    int index;
    int i;
    int num_input;
    int num_find;
    int in_it,num;

    scanf("%d", &num_input);
    for(i = 0; i < num_input; i++) {
        scanf("%d",&origin[i]);
    }

    scanf("%d",&num_find);
    for(index = 1; index <= num_find; index++) {
        in_it = 0;
        scanf("%d", &num);
        for(i = 0; i < num_input && in_it == 0; i++) {
            if(num == origin[i]) {
                in_it = 1;
            }
        }
        i--;
        if (in_it == 1) {
              if(i == 0) {
                  if(num_input == 1) {
                      printf("NULL\n");
                  } else {
                      printf("%d\n",origin[1]);
                  }
              }else
                  if(i == num_input - 1) {
                      printf("%d\n",origin[num_input - 2]);
                  }else{
                      printf("%d %d\n",origin[i - 1], origin[i + 1]);
                  }
        }else {
            printf("NULL\n");
        }
    }
    return 0;
}
