# Abstract Machine Model

This document describes a simple model of an abstract machine that we will
use to motivate and explain the behavior of operating systems and compilers.
The *concepts* in this abstract are present in all modern machines, but the
names vary across different processors.  For example, the Instruction Pointer (IP)
described in this model is called EIP on 32-bit Intel chips, RIP, on 64-bit Intel chips,
and PC (program counter) on ARM chips.  Regardless of the name, they all
have these same basic capabilities.

To begin with, we assume that the machine consists of nothing more than
a CPU with internal registers and a byte-addressable memory accessed 
by individual LOAD and STORE operations that move one *word* of memory
in and out of a single register.  The *word size* is 32 bits, and so each
each memory cell, each internal register, each address, and each CPU instruction
are all 32 bits.  It follows that the maximum addressable memory is 2^32B, or 4GB. 

## User Mode Registers

These registers can be read and written by ordinary user programs at any point:

| Register | Name | Purpose |
|---|---|---|
|R0, R1, R2, ... Rn | General Purpose Registers | Used for ordinary program computations. |
|FLAGS | Flags | Several bits that reflect recent results, such as equal-to, less-than, etc |
|SP | Stack Pointer | Contains the address of the lowest (newest) item on the stack. |
|IP | Instruction Pointer | Contains the address of the current instruction. |

## Kernel Mode Registers

These registers can only be read or written when the machine is in *kernel mode*.
An attempt to access these registers from user mode will result in a *trap*.

| Register | Name | Purpose |
|---|---|---|
|MODE | Mode Register | Describes the current state of the processor: user-mode or kernel-mode. |
|ISP | Kernel Stack Pointer | Contains the address of the stack to be used for interrupts. | 
|TVP | Trap Vector Pointer | Contains the address of the trap vector. |

## User Level Instructions

This abstract machine supports the following assembly instructions.

Memory is accessed via two instructions: LOAD and STORE.
LOAD moves a single memory address into a single register,
and STORE writes a single register into a single memory address:

```
LOAD mem, reg
STORE reg, mem
```

Almost all other operations are performed solely using registers.
For example, the ADD instruction adds two registers together,
and places the result in the second operand.  In a similar way,
SUB performs subtraction, and MUL performs multiply.  If we need
others kinds of arithmetic and logical operations (DIV, AND, OR),
then we can assume those exist as well.

```
ADD rx, ry
SUB rx, ry
MUL rx, ry
...
```

In order to perform branches and loops, we need several control
flow instructions.  These are typically done with a pair of instructions:
CMP compares two registers together and then puts the results into
the FLAGS register.  Then, a conditional jump reads the FLAGS register
and jumps to a new instruction if true.  For example, JLT jumps if
the first register was Less Than the second register.
The JUMP instruction jumps to a new label unconditionally.

```
CMP rx, ry
JLT/JLE/JEQ/JNE/JGE/JGT label
JUMP label
```

```
PUSH r
POP r
```


```
CALL label
RET
```

## Quick Example

```
     LOAD $0, r0
top:
     ADD  $1, r0
     CMP  $10, r0
     JLT  top
done:
     PUSH 
     CALL 
```


## Function Calls

## Interrupts

```
TRAP n
RTI
```


