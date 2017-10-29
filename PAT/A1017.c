#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int come, cost;
}Node;

Node list[10008];
int window[108];
int n,k;

int cmp(const void *a, const void *b){
    return ((Node*)a)->come - ((Node*)b)->come;
}

int main(void){
    scanf("%d %d", &n, &k);
    int i,hh,mm,ss,cost;
    for(i=0;i<n;++i){
        scanf("%d:%d:%d %d",&hh, &mm, &ss, &cost);
        list[i].come = hh*3600 + mm*60 + ss;
        list[i].cost = cost*60;
    }
    qsort(list, n, sizeof(Node), cmp);
    int eight = 8*3600, seventeen = 17*3600;
    float wait = 0;
    int count = 0;
    memset(window, 0, sizeof(int)*k);
    int temp;
    for(i=0;i<n;++i){
        temp = 0;
        if(list[i].come < eight){
            temp = eight - list[i].come;
            list[i].come = eight;
        }

        int j,min=window[0], pos=0;
        for(j=1;j<k;++j){
            if(min > window[j]){
                min = window[j];
                pos = j;
            }
        }
        if(list[i].come>seventeen) break;
        if(list[i].come < min){
            wait += min - list[i].come + temp;
            window[pos] += list[i].cost;
        }else{
            if(!min)  wait += temp;
            window[pos] = list[i].come + list[i].cost;

        }
        ++count;
    }
    printf("%.1f", wait/count/60);
    return 0;
}
