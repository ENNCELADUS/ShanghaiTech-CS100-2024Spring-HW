#include <stdio.h>

int count_digits(int n){
    int digit_num = 0;
    do{
        digit_num++;
        n /= 10;
    } while (n != 0);
    return digit_num;
}

int is_repdigit(int n, int digit_num){
    if (n == 0)
        return 1;
    else{
        if (digit_num < 4)
            return 0;
        else{
            int last_digit = n % 10;
            n /= 10;
            while (n > 0) {
                if (n % 10 != last_digit){
                    return 0;
                }
                n /= 10;
            }
        }
    }
    return 1;
}

int min_element(int *array, int l, int r) {
  int pos = l;
  while (l < r) {
    if (array[l] < array[pos])
      pos = l;
    ++l;
  }
  return pos;
}

int max_element(int *array, int l, int r) {
  int pos = l;
  while (l < r) {
    if (array[l] > array[pos])
      pos = l;
    ++l;
  }
  return pos;
}

void swap(int *pa, int *pb) {
  int tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}


void sort(int *array, int n, int ascending) {
  for (int i = 0; i < n; ++i) {
    if (ascending == 1){
        int min_pos = min_element(array, i, n);
        swap(&array[i], &array[min_pos]);
    }
    else if(ascending == 0){
        int max_pos = max_element(array, i, n);
        swap(&array[i], &array[max_pos]);
    }
  }
}

int sorted_x(int x, int ascending){
    // get the digits of x, store in an array
    int digits_of_x[4] = {0};
    int i = 0;
    while(x != 0){
        digits_of_x[i] = x % 10;
        x /= 10;
        i++;
    }

    // use the sort function to sort the digit-array
    //ascending number
    if (ascending == 1){
        sort(digits_of_x, 4, 1);
    }
    //descending number
    else if (ascending == 0){
        sort(digits_of_x, 4, 0);
    }
    
    // restore the sorted num
    int num = 0;

    for (int i = 0; i < 4; i ++){
        num = num * 10 + digits_of_x[i];
    }
    return num;
}

int main(){
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++){
        scanf(" %d", &x);
        if (count_digits(x) > 4)
            printf("%d contains more than 4 digits.\n", x);

        else if (is_repdigit(x, count_digits(x)) == 1)
            printf("%d is a repdigit.\n", x);

        else{
            while (x != 6174){
                int descending_x = sorted_x(x, 0);
                int ascending_x = sorted_x(x, 1);
                x = descending_x - ascending_x;
                printf("%d - %d = %d\n", descending_x, ascending_x, x);
            }
        }

    }
    return 0;
}