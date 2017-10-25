#include <stdio.h>
#include <string.h>
#define MAX 1005

int G[MAX][MAX];
int n,m,k;

int set[MAX], mark[MAX];
int ufs_init(){
    memset(mark, 0, sizeof(int)*n);
    int i;
    for(i=0;i<n;++i) set[i] = i;
}
int ufs_find(int a){
    if(set[a]==a) return a;
    return set[a] = ufs_find(set[a]);
}
void ufs_union(int a, int b){
    if(ufs_find(a) == ufs_find(b)) return;
    set[a] = set[b];
}

int ufs_count(void){
    int i=0;
    for(;i<n;++i) ufs_find(i);
    int num[n];
    memset(num, 0, sizeof(int)*n);
    for(i=0;i<n;++i){
        ++num[set[i]];
    }
    int result=0;
    for(i=0;i<n;++i){
        if(num[i]) ++result;
    }
    return result;
}

int calc(int p){
    int i, j;
    ufs_init();
    for(i=0;i<n;++i){
        if(i==p) continue;
        for(j=0;j<n;++j){
            if(j==p) continue;
            if(G[i][j]){
                //printf("%d %d\n",i,j);
                ufs_union(i, j);
            }
        }
    }
    return ufs_count() - 2;
}


int main(void){
    memset(G, 0, sizeof(int)*MAX*MAX);

    scanf("%d %d %d",&n, &m, &k);
    int i,j;
    int from, to;
    for(i=0;i<m;++i){
        scanf("%d %d", &from, &to);
        --from;--to;
        G[from][to] = 1;
        G[to][from] = 1;
    }
    int p;
    for(i=0;i<k;++i){
        scanf("%d", &p);
        printf("%d\n", calc(p-1));
    }
    return 0;
}
