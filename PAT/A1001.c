#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d",&a, &b);
    int sum = a + b;
    if(sum < 0){
        putchar('-');
        sum = -sum;
    }else if(!sum){
        putchar('0');
        return 0;
    }
    int string[8];
    int pos;
    for(pos=0;sum!=0;++pos){
        string[pos] = sum % 10;
        sum /= 10;
    }
    int decimal = pos;
    for(--pos;pos != -1;--pos){
        if(pos + 1 != decimal && !((pos + 1) % 3)){
            putchar(',');
        }
        putchar('0'+string[pos]);
    }
    return 0;
}
