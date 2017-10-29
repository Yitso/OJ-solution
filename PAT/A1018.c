#include <stdio.h>
#include <string.h>
#define MAX 508

int c, n, p, m;
int road[MAX][MAX];
int front[MAX];
int used[MAX];
int bike[MAX];

typedef struct _p{
    int path[MAX], end;
}Path;

typedef struct node{
    int cost, require, back;
    Path path;
}Node;

int count =0;
Node slove(int prev, int cost, int have, int require, int hierarchy, Path path){
    Node temp;

    if(prev==p){
        temp.cost = cost;
        temp.require = require;
        temp.back = have;

        temp.path = path;

        return temp;
    }
    int i;
    int min_cost = 0xffffff;
    int min_require = 0xffffff;
    int min_back = 0xffffff;
    int min_pos = -1;
    Path min_path;
    int temp_require, temp_have;

    Path temp_path;

    for(i=1;i<=n;++i){
        temp_require = require;
        temp_have = have;

        temp_path = path;

        if(!used[i] && road[prev][i]){
            used[i] = 1;

            temp_have -= c/2 - bike[i-1];
            if(temp_have < 0){
                temp_require -= temp_have;
                temp_have = 0;
            }

            temp_path.path[++temp_path.end] = i;

            temp = slove(i, cost+road[prev][i], temp_have, temp_require, 1+hierarchy, temp_path);
            used[i] = 0;
            if(temp.cost < min_cost ||
               (temp.cost == min_cost && min_require > temp.require)||
               (temp.cost == min_cost && min_require == temp.require && min_back > temp.back)){
                min_cost = temp.cost;
                min_require = temp.require;
                min_back = temp.back;
                min_path = temp.path;
            }
        }
    }
    temp.cost = min_cost;
    temp.require = min_require;
    temp.back = min_back;
    temp.path = min_path;

    return temp;
}

int main(void){
    memset(road, 0, sizeof(int)*MAX*MAX);
    memset(used, 0, sizeof(int)*MAX);
    scanf("%d %d %d %d",&c, &n, &p, &m);
    int i;
    int a, b, cost;
    for(i=0;i<n;++i){
        scanf("%d", bike+i);
    }
    for(i=0;i<m;++i){
        scanf("%d %d %d", &a, &b, &cost);
        road[a][b] = cost;
        road[b][a] = cost;
    }
    Path path;
    path.path[0] = 0;
    path.end = 0;
    used[0] = 1;
    Node res = slove(0, 0, 0, 0, 1, path);
    printf("%d ", res.require);
    for(i=0;i<res.path.end;++i){
        printf("%d->", res.path.path[i]);
    }
    printf("%d %d", p, res.back);
    //printf("%d", res.)
    return 0;
}
