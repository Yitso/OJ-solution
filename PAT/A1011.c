#include <stdio.h>

int main(void){
    int i, j;
    float num, temp, profit=0.65;
    int mark;
    char char_dict[3] = {'W', 'T', 'L'};
    for(i=0;i<3;i++){
        num = -1;
        for(j=0;j<3;j++){
            scanf("%f", &temp);
            if(num < temp){
                num = temp;
                mark = j;
            }
        }
        profit *= num;
        printf("%c ", char_dict[mark]);
    }
    printf("%.2f", (profit-1)*2);
    return 0;
}
