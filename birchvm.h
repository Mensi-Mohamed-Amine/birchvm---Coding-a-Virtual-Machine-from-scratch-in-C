/* birchvm.h */

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

/*

    16 bit
        AX
        Bx
        CX
        DX
        SP
        IP
    64 KB memory
    (Serial COM port)
    (Floppy drive)

*/

typedef unsigned short int Reg;

struct s_registers
{
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp;
    Reg ip;
};

typedef struct s_registers Registers;
struct s_cpu
{
    Registers r;
};

typedef struct s_cpu CPU;

/*
    mov ax,0x05 // 0x01 0x01

*/

typedef Opcode Program;

typedef int8 Stack[-1];
typedef Instruction Program;
struct s_vm
{
    CPU c;
    Stack s;
    Program *p;
};

typedef struct s_vm VM;

int main(int, char **);