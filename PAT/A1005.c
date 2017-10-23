#include <stdio.h>
char num_string[10][10] = {"zero", "one", "two", "three",
                    "four", "five", "six", "seven", "eight", "nine"};
int main(void){
    int sum = 0;
    int ch;
    while((ch = getchar()) >= '0'){
        if(ch > '9') break;
        sum += ch - '0';
    }
    int num[10], pos=0;
    for(;sum!=0;sum/=10,++pos){
        num[pos] = sum % 10;
    }
    printf("%s", num_string[num[--pos]]);
    for(--pos;pos>=0;--pos){
        printf(" %s", num_string[num[pos]]);
    }
    return 0;
}