#include<stdio.h>
#include<math.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    if (a == 0){
        if (b == 0){
            if (c == 0)
                printf("x\\in\\mathbb{R}");
            else
                printf("No solution.\n");
        }
        else
            printf("x = %.3lf\n", (double)-c / (double)b);
    }


    else{
        double det = b * b - 4 * a * c;
        if (det < 0)
            printf("No solution.\n");
        else if (det > 0){
            double x1 = (-b - sqrt(det)) / (2.0 * a);
            double x2 = (-b + sqrt(det)) / (2.0 * a);

            if (x1 > x2)
                swap(&x1, &x2);

            printf("x1 = %.3lf, x2 = %.3lf\n", x1, x2);
        }
        else{
            printf("x1 = x2 = %.3lf\n", (double)-b / (2.0 * a));
        }

    }
    
    return 0;
}