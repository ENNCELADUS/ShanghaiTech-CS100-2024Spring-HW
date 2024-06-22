#include <stdio.h>

int hw3_islower(int ch){
    return ch >= 'a' && ch <= 'z';
}

int hw3_isupper(int ch){
    return ch >= 'A' && ch <= 'Z';
}

int hw3_isalpha(int ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int hw3_isdigit(int ch){
    return ch >= '0' && ch <= '9';
}

int hw3_tolower(int ch){
    return hw3_isupper(ch) ? (ch + 32) : ch;
}

int hw3_toupper(int ch){
    return hw3_islower(ch) ? (ch - 32) : ch;
}

size_t hw3_strlen(const char *str){
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}

char *hw3_strchr(const char *str, int ch){
    while (*str != '\0'){
        if (*str == ch)
            return (char *)str;
        str++;
    }
    if (ch == '\0') {
        return (char *)str;
    }
    return NULL;
}

char *hw3_strcpy(char *dest, const char *src){
    char *temp = dest;
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return temp;
}

char *hw3_strcat(char *dest, const char *src){
    char *temp = dest;

    while (*dest != '\0') {
        dest++;
    }
    hw3_strcpy(dest, src);
    return temp;
}

int hw3_strcmp(const char *lhs, const char *rhs){
    while ((*lhs != '\0') && (*rhs != '\0') && (*lhs == *rhs)){
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}
// test code
void demo(const char* lhs, const char* rhs)
{
    int rc = hw3_strcmp(lhs, rhs);
    const char *rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";
    printf("[%s] %s [%s]\n", lhs, rel, rhs);
}
 
int main(void)
{
    const char* string = "Hello World!";
    demo(string, "Hello!");
    demo(string, "Hello");
    demo(string, "Hello there");
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11);
}