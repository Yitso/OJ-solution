#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1005

int n, m, k, q;
int service[MAX];

typedef struct list{
    int length;
    int end_time;
    int head;
    int array[MAX];
}Node;

Node list[25];

void print_time(int time){
    if(time==-1){
        printf("Sorry\n");
        return;
    }
    int hh = 8 + time / 60;
    int mm = time % 60;

    if(hh<10) putchar('0');
    printf("%d:", hh);
    if(mm<10) putchar('0');
    printf("%d\n",mm);
}

int main(void){
    memset(list, 0, sizeof(Node)*25);
    scanf("%d %d %d %d",&n, &m, &k, &q);
    int i,j,u,v;
    int cost;
    int min_len, min_len_p;
    int min_next, min_next_p;
    int start_time;
    for(i=0;i<k;++i){
        scanf("%d",&cost);
        min_len = list[0].length - list[0].head;
        min_len_p = 0;
        min_next = list[0].array[list[0].head];
        min_next_p = 0;
        for(j=1;j<n;j++){
            if(min_len > list[j].length - list[j].head){
                min_len = list[j].length - list[j].head;
                min_len_p = j;
            }
            if(min_next > list[j].array[list[j].head]){
                min_next = list[j].array[list[j].head];
                min_next_p = j;
            }
        }
        if(min_len < m){
            list[min_len_p].end_time += cost;
            service[i] = list[min_len_p].end_time;
            list[min_len_p].array[list[min_len_p].length] = service[i];
            ++list[min_len_p].length;
        }else{
            start_time = list[min_next_p].end_time;

            list[min_next_p].end_time += cost;
            service[i] = list[min_next_p].end_time;
            list[min_next_p].array[list[min_next_p].length] = service[i];
            ++list[min_next_p].head;
            ++list[min_next_p].length;

            if(start_time >= 540){
                // 开始时间超过17点
                service[i] = -1;
            }
        }
    }
    int query, hh, mm;
    for(i=0;i<q;++i){
        scanf("%d",&query);
        print_time(service[query-1]);
    }
    return 0;
}
