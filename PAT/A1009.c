#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int power;
    float value;
}Node;

int n, m, k=0;
Node output[105];
Node first[11];

int cmp(const void *a ,const void *b){
    return *(int *)a < *(int *)b;
}
int main(void){
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %f", &first[i].power, &first[i].value);
    }
    scanf("%d", &m);
    int power;
    float value;
    for(i=0;i<m;i++){
        scanf("%d %f", &power, &value);
        for(j=0;j<n;j++){
            output[k].power = first[j].power + power;
            output[k].value = first[j].value * value;
            ++k;
        }
    }
    qsort(output, k, sizeof(Node), cmp);
    power = -1;
    value = 0;
    int pos = 0;
    for(i=0;i<k;i++){
        if(power != output[i].power && power >= 0){
            if (abs(value) > 0.05){
                output[pos].power = power;
                output[pos++].value = value;
            }
            value = 0;
        }
        power = output[i].power;
        value += output[i].value;
    }
    if (abs(value) > 0.05){
        output[pos].power = power;
        output[pos++].value = value;
    }
    printf("%d", pos);
    for(i=0;i<pos;i++){
        printf(" %d %.1f", output[i].power, output[i].value);
    }
    return 0;
}
