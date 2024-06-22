#include <stdio.h>

int main(){

    int num;
    int sum = 0;
    int max = -101;

    while (1)
    {
        scanf("%d", &num);
        
        if (num == 0)
            break;

        sum += num;
        

        if(num > max)
            max = num;
    }
    printf("sum: %d\n", sum);
    printf("maximum: %d", max);

    return 0;
}
