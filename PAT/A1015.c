#include <stdio.h>
#include <math.h>
int num, radix;
int decimal, temp;
int num_list[20];

int prime(int num){
    if(num==1 || !num ) return 0;
    if(num==2) return 1;
    int max = sqrt(num) +1;
    int i;
    for(i=2;i<max;i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

int main(void){
    int pos;
    while(scanf("%d", &num) && num >= 0){
        scanf("%d", &radix);
        decimal = 0;
        temp = radix;
        if(! prime(num)){
            printf("No\n");
            continue;
        }
         for(pos=0;num!=0;num/=radix,++pos){
            num_list[pos] = num % temp;
        }
        temp = 1;
        for(--pos;pos>=0;--pos, temp*=radix){
            decimal += num_list[pos] * temp;
        }
        if(prime(decimal)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
