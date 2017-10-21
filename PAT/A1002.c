#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 1005
int cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(void){
    int a, b;
    float num[MAX_L];
    memset(num, 0, sizeof(float)*MAX_L);
    int mark[MAX_L];
    int mark_length = 0;
    scanf("%d", &a);
    int i;
    for(i=0;i < a;++i, ++mark_length){
        scanf("%d", mark + mark_length);
        scanf("%f", num + mark[mark_length]);
    }
    scanf("%d", &b);
    float temp;
    for(i = 0;i < b;++i, ++mark_length){
        scanf("%d", mark + mark_length);
        scanf("%f", &temp);
        num[mark[mark_length]] += temp;
    }
    qsort(mark, mark_length, sizeof(float), cmp);
    int prev = -1;
    int count = 0;
    int output_pow[mark_length];
    float output_value[mark_length];
    for(i=0;i<mark_length;i++){
        if(mark[i] == prev) continue;
        prev = mark[i];
        if(abs(num[prev]) < 0.01) continue;
        output_pow[count] = prev;
        output_value[count] = num[prev];
        ++count;
    }
    printf("%d", count);
    for(i=0;i< count;i++){
        printf(" %d %.1f", output_pow[i], output_value[i]);
    }
    return 0;
}
