#include <stdio.h>
#include <string.h>

void print_std(const char *std) {
    if (strncmp(std, "c", 1) == 0) {
        const char *std_num = std + 1;
        printf("-std=c%s: Set the language standard to ISO C%s.\n", std_num, std_num);
    } 
    else if (strncmp(std, "c++", 3) == 0) {
        const char *std_num = std + 3;
        printf("-std=c++%s: Set the language standard to ISO C++%s.\n", std_num, std_num);
    } 
    else if (strncmp(std, "gnu", 3) == 0) {
        const char *std_num = std + 3;
        printf("-std=gnu%s: Set the language standard to GNU dialect of C%s.\n", std_num, std_num);
    } 
    else if (strncmp(std, "gnu++", 5) == 0) {
        const char *std_num = std + 5;
        printf("-std=gnu++%s: Set the language standard to GNU dialect of C++%s.\n", std_num, std_num);
    }
}

// deal with suffix

const char *c_suffixes[] = {".c"};
const char *c_cpp_header_suffixes[] = {".h"};
const char *cpp_suffixes[] = {".cpp", ".C", ".cc", ".cxx"};
const char *cpp_header_suffixes[] = {".hpp", ".hxx"};

int has_suffix(const char *str, const char *suffixes[], int how_many_suffixes_in_suffixes) {
    if (str == NULL) return 0;
    size_t str_len = strlen(str);

    for (int i = 0; i < how_many_suffixes_in_suffixes; i ++){
        size_t suffix_len = strlen(suffixes[i]);
        if (suffix_len > str_len)
            continue;
        if (strcmp(str + str_len - suffix_len, suffixes[i]) == 0)
            return 1;
    }
    return 0;
}

void print_other(const char *str){
    // Situation 1: judge c suffixes
    if (has_suffix(str, c_suffixes, 1))
        printf("%s: C source code as input file.\n", str);
    // Situation 2: judge c/c++ header file suffixes
    else if (has_suffix(str, c_cpp_header_suffixes, 1))
        printf("%s: C/C++ header file as input file.\n", str);
    // Situation 3: judge c++ suffixes
    else if (has_suffix(str, cpp_suffixes, 4))
        printf("%s: C++ source code as input file.\n", str);
    // Situation 4: judge c++ header file suffixes
    else if (has_suffix(str, cpp_header_suffixes, 2))
        printf("%s: C++ header file as input file.\n", str);
    else printf("Invalid statement.\n");
}


int main(int argc, char *argv[]){
    for (int i = 1; i < argc; i ++){
        // 1.-Wall
        if (strcmp(argv[i], "-Wall") == 0)
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        // 2.-Wpedantic
        else if (strcmp(argv[i], "-Wpedantic") == 0)
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        // 3.-Wextra
        else if (strcmp(argv[i], "-Wextra") == 0)
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        // 4.-Werror
        else if (strcmp(argv[i], "-Werror") == 0)
            printf("-Werror: Make all warnings into errors.\n");
        // 5.-o xxx
        else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                printf("-o %s: Place the primary output in file %s.\n", argv[i + 1], argv[i + 1]);
                i ++; // skip the next string(the name of the file)
            }
        }
        // 6.-I xxx
        else if (strcmp(argv[i], "-I") == 0) {
            if (i + 1 < argc) {
                printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i + 1], argv[i + 1]);
                i ++; // skip the next string(the name of the file)
            }
        }
        // 7.-std=xxx
        else if (strncmp(argv[i], "-std=", 5) == 0){
            const char *standard_name = argv[i] + 5;
            print_std(standard_name);
        }
        // 8.Other
        else {
            print_other(argv[i]);
        }

    }
    return 0;
}