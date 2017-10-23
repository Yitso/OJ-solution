#include <stdio.h>
#include <string.h>

int main(void){
    int m;
    scanf("%d", &m);
    int hh, mm, ss;
    int i;
    char unlock[17], lock[17], name[17];
    int max = -1, min = 0xffffff, temp;
    for(i=0;i<m;i++){
        scanf("%s %d:%d:%d", name, &hh, &mm, &ss);
        temp = hh*3600 + mm*60 + ss;
        if(temp < min){
            min = temp;
            strcpy(unlock, name);
        }
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp = hh*3600 + mm*60 + ss;
        if(temp > max){
            max = temp;
            strcpy(lock, name);
        }
    }
    printf("%s %s",unlock, lock);
    return 0;
}
