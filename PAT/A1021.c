#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10008

int used[MAX];
int ufs[MAX];
int n;

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct list{
    Node *end;
    Node *start;
}List;

List Tree[MAX];

void ufs_init(int size){
    int i;
    for(i=0;i<size;i++){
        ufs[i] = i;
    }
}

int ufs_find(int a){
    if(ufs[a]!=a){
        return ufs[a] = ufs_find(ufs[a]);
    }
    return a;
}

int ufs_union(int a, int b){
    int u,v;
    u = ufs_find(a);v = ufs_find(b);
    if(u==v) return 1;
    else{
        ufs[u] = v;
    }
    return 0;
}

int ufs_count(int size){
    int i;
    int count=0;
    for(i=0;i<size;++i){
        ufs_find(i);
    }
    int temp[size];
    memset(temp, 0, sizeof(int)*size);
    for(i=0;i<size;++i){
        ++temp[ufs[i]];
    }
    for(i=0;i<size;++i){
        if(temp[i]){
            ++count;
        }
    }
    return count;
}

void push_back(List *list, int value){
    if(!list->start){
        list->start = (Node *)malloc(sizeof(Node));
        list->end = list->start;
    }else{
        list->end->next = (Node *)malloc(sizeof(Node));
        list->end = list->end->next;
    }
    list->end->value = value;
    list->end->next = NULL;
}

int slove(int prev, int h){
    int value;
    int max_h = h, temp_h;
    Node * temp;
    for(temp=Tree[prev].start;temp!=NULL;temp=temp->next){
        value = temp->value;
        if (used[value]) continue;

        used[value] = 1;
        temp_h = slove(value, h+1);
        used[value] = 0;

        if(temp_h > max_h){
            max_h = temp_h;
        }

    }
    return max_h;
}

int main(void){
    scanf("%d", &n);
    memset(Tree, 0, sizeof(List)*n);
    memset(used, 0, sizeof(int)*n);
    int i;
    int from, to;
    int error=0;
    ufs_init(n);
    for(i=0;i<n-1;++i){
        scanf("%d %d", &from, &to);
        --from;--to;
        error += ufs_union(from, to);
        if(!error){
            push_back(&Tree[from], to);
            push_back(&Tree[to], from);
        }

    }
    int count = ufs_count(n);
    if(count > 1 || error){
        printf("Error: %d components", count);
        return 0;
    }
    int res[MAX];
    int max=-1;
    for(i=0;i<n;++i){
        used[i] = 1;
        res[i] = slove(i, 0);
        used[i] = 0;
        if (res[i] > max) max = res[i];
    }
    for(i=0;i<n;++i){
        if (res[i] == max) printf("%d\n", i+1);
    }
    return 0;
}

