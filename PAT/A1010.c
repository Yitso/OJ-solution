#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int digit_dict[256];
char digit_first[11], digit_second[11];

long long trans(char *num, int length, long long radix){
    int i;
    long long decimal=num[length-1], temp=radix;
    for(i=length-2;i>=0;--i){
        decimal += num[i]*temp;
        temp *= radix;
    }
    return decimal;
}

int main(){
    int i;
    for(i='0';i <= '9';++i){
        digit_dict[i] = i - '0';
    }
    for(i='a';i <= 'z';++i){
        digit_dict[i] = 10 + i - 'a';
    }
    long long tag, base_radix, aim_radix = 2;
    scanf("%s %s %lld %lld", digit_first, digit_second, &tag, &base_radix);
    int length_first = strlen(digit_first);
    int length_second = strlen(digit_second);

    for(i = 0;i<length_first;++i){
        digit_first[i] = digit_dict[digit_first[i]];
    }
    for(i = 0;i<length_second;++i){
        digit_second[i] = digit_dict[digit_second[i]];

    }
    char *base, *aim;
    int base_len, aim_len;

    base = tag==1?digit_first:digit_second;
    base_len = tag==1?length_first:length_second;
    aim = tag==1?digit_second:digit_first;
    aim_len = tag==1?length_second:length_first;

    long long base_decimal = trans(base, base_len, base_radix);
    long long left = 2, right = 0xfffffffffff, aim_decimal;
    for(i=0;i<aim_len;i++){
        if(left<aim[i]+1){
            left = aim[i]+1;
        }
    }
    do{
        aim_radix = (left + right)/2;
        aim_decimal = trans(aim, aim_len, aim_radix);
        if(aim_decimal < base_decimal){
            left = aim_radix;
        }else{
            right = aim_radix;
        }
    }while(llabs(right-left) > 1);

    if(trans(aim, aim_len, left) == base_decimal){
        printf("%lld", left);
    }else if(trans(aim, aim_len, right) == base_decimal){
        printf("%lld", right);
    }else{
        printf("Impossible");
    }
    return 0;
}
