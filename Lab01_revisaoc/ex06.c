#include <stdio.h>

int main()
{
    int fat = 0;
    for(int n = 1; n <11; n++){
        for(fat = 1; n > 1; n--){
            fat = fat * n;
        }
        printf("%d! = %d\n", n,fat);
    }
    return 0;
}