#include <stdio.h>

double x_to_n_power(double x, int i){
    double x0 = x;
    x = 1;

    if (i > 0){
        for (int j = 0; j < i; j ++)
            x *= x0;
        return x;
    }
    else
        return 1;
}
/*
优化x^n的计算：x^n = x^(n-1) * n
*/

int main(){
    int degree;
    scanf("%d", &degree);
    double coefficient[32];
    for (int i = 0; i <= degree; i ++){
        scanf(" %lf", &coefficient[i]);
    }

    int m;
    scanf("%d", &m);

    double x;
    
    for (int j = 0; j < m; j ++){
        scanf(" %lf", &x);
        double result = 0;

        for (int i = 0; i <= degree; i ++)
            result += coefficient[i] * x_to_n_power(x, i);

        printf("%.3lf\n", result);
    }
    return 0;
}