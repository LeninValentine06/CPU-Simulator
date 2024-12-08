#include <stdint.h>
#include <stdio.h>

#define FLAG_CY 0x80 // Carry Flag (bit 7)
#define FLAG_Z  0x40 // Zero Flag (bit 6)
#define FLAG_S  0x20 // Sign Flag (bit 5)
#define FLAG_P  0x10 // Parity Flag (bit 4)
#define FLAG_OV 0x08 // Overflow Flag (bit 3)
#define FLAG_AC 0x04 // Auxiliary Carry Flag (bit 2)
#define FLAG_I  0x02 // Interrupt Enable (bit 1)
#define FLAG_H  0x01 // Halt Flag (bit 0)

struct registers{
    uint8_t R0;
    uint8_t R1;
    uint8_t R2;
    uint8_t R3;
    uint8_t R4;
    uint8_t R5;
    uint8_t R6;
    uint8_t R7;
    uint8_t IR;  // Instruction Register
    uint8_t MAR; // Memory Address Register
    uint8_t MDR; // Memory Data Register
    uint8_t PC;  // Program Counter
    uint8_t SP;  // Stack Pointer
    uint8_t A;   // Accumulator
    uint8_t B;   // General-purpose B Register
    uint8_t FR;  // Flag Register
};

void flag(struct registers *c){
    if(c->FR % 10000000 == 1){
        printf("Halt Flag");
    }
    
    if(c->FR % 1000000 - c->FR % 10000000 == 1){
        printf("Interrupt Enable Flag");
    }
}

