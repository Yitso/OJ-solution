#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int i, prev = 0, aim, time = 0;
    for(i=0;i<n;++i){
        scanf("%d", &aim);
        if(prev > aim){
            time += 5 + (prev - aim) * 4;
        }else{
            time += 5 + (aim - prev) * 6;
        }
        prev = aim;
    }
    printf("%d", time);
    return 0;
}
