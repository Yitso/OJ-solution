#include <stdio.h>
#include <string.h>
#define MAX_L 502

int cost_mat[MAX_L][MAX_L];
int mark[MAX_L][MAX_L];
int n, m, c1, c2;
int rescue_list[MAX_L];

int count = 0;
int min_cost = 0xffffff, max_rescue = -1;

void slove(int now, int cost, int res);

int main(void){
    memset(mark, 0, sizeof(int)*MAX_L*MAX_L);
    memset(cost_mat, 0, sizeof(int)*MAX_L*MAX_L);
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    int i;
    for(i=0;i<n;++i){
        scanf("%d", rescue_list + i);
    }
    int from, to, cost;
    for(i=0;i<m;++i){
        scanf("%d %d %d", &from, &to, &cost);
        cost_mat[from][to] = cost;
        cost_mat[to][from] = cost;
    }
    slove(c1, 0, rescue_list[c1]);
    printf("%d %d",count, max_rescue);
    return 0;
}

void slove(int now, int cost, int rescue){
    if (now == c2){
    if (cost < min_cost){
        min_cost = cost;
      max_rescue = rescue;
      count = 1;
    }else if(cost == min_cost){
      ++count;
      if(rescue > max_rescue){
                max_rescue = rescue;
      }
    }
    return;
    }
    if(cost > min_cost)
        return; // ºÙ÷¶
  int i = 0;
    for(i = 0;i < n;++i){
        if(mark[now][i])
            continue;
        if(cost_mat[now][i]){
            mark[now][i] = 1;
            mark[i][now] = 1;
            slove(i, cost_mat[now][i]+cost, rescue+rescue_list[i]);
            mark[now][i] = 0;
            mark[i][now] = 0;
        }
    }
}
