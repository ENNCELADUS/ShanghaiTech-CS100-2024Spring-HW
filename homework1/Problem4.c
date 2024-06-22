#include <stdio.h>

int main(){
    int max1 = -101;
    int max2 = -102;
    int min1 = 101;
    int min2 = 102;

    int n;
    scanf("%d", &n);

    int num;

    for (int i = 0; i < n; i ++){
        scanf("%d", &num);
        if (num > max1)
        {
            max2 = max1;
            max1 = num;
        }
        else if (num < max1 && num > max2)
            max2 = num;

        if (num < min1)
        {
            min2 = min1;
            min1 = num;
        }
            
        else if (num > min1 && num < min2)
            min2 = num;
        
    }
    printf("%d %d", max2, min2);
    return 0;
}