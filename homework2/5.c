#include <stdio.h>
#include <string.h>

int registers[6] = {0};

const char* judge_opcode(int a){
    if (a == 0)
        return "add";
    else if (a == 1)
        return "sub";
    else if (a == 2)
        return "mul";
    else if (a == 3)
        return "div";
    else if (a == 4)
        return "let";
    else if (a == 5)
        return "print";
    return " ";
}

// 6 types of operator

void add(int r1, int r2) {
    registers[r1] += registers[r2];
}

void sub(int r1, int r2) {
    registers[r1] -= registers[r2];
}

void mul(int r1, int r2) {
    registers[r1] *= registers[r2];
}

void div(int r1, int r2) {
    if (registers[r2] != 0) { 
        registers[r1] /= registers[r2];
    }
}

void let(int r1, unsigned imm) {
    registers[r1] = imm;
}

void print(int r1) {
    printf("x%d = %d\n", r1, registers[r1]);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        unsigned instruction;
        scanf("%x", &instruction);
        
        // take the 4 segments
        int opcode = (instruction >> 13) & 0x7;
        int r1 = (instruction >> 10) & 0x7;
        int r2 = (instruction >> 7) & 0x7;
        unsigned imm = instruction & 0x7F;

        // run the instruction
        if (strcmp(judge_opcode(opcode), "add") == 0){
            if (r1 != 0)
                add(r1, r2);
        }
            
        else if (strcmp(judge_opcode(opcode), "sub") == 0){
            if (r1 != 0)
                sub(r1, r2);
        }

        else if (strcmp(judge_opcode(opcode), "mul") == 0){
            if (r1 != 0)
                mul(r1, r2);
        }

        else if (strcmp(judge_opcode(opcode), "div") == 0){
            if (r1 != 0)
                div(r1, r2);
        }

        else if (strcmp(judge_opcode(opcode), "let") == 0){
            if (r1 != 0)
                let(r1, imm);
        }

        else if (strcmp(judge_opcode(opcode), "print") == 0){
            print(r1);
        }
            
    }
    
    return 0;
}
