#include <stdio.h>
#include <string.h>
#define MAX_L 502

int cost_mat[MAX_L][MAX_L];
int mark[MAX_L][MAX_L];
int n, m, c1, c2;
int rescue_list[MAX_L];


int count = 0;
int min_cost = 0xffffff, max_rescue = -1;



typedef struct node{
    int cost;
    int position;
}Node;

Node priority_queue[MAX_L*MAX_L];
int queue_length = 0;

void push(Node);
Node pop(void);
void dijkstra(void);
void slove(int now, int cost, int res);
void print(){
    int i;
    printf("length :%d element:", queue_length);
    for(i=0;i < queue_length;i++){
        printf(" %d", priority_queue[i]);
    }
    putchar('\n');
}

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
    dijkstra();
    slove(c1, 0, rescue_list[c1]);
    printf("%d %d",count, max_rescue);
    return 0;
}
void push(Node element){
    int i = queue_length;
    for(;(priority_queue[i/2]).cost > element.cost && i!=0;i/=2){
        priority_queue[i] = priority_queue[i/2];
    }
    priority_queue[i] = element;
    ++queue_length;
}

Node pop(void){
    int i, child;
    Node top, last;
    --queue_length;
    top = priority_queue[0];
    last = priority_queue[queue_length];
    for (i = 0; (i + 1) * 2 - 1 <= queue_length; i = child) {
         child = (i + 1) * 2 - 1;
         if (child != queue_length && priority_queue[child + 1].cost
                 <  priority_queue[child].cost)
             child++;
         if (last.cost > priority_queue[child].cost)
             priority_queue[i] = priority_queue[child];
         else
             break;
     }
     priority_queue[i] = last;
     return top;
}

void dijkstra(){
    int distance[MAX_L];
    int used[MAX_L];
    int i;
    for(i=0;i<n;i++){
        distance[i] = 0xffffff;
    }
    memset(used, 0, sizeof(int)*MAX_L);
    distance[c1] = 0;
    Node node, temp;
    node.cost = 0;
    node.position = c1;
    push(node);
//    printf("operation: push(%d) ",node);
//    print();
    int node_pos, node_cost;
    while(queue_length){

        temp = pop();
//        printf("operation: pop(%d) ", temp);
//        print();
        node_pos = temp.position;
        node_cost = temp.cost;
        if(distance[node_pos] < node_cost || used[node_pos])
            continue;
        used[node_pos] = 1;
        for(i=0;i<n;i++){
            if(cost_mat[node_pos][i] && distance[i] > node_cost + cost_mat[node_pos][i]){
                distance[i] = node_cost + cost_mat[node_pos][i];
                temp.cost = distance[i];
                temp.position = i;
                push(temp);
//                printf("operation: push(%d) ", temp);
//                print();
            }

        }
    }
    min_cost = distance[c2];
//    printf("%d ", min_cost);
}

void slove(int now, int cost, int rescue){
    if(cost > min_cost)
        return; // ¼ôÖ¦
    if (now == c2){
        ++count;
        if(rescue > max_rescue){
            max_rescue = rescue;
        }
        return;
    }
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
