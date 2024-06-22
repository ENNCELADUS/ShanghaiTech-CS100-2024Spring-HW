/*
主要改进点：

x_to_n_power函数使用了快速幂算法，能够更高效地计算幂。
在main函数中，我们使用一个变量x_power来存储当前的x^i值，并在每次循环中更新它，避免了不必要的重复计算。
*/

#include <stdio.h>

// 使用快速幂算法来计算x^n
double x_to_n_power(double x, int n) {
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

int main() {
    int degree;
    scanf("%d", &degree);
    double coefficient[32];
    for (int i = 0; i <= degree; i++) {
        scanf(" %lf", &coefficient[i]);
    }

    int m;
    scanf("%d", &m);

    double x;
    
    for (int j = 0; j < m; j++) {
        scanf(" %lf", &x);
        double result = 0;
        double x_power = 1; // 初始化x的0次幂

        for (int i = 0; i <= degree; i++) {
            result += coefficient[i] * x_power;
            x_power *= x; // 直接用上次的结果乘以x来计算下一个幂
        }

        printf("%.3lf\n", result);
    }
    return 0;
}

