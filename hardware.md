# Abstract Computer Model

This document describes a simple model of an abstract computer that we will
use to motivate and explain the behavior of operating systems and compilers.

The *concepts* in this abstract are present in all modern machines, but the
names vary across different processors.  For example, the Instruction Pointer (IP)
described in this model is called EIP on 32-bit Intel chips, RIP, on 64-bit Intel chips,
and PC (program counter) on ARM chips.  Regardless of the name, they all behave in the same way.

## User Mode Registers

| Register | Name | Purpose |
|---|---|---|
|R0, R1, R2, ... Rn | General Purpose Registers | Used for ordinary program computations. |
|SP | Stack Pointer | Contains the address of the lowest (newest) item on the stack. |
|IP | Instruction Pointer | Contains the address of the current instruction. |

## Kernel Mode Registers

| Register | Name | Purpose |
|---|---|---|
|MODE | Mode Register | Describes the current state of the processor: user-mode or kernel-mode. |
|ISP | Kernel Stack Pointer | Contains the address of the stack to be used for interrupts. | 
|IVP | Interrupt Vector Pointer | Contains the address of the interrupt vector. |

## User Level Instructions

```
LOAD m, r
STORE r, m
```

``
ADD rx, ry, rz
SUB rx, ry, rz
MUL rx, ry, rz
...
```

```
PUSH r
POP r
```
```
CMP rx, ry
JLT/JLE/JEQ/JNE/JGE/JGT label
JUMP label
```

```
CALL label
RET
```

## Interrupts
```
TRAP n
RTI
```


