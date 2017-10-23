#include <stdio.h>
#include <string.h>
#define MAX 102

int n, m;
int mat[MAX][MAX];
int node_child_count[MAX];
int hierarchy = 0;
int hierarchy_child_count[MAX];

void slove(int, int);

int main(void){
    memset(mat, 0, sizeof(int)*MAX*MAX);
    memset(node_child_count, 0, sizeof(int)*MAX);
    memset(hierarchy_child_count, 0, sizeof(int)*MAX);
    scanf("%d %d", &n, &m);
    int i, j, parent, child, count;
    for(i=0;i<m;++i){
        scanf("%d %d", &parent, &count);
        node_child_count[parent] = count;
        for(j=0;j < count; ++j){
            scanf("%d", &child);
            mat[parent][child] = 1;
        }
    }
    slove(1, 1);
    printf("%d", hierarchy_child_count[1]);
    for(i = 2;i <= hierarchy;++i){
        printf(" %d", hierarchy_child_count[i]);
    }
    return 0;
}

void slove(int parent, int h){
    if (h > hierarchy){
        hierarchy = h;
    }
    if(!node_child_count[parent]){
        ++hierarchy_child_count[h];
        return;
    }
    int i;
    for(i = 1;i <= n;++i){
        if(mat[parent][i]){
            slove(i, h+1);
        }
    }
}