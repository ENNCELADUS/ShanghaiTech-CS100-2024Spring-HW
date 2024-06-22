#include <stdio.h>
#include <stdlib.h>

int judge(char *str, int str_size){
    for (int i = 0, j = str_size - 1; i <= j; i ++, j --){
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i ++){
        int len;
        scanf(" %d", &len);
        getchar();
        // use dynamic memory
        const int str_size = len + 1;

        char *str= (char *)malloc(sizeof(char) * str_size);

        fgets(str, str_size, stdin);

        if (judge(str, str_size - 1) == 1)
            printf("Yes\n");
        else
            printf("No\n");

        free(str);
    }

    return 0;
}