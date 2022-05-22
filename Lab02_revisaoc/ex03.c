#include <stdio.h>
#include <string.h>

int main() 
{
    double dados[] = {1.334343443, 3.554545454, 4.343424,4343.43423, 432434.424, 43.432423432, 432.434234, 1234.421321, 0.433434, 0.00321323900};
    for(int i = 0; i < 10; i++){
        printf("%f\n", dados[i]);
    }
    return 0;
}