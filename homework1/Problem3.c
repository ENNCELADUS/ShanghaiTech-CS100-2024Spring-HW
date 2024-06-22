#include <stdio.h>


int main(){
    double x, y;
    char operator, judge = 'y';

    do {
        scanf(" %lf %c %lf", &x, &operator, &y);

        if (operator == '+'){
            printf("%lf %c %lf == %lf\n", x, operator, y, x + y);
            }
        else if (operator == '-'){
            printf("%lf %c %lf == %lf\n", x, operator, y, x - y);
            }
        else if (operator == '*'){
            printf("%lf %c %lf == %lf\n", x, operator, y, x * y);
            }
        else if (operator== '/'){
            printf("%lf %c %lf == %lf\n", x, operator, y, x / y);
            }

        else{
            printf("Unknown operator!\n");
        }

/*
switch-case statement:
        switch (operator){
            case '+':
                printf("%lf %c %lf == %lf\n", x, operator, y, x + y);

        }

*/

        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &judge); 

    } while (judge == 'y'); 

    return 0;
}

/*
在 scanf 的 %c 前面添加空格是一个在读取字符时常用的技巧，它的目的是跳过任何标准输入中的空白字符，包括空格、制表符和换行符。

当你使用 scanf 函数读取输入时，如果前一个输入是数字或其他非字符类型，用户按下回车键（产生换行符 \n）来结束输入，这个换行符就会留在输入缓冲区中。如果下一个 scanf 调用是用来读取一个字符（例如使用 %c），它会立即接受这个换行符作为有效字符，因此不会停下来等待用户输入新的字符。

为了避免这种情况，我们在 %c 前面放置一个空格，告诉 scanf 忽略任何空白字符，直到它读取到下一个非空白字符。这样，scanf(" %c", &variable); 将会跳过任何前面的空白字符，包括用户可能已经输入的换行符，然后等待用户的下一个输入。

这是处理输入的一种常见技巧，尤其是在循环中需要多次读取字符时。这个方法确保每次 scanf 都能够正确地读取用户意图输入的字符，而不是之前留在缓冲区中的空白字符。
*/


