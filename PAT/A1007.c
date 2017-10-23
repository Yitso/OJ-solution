#include <stdio.h>
#define MAX 10005
int seq[MAX];

int main(void){
    int n;
    scanf("%d", &n);
    int i, j;
    int negative_count = 0;
    for(i=0;i<n;++i){
        scanf("%d", seq+i);
        if(seq[i] < 0){
            ++negative_count;
        }
    }
    if(negative_count == n){
        printf("0 %d %d", seq[0], seq[n-1]);
        return 0;
    }
    int max_sum = -1, start, end, prev;
    for(i=0;i<n;++i){
        if(seq[i] < 0) continue;
        prev = 0;
        for(j=i;j<n;++j){
            prev += seq[j];
            if(max_sum < prev){
                max_sum = prev;
                start = i;
                end = j;
            }
        }
    }
    printf("%d %d %d", max_sum, seq[start], seq[end]);
    return 0;
}
