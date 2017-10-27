#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2005

typedef struct stu{
    char* id;
    int value;
    int rank;
}STU;
int n, k;

STU c[MAX], m[MAX], e[MAX], a[MAX];

int cmp(const void *a, const void *b){
    return ((STU*)a)->value < ((STU*)b)->value;
}
int main(void){
    scanf("%d %d", &n, &k);
    int i,j;
    for(i=0;i<n;++i){
        c[i].id = (char *)malloc(sizeof(char)*10);
        m[i].id = c[i].id;
        e[i].id = c[i].id;
        a[i].id = c[i].id;
        scanf("%s %d %d %d",c[i].id, &c[i].value, &m[i].value, &e[i].value);
        a[i].value = (c[i].value + m[i].value + e[i].value) / 3;
    }
    qsort(c, n, sizeof(STU), cmp);
    qsort(m, n, sizeof(STU), cmp);
    qsort(e, n, sizeof(STU), cmp);
    qsort(a, n, sizeof(STU), cmp);
    char temp[10];
    int find;
    int a_prev = -1, c_prev = -1, m_prev = -1, e_prev = -1;
    int a_rank = -1, c_rank = -1, m_rank = -1, e_rank = -1;
    for(i=0;i<n;i++){
        if(a[i].value != a_prev){
            a_prev = a[i].value;
            a_rank = i + 1;
        }
        a[i].rank = a_rank;
        if(c[i].value != c_prev){
            c_prev = c[i].value;
            c_rank = i + 1;
        }
        c[i].rank = c_rank;
        if(m[i].value != m_prev){
            m_prev = m[i].value;
            m_rank = i + 1;
        }
        m[i].rank = m_rank;
        if(e[i].value != e_prev){
            e_prev = e[i].value;
            e_rank = i + 1;
        }
        e[i].rank = e_rank;
    }
    char mark;
    int rank;
    for(i=0;i<k;++i){
        scanf("%s",temp);
        find = 0;
        rank = MAX;
        mark = 0;
        for(j=0;j<n;++j){
            if(!strcmp(a[j].id, temp)){
                if(rank >= a[j].rank){
                    rank = a[j].rank;
                    mark = 'A';
                }
                ++find;
            }
            if(!strcmp(c[j].id, temp)){
                if(rank > c[j].rank ||(rank==c[j].rank&&mark!='A')){
                    rank = c[j].rank;
                    mark = 'C';
                }
                ++find;
            }
            if(!strcmp(m[j].id, temp)){
                if(rank > m[j].rank ||(rank==m[j].rank&&mark=='E')){
                    rank = m[j].rank;
                    mark = 'M';
                }
                ++find;
            }
            if(!strcmp(e[j].id, temp)){
                if(rank > e[j].rank){
                    rank = e[j].rank;
                    mark = 'E';
                }
                ++find;
            }
            if(find==4) break;
        }
        if(!find){
            printf("N/A\n");
        }else{
            printf("%d %c\n", rank, mark);
        }
    }
    return 0;
}
