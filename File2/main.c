#include <stdio.h>
void GetInput(FILE*,int );
int main() {
    int times;
    FILE *fp = NULL;
    scanf("%d",&times);
    fp = fopen("dict.dic","rb");

    GetInput(fp, times);

    return 0;
}
void GetInput(FILE* fp, int times) {
    int i;
    char a,aa[5];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    for(i = 0; i < times; i++) {
        fread(&a,sizeof(a),1,fp);
        fread(&b,sizeof(b),1,fp);
        fread(&c,sizeof(c),1,fp);
        fread(&d,sizeof(d),1,fp);
        fread(&e,sizeof(e),1,fp);
        fread(&g,sizeof(g),1,fp);
        fread(&h,sizeof(h),1,fp);
        fread(aa,sizeof(a),5,fp);
        fread(bb,sizeof(b),5,fp);
        fread(cc,sizeof(c),5,fp);
        fread(dd,sizeof(d),5,fp);
        fread(ee,sizeof(e),5,fp);
        fread(gg,sizeof(g),5,fp);
        fread(hh,sizeof(h),5,fp);
    }
    printf("%c\n%hd\n%d\n%ld\n%lld\n%f\n%lf\n",a,b,c,d,e,g,h);
    printf("%s\n",aa);
    for(i = 0; i < 5; i++) {
        printf("%hd ",bb[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++) {
        printf("%d ",cc[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++) {
        printf("%ld ",dd[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++) {
        printf("%lld ",ee[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++) {
        printf("%f ",gg[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++) {
        printf("%lf ",hh[i]);
    }
    printf("\n");
}