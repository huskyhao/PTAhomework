#include <stdio.h>
char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);

    if(p==NULL)    printf("NULL!\n");
    else    puts(p);

    return 0;
}

/* 请在这里填写答案 */
char *locatesubstr(char *str1,char *str2) {
    char *ret = NULL;
    int i,j;
    int found = 0;
    int test;
    for(i = 0;*(str1 + i) && !found;i++) {
        if(*(str1 + i) == *str2) {
            test = 1;
            for(j = 0; *(str2 + j); j++) {
                if(*(str2 + j) != *(str1 + i + j)) {
                    test = 0;
                }
            }
            if(test) {
                found = 1;
                ret = str1 + i;
            }
        }
    }

    return ret;
}
