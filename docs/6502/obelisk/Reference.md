## Instruction Reference
Click on any of following links to go straight to the information for that instruction.

|             |             |             |             |             |             |             |             |             |             |             |             |             |             |
|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|
| [ADC](#ADC) | [AND](#AND) | [ASL](#ASL) | [BCC](#BCC) | [BCS](#BCS) | [BEQ](#BEQ) | [BIT](#BIT) | [BMI](#BMI) | [BNE](#BNE) | [BPL](#BPL) | [BRK](#BRK) | [BVC](#BVC) | [BVS](#BVS) | [CLC](#CLC) |
| [CLD](#CLD) | [CLI](#CLI) | [CLV](#CLV) | [CMP](#CMP) | [CPX](#CPX) | [CPY](#CPY) | [DEC](#DEC) | [DEX](#DEX) | [DEY](#DEY) | [EOR](#EOR) | [INC](#INC) | [INX](#INX) | [INY](#INY) | [JMP](#JMP) |
| [JSR](#JSR) | [LDA](#LDA) | [LDX](#LDX) | [LDY](#LDY) | [LSR](#LSR) | [NOP](#NOP) | [ORA](#ORA) | [PHA](#PHA) | [PHP](#PHP) | [PLA](#PLA) | [PLP](#PLP) | [ROL](#ROL) | [ROR](#ROR) | [RTI](#RTI) |
| [RTS](#RTS) | [SBC](#SBC) | [SEC](#SEC) | [SED](#SED) | [SEI](#SEI) | [STA](#STA) | [STX](#STX) | [STY](#STY) | [TAX](#TAX) | [TAY](#TAY) | [TSX](#TSX) | [TXA](#TXA) | [TXS](#TXS) | [TYA](#TYA) |

### ADC
Add with Carry

A,Z,C,N = A+M+C 

This instruction adds the contents of a memory location to the accumulator together with the carry bit. If overflow occurs the carry bit is set, this enables multiple byte addition to be performed.

Processor Status after use:
|                     |                                     |                              |
|---------------------|-------------------------------------|------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set if overflow in bit 7     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0                 |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                 |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                 |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                 |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set if sign bit is incorrect |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 set             |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $69        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $65        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $75        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $6D        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $7D        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $79        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $61        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $71        | 2         | 5 (+1 if page crossed) |

See also: [SBC](#SBC) 

### AND
Logical AND

A,Z,N = A&M

A logical AND is performed, bit by bit, on the accumulator contents using the contents of a byte of memory.

Processor Status after use:
|                     |                                     |                  |
|---------------------|-------------------------------------|------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0     |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected     |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected     |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected     |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected     |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 set |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $29        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $25        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $35        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $2D        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $3D        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $39        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $21        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $31        | 2         | 5 (+1 if page crossed) |

See also: [EOR](#EOR), [ORA](#ORA)

### ASL
Arithmetic Shift Left

A,Z,C,N = M*2 or M,Z,C,N = M*2

This operation shifts all the bits of the accumulator or memory contents one bit left. Bit 0 is set to 0 and bit 7 is placed in the carry flag. The effect of this operation is to multiply the memory contents by 2 (ignoring 2's complement considerations), setting the carry if the result will not fit in 8 bits.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to contents of old bit 7      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Accumulator](Addressing.md#IMP) | $0A        | 1         | 2          |
| [Zero Page](Addressing.md#ZPG)   | $06        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $16        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $0E        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $1E        | 3         | 7          |

See also: [LSR](#LSR), [ROL](#ROL), [ROR](#ROR)

### BCC
Branch if Carry Clear If the carry flag is clear then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $90        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BCS](#BCS) 

### BCS
Branch if Carry Set If the carry flag is set then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $B0        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BCC](#BCC)

### BEQ
Branch if Equal If the zero flag is set then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $F0        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BNE](#BNE)

### BIT
Bit Test A & M, N = M7, V = M6
This instructions is used to test if one or more bits are set in a target memory location. The mask pattern in A is ANDed with the value in memory to set or clear the zero flag, but the result is not kept. Bits 7 and 6 of the value from memory are copied into the N and V flags

Processor Status after use:
|                     |                                     |                                      |
|---------------------|-------------------------------------|--------------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected                         |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if the result if the AND is zero |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                         |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                         |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                         |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set to bit 6 of the memory value     |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set to bit 7 of the memory value     |

|                                |            |           |            |
|--------------------------------|------------|-----------|------------|
| **Addressing Mode**            | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG) | $24        | 2         | 3          |
| [Absolute](Addressing.md#ABS)  | $2C        | 3         | 4          |

### BMI
Branch if Minus If the negative flag is set then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $30        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BPL](#BPL)

### BNE
Branch if Not Equal If the zero flag is clear then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $D0        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BEQ](#BEQ)

### BPL
Branch if Positive If the negative flag is clear then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $10        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BMI](#BMI)

### BRK
Force Interrupt The BRK instruction forces the generation of an interrupt request. The program counter and processor status are pushed on the stack then the IRQ interrupt vector at $FFFE/F is loaded into the PC and the break flag in the status set to one.

|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Set to 1     |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $00        | 1         | 7          |

The interpretation of a BRK depends on the operating system. On the BBC Microcomputer it is used by language ROMs to signal run time errors but it could be used for other purposes (e.g. calling operating system functions, etc.).

### BVC
Branch if Overflow Clear If the overflow flag is clear then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $50        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BVS](#BVS) 

### BVS 
Branch if Overflow Set If the overflow flag is set then add the relative displacement to the program counter to cause a branch to a new location.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |                                               |
|-------------------------------|------------|-----------|-----------------------------------------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles**                                    |
| [Relative](Addressing.md#REL) | $70        | 2         | 2 (+1 if branch succeeds +2 if to a new page) |

See also: [BVC](#BVC)

### CLC
Clear Carry Flag

C = 0

Set the carry flag to zero.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to 0     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $18        | 1         | 2          |

See also: [SEC](#SEC)

### CLD
Clear Decimal Mode

D = 0

Sets the decimal mode flag to zero.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Set to 0     |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $D8        | 1         | 2          |

**NB**: The state of the decimal flag is uncertain when the CPU is powered up and it is not reset when an interrupt is generated. In both cases you should include an explicit CLD to ensure that the flag is cleared before performing addition or subtraction. See also: [SED](#SED)

### CLI
Clear Interrupt Disable

I = 0

Clears the interrupt disable flag allowing normal interrupt requests to be serviced.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Set to 0     |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $58        | 1         | 2          |

See also: [SEI](#SEI)
### CLV
Clear Overflow Flag

V = 0

Clears the overflow flag.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set to 0     |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $B8        | 1         | 2          |

### CMP
Compare

Z,C,N = A-M

This instruction compares the contents of the accumulator with another memory held value and sets the zero and carry flags as appropriate.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set if A >= M                     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = M                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $C9        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $C5        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $D5        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $CD        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $DD        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $D9        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $C1        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $D1        | 2         | 5 (+1 if page crossed) |

See also: [CPX](#CPX), [CPY](#CPY)

### CPX
Compare X Register

Z,C,N = X-M

This instruction compares the contents of the X register with another memory held value and sets the zero and carry flags as appropriate.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set if X >= M                     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X = M                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                |            |           |            |
|--------------------------------|------------|-----------|------------|
| **Addressing Mode**            | **Opcode** | **Bytes** | **Cycles** |
| [Immediate](Addressing.md#IMM) | $E0        | 2         | 2          |
| [Zero Page](Addressing.md#ZPG) | $E4        | 2         | 3          |
| [Absolute](Addressing.md#ABS)  | $EC        | 3         | 4          |

See also: [CMP](#CMP), [CPY](#CPY)

### CPY
Compare Y Register

Z,C,N = Y-M

This instruction compares the contents of the Y register with another memory held value and sets the zero and carry flags as appropriate.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set if Y >= M                     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if Y = M                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                |            |           |            |
|--------------------------------|------------|-----------|------------|
| **Addressing Mode**            | **Opcode** | **Bytes** | **Cycles** |
| [Immediate](Addressing.md#IMM) | $C0        | 2         | 2          |
| [Zero Page](Addressing.md#ZPG) | $C4        | 2         | 3          |
| [Absolute](Addressing.md#ABS)  | $CC        | 3         | 4          |

See also: [CMP](#CMP), [CPX](#CPX)

### DEC
Decrement Memory

M,Z,N = M-1

Subtracts one from the value held at a specified memory location setting the zero and negative flags as appropriate. 

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected                      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if result is zero             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG)   | $C6        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $D6        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $CE        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $DE        | 3         | 7          |

See also: [DEX](#DEX), [DEY](#DEY)

### DE
Decrement X Register

X,Z,N = X-1

Subtracts one from the X register setting the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X is zero         |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of X is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $CA        | 1         | 2          |

See also: [DEC](#DEC), [DEY](#DEY)

### DEY
Decrement Y Register

Y,Z,N = Y-1

Subtracts one from the Y register setting the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if Y is zero         |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of Y is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $88        | 1         | 2          |

See also: [DEC](#DEC), [DEX](#DEX)

### EOR
Exclusive OR

A,Z,N = A^M

An exclusive OR is performed, bit by bit, on the accumulator contents using the contents of a byte of memory.

Processor Status after use:
|                     |                                     |                  |
|---------------------|-------------------------------------|------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0     |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected     |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected     |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected     |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected     |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 set |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $49        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $45        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $55        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $4D        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $5D        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $59        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $41        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $51        | 2         | 5 (+1 if page crossed) |

See also: [AND](#AND), [ORA](#ORA)

### INC
Increment Memory

M,Z,N = M+1

Adds one to the value held at a specified memory location setting the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected                      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if result is zero             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG)   | $E6        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $F6        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $EE        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $FE        | 3         | 7          |

See also: [INX](#INX), [INY](#INY)

### INX
Increment X Register

X,Z,N = X+1

Adds one to the X register setting the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X is zero         |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of X is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $E8        | 1         | 2          |

See also: [INC](#INC), [INY](#INY)

### INY
Increment Y Register

Y,Z,N = Y+1

Adds one to the Y register setting the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if Y is zero         |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of Y is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $C8        | 1         | 2          |

See also: [INC](#INC), [INX](#INX)

### JMP
Jump Sets the program counter to the address specified by the operand.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |            |
|-------------------------------|------------|-----------|------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles** |
| [Absolute](Addressing.md#ABS) | $4C        | 3         | 3          |
| [Indirect](Addressing.md#IND) | $6C        | 3         | 5          |

NB: An original 6502 has does not correctly fetch the target address if the indirect vector falls on a page boundary (e.g. $xxFF where xx is any value from $00 to $FF). In this case fetches the LSB from $xxFF as expected but takes the MSB from $xx00. This is fixed in some later chips like the 65SC02 so for compatibility always ensure the indirect vector is not at the end of the page.

### JSR
Jump to Subroutine The JSR instruction pushes the address (minus one) of the return point on to the stack and then sets the program counter to the target memory address. 

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                               |            |           |            |
|-------------------------------|------------|-----------|------------|
| **Addressing Mode**           | **Opcode** | **Bytes** | **Cycles** |
| [Absolute](Addressing.md#ABS) | $20        | 3         | 6          |

See also: [RTS](#RTS)

### LDA
Load Accumulator

A,Z,N = M

Loads a byte of memory into the accumulator setting the zero and negative flags as appropriate.
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of A is set |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $A9        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $A5        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $B5        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $AD        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $BD        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $B9        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $A1        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $B1        | 2         | 5 (+1 if page crossed) |

See also: [LDX](#LDX), [LDY](#LDY)

### LDX
Load X Register X,Z,N = M Loads a byte of memory into the X register setting the zero and negative flags as appropriate.
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of X is set |

|                                  |            |           |                        |
|----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)   | $A2        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)   | $A6        | 2         | 3                      |
| [Zero Page,Y](Addressing.md#ZPY) | $B6        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)    | $AE        | 3         | 4                      |
| [Absolute,Y](Addressing.md#ABY)  | $BE        | 3         | 4 (+1 if page crossed) |

See also: [LDA](#LDA), [LDY](#LDY)

### LDY
Load Y Register Y,Z,N = M Loads a byte of memory into the Y register setting the zero and negative flags as appropriate.
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if Y = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of Y is set |

|                                  |            |           |                        |
|----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)   | $A0        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)   | $A4        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX) | $B4        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)    | $AC        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)  | $BC        | 3         | 4 (+1 if page crossed) |

See also: [LDA](#LDA), [LDX](#LDX)

### LSR
Logical Shift Right

A,C,Z,N = A/2 or M,C,Z,N = M/2

Each of the bits in A or M is shift one place to the right. The bit that was in bit 0 is shifted into the carry flag. Bit 7 is set to zero.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to contents of old bit 0      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if result = 0                 |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Accumulator](Addressing.md#IMP) | $4A        | 1         | 2          |
| [Zero Page](Addressing.md#ZPG)   | $46        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $56        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $4E        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $5E        | 3         | 7          |

See also: [ASL](#ASL), [ROL](#ROL), [ROR](#ROR)

### NOP
No Operation The NOP instruction causes no changes to the processor other than the normal incrementing of the program counter to the next instruction.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $EA        | 1         | 2          |

### ORA
Logical Inclusive OR

A,Z,N = A|M

An inclusive OR is performed, bit by bit, on the accumulator contents using the contents of a byte of memory.

Processor Status after use:
|                     |                                     |                  |
|---------------------|-------------------------------------|------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0     |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected     |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected     |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected     |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected     |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 set |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $09        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $05        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $15        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $0D        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $1D        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $19        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $01        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $11        | 2         | 5 (+1 if page crossed) |

See also: [AND](#AND), [EOR](#EOR)

### PHA
Push Accumulator Pushes a copy of the accumulator on to the stack.

Processor Status after use:

|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $48        | 1         | 3          |

See also: [PLA](#PLA)

### PHP
Push Processor Status Pushes a copy of the status flags on to the stack.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $08        | 1         | 3          |

See also: [PLP](#PLP)

### PLA
Pull Accumulator Pulls an 8 bit value from the stack and into the accumulator. The zero and negative flags are set as appropriate.
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of A is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $68        | 1         | 4          |

See also: [PHA](#PHA)

### PLP
Pull Processor Status Pulls an 8 bit value from the stack and into the processor flags. The flags will take on new states as determined by the value pulled.

Processor Status after use:
|                     |                                     |                |
|---------------------|-------------------------------------|----------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set from stack |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set from stack |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Set from stack |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Set from stack |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Set from stack |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set from stack |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set from stack |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $28        | 1         | 4          |

See also: [PHP](#PHP)

### ROL
Rotate Left Move each of the bits in either A or M one place to the left. Bit 0 is filled with the current value of the carry flag whilst the old bit 7 becomes the new carry flag value.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to contents of old bit 7      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Accumulator](Addressing.md#IMP) | $2A        | 1         | 2          |
| [Zero Page](Addressing.md#ZPG)   | $26        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $36        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $2E        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $3E        | 3         | 7          |

See also: [ASL](#ASL), [LSR](#LSR), [ROR](#ROR)

### ROR
Rotate Right Move each of the bits in either A or M one place to the right. Bit 7 is filled with the current value of the carry flag whilst the old bit 0 becomes the new carry flag value.

Processor Status after use:
|                     |                                     |                                   |
|---------------------|-------------------------------------|-----------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to contents of old bit 0      |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0                      |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                      |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                      |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                      |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected                      |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of the result is set |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Accumulator](Addressing.md#IMP) | $6A        | 1         | 2          |
| [Zero Page](Addressing.md#ZPG)   | $66        | 2         | 5          |
| [Zero Page,X](Addressing.md#ZPX) | $76        | 2         | 6          |
| [Absolute](Addressing.md#ABS)    | $6E        | 3         | 6          |
| [Absolute,X](Addressing.md#ABX)  | $7E        | 3         | 7          |

See also [ASL](#ASL), [LSR](#LSR), [ROL](#ROL)

### RTI
Return from Interrupt The RTI instruction is used at the end of an interrupt processing routine. It pulls the processor flags from the stack followed by the program counter.

Processor Status after use:
|                     |                                     |                |
|---------------------|-------------------------------------|----------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set from stack |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set from stack |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Set from stack |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Set from stack |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Set from stack |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set from stack |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set from stack |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $40        | 1         | 6          |

### RTS
Return from Subroutine The RTS instruction is used at the end of a subroutine to return to the calling routine. It pulls the program counter (minus one) from the stack.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $60        | 1         | 6          |

See also: [JSR](#JSR)

### SBC
Subtract with Carry

A,Z,C,N = A-M-(1-C)

This instruction subtracts the contents of a memory location to the accumulator together with the not of the carry bit. If overflow occurs the carry bit is clear, this enables multiple byte subtraction to be performed. 

Processor Status after use:
|                     |                                     |                              |
|---------------------|-------------------------------------|------------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Clear if overflow in bit 7   |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0                 |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected                 |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected                 |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected                 |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Set if sign bit is incorrect |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 set             |

|                                   |            |           |                        |
|-----------------------------------|------------|-----------|------------------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles**             |
| [Immediate](Addressing.md#IMM)    | $E9        | 2         | 2                      |
| [Zero Page](Addressing.md#ZPG)    | $E5        | 2         | 3                      |
| [Zero Page,X](Addressing.md#ZPX)  | $F5        | 2         | 4                      |
| [Absolute](Addressing.md#ABS)     | $ED        | 3         | 4                      |
| [Absolute,X](Addressing.md#ABX)   | $FD        | 3         | 4 (+1 if page crossed) |
| [Absolute,Y](Addressing.md#ABY)   | $F9        | 3         | 4 (+1 if page crossed) |
| [(Indirect,X)](Addressing.md#IDX) | $E1        | 2         | 6                      |
| [(Indirect),Y](Addressing.md#IDY) | $F1        | 2         | 5 (+1 if page crossed) |

See also: [ADC](#ADC)

### SEC
Set Carry Flag

C = 1

Set the carry flag to one.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Set to 1     |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $38        | 1         | 2          |

See also: [CLC](#CLC)

### SED
Set Decimal Flag

D = 1

Set the decimal mode flag to one.
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Set to 1     |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $F8        | 1         | 2          |

See also: [CLD](#CLD)

### SEI
Set Interrupt Disable

I = 1

Set the interrupt disable flag to one.

|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Set to 1     |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $78        | 1         | 2          |

See also: [CLI](#CLI)

### STA
Store Accumulator

M = A 

Stores the contents of the accumulator into memory.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                                   |            |           |            |
|-----------------------------------|------------|-----------|------------|
| **Addressing Mode**               | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG)    | $85        | 2         | 3          |
| [Zero Page,X](Addressing.md#ZPX)  | $95        | 2         | 4          |
| [Absolute](Addressing.md#ABS)     | $8D        | 3         | 4          |
| [Absolute,X](Addressing.md#ABX)   | $9D        | 3         | 5          |
| [Absolute,Y](Addressing.md#ABY)   | $99        | 3         | 5          |
| [(Indirect,X)](Addressing.md#IDX) | $81        | 2         | 6          |
| [(Indirect),Y](Addressing.md#IDY) | $91        | 2         | 6          |

See also: [STX](#STX), [STY](#STY)

### STX
Store X Register

M = X

Stores the contents of the X register into memory.

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG)   | $86        | 2         | 3          |
| [Zero Page,Y](Addressing.md#ZPY) | $96        | 2         | 4          |
| [Absolute](Addressing.md#ABS)    | $8E        | 3         | 4          |

See also: [STA](#STA), [STY](#STY)

### STY
Store Y Register

M = Y

Stores the contents of the Y register into memory. 

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                                  |            |           |            |
|----------------------------------|------------|-----------|------------|
| **Addressing Mode**              | **Opcode** | **Bytes** | **Cycles** |
| [Zero Page](Addressing.md#ZPG)   | $84        | 2         | 3          |
| [Zero Page,X](Addressing.md#ZPX) | $94        | 2         | 4          |
| [Absolute](Addressing.md#ABS)    | $8C        | 3         | 4          |

See also: [STA](#STA), [STX](#STX)

### TAX
Transfer Accumulator to X

X = A

Copies the current contents of the accumulator into the X register and sets the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of X is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $AA        | 1         | 2          |

See also: [TXA](#TXA)

### TAY
Transfer Accumulator to Y

Y = A

Copies the current contents of the accumulator into the Y register and sets the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if Y = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of Y is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $A8        | 1         | 2          |

See also: [TYA](#TAY)

### TSX
Transfer Stack Pointer to X

X = S

Copies the current contents of the stack register into the X register and sets the zero and negative flags as appropriate. 

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if X = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of X is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $BA        | 1         | 2          |

See also: [TXS](#TXS)

### TXA
Transfer X to Accumulator

A = X

Copies the current contents of the X register into the accumulator and sets the zero and negative flags as appropriate. 

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of A is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $8A        | 1         | 2          |

See also: [TAX](#TAX)
### TXS
Transfer X to Stack Pointer

S = X

Copies the current contents of the X register into the stack register. 

Processor Status after use:
|                     |                                     |              |
|---------------------|-------------------------------------|--------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Not affected |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Not affected |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $9A        | 1         | 2          |

See also: [TSX](#TSX)

### TYA
Transfer Y to Accumulator

A = Y

Copies the current contents of the Y register into the accumulator and sets the zero and negative flags as appropriate.

Processor Status after use:
|                     |                                     |                          |
|---------------------|-------------------------------------|--------------------------|
| [C](Registers.md#C) | [Carry Flag](Registers.md#C)        | Not affected             |
| [Z](Registers.md#Z) | [Zero Flag](Registers.md#Z)         | Set if A = 0             |
| [I](Registers.md#I) | [Interrupt Disable](Registers.md#I) | Not affected             |
| [D](Registers.md#D) | [Decimal Mode Flag](Registers.md#D) | Not affected             |
| [B](Registers.md#B) | [Break Command](Registers.md#B)     | Not affected             |
| [V](Registers.md#V) | [Overflow Flag](Registers.md#V)     | Not affected             |
| [N](Registers.md#N) | [Negative Flag](Registers.md#N)     | Set if bit 7 of A is set |

|                              |            |           |            |
|------------------------------|------------|-----------|------------|
| **Addressing Mode**          | **Opcode** | **Bytes** | **Cycles** |
| [Implied](Addressing.md#IMP) | $98        | 1         | 2          |

See also: [TAY](#TAY)

--------------------------------------------------
[&larr; Back](Algorithms.md) | [Contents](README.md) | [Next &rarr;](Downloads.md)