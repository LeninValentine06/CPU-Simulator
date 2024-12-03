# 8-Bit CPU-Simulator
---



## **Step 1: Design the Architecture**

### Goals:
* Finalize the architecture before writing code.

### Actions:
1. **Define the CPU components**:
   * 16 registers (name them: `R0` to `R15`).
   * Special-purpose registers:
      * **Program Counter (PC)** for tracking the next instruction.
      * **Instruction Register (IR)** for holding the current instruction.
      * **Flags Register** for zero, carry, and overflow flags.
   * ALU for arithmetic and logical operations.

2. **Instruction Format**:
   * Two-address format: `OPCODE DST, SRC`.
   * Example:
      * `MOV R0, R1` (Move content of `R1` to `R0`).
      * `ADD R2, R3` (Add contents of `R2` and `R3` and store in `R2`).
   * Opcodes: Define unique numbers for each instruction (e.g., `MOV=0x01`, `ADD=0x02`).

3. **Memory**:
   * Decide on size: Start with **256 bytes**.
   * Memory map:
      * First 128 bytes for data.
      * Remaining 128 bytes for the program.

## **Step 2: Write the Memory Module**

### Goals:
* Implement a way to store and retrieve data.

### Actions:
1. Create a `uint8_t memory[256];` array to represent RAM.
2. Write functions to:
   * **Read memory**: `uint8_t read(uint8_t address);`
   * **Write memory**: `void write(uint8_t address, uint8_t value);`

## **Step 3: Build the Registers**

### Goals:
* Simulate CPU registers.

### Actions:
1. Define 16 general-purpose registers as an array:
   ```c
   uint8_t registers[16];
   ```

2. Define special-purpose registers:
   ```c
   uint8_t PC = 0; // Program Counter
   uint8_t IR = 0; // Instruction Register
   uint8_t FLAGS = 0; // Zero, Carry, Overflow
   ```

## **Step 4: Implement the ALU**

### Goals:
* Perform arithmetic and logical operations.

### Actions:
1. Write functions for:
   * **Addition** (`uint8_t alu_add(uint8_t a, uint8_t b)`).
   * **Subtraction**.
   * **Bitwise operations**: AND, OR, XOR, NOT.

2. Update flags after every operation:
   * Zero flag if result is 0.
   * Carry flag for overflow.

## **Step 5: Create the Instruction Set**

### Goals:
* Define all supported instructions.

### Actions:
1. Decide on core instructions:
   * Data transfer: `MOV DST, SRC`.
   * Arithmetic: `ADD`, `SUB`.
   * Logical: `AND`, `OR`, `XOR`.
   * Program flow: `JMP`, `CALL`, `RET`.
   * Halt: `HLT`.

2. Create an opcode table:
   ```c
   enum { 
     MOV = 0x01, 
     ADD = 0x02, 
     SUB = 0x03, 
     JMP = 0x04, 
     HLT = 0xFF 
   };
   ```

## **Step 6: Write the CPU Simulator**

### Goals:
* Simulate the fetch-decode-execute cycle.

### Actions:
1. Implement **fetch**:
   * Fetch instruction from memory using `PC`.

2. Implement **decode**:
   * Extract opcode and operands from the instruction.

3. Implement **execute**:
   * Call the appropriate function based on the opcode.

## **Step 7: Load and Run a Program**

### Goals:
* Test the simulator with a simple program.

### Actions:
1. Write a program in machine code:
   ```asm
   0x01 0x00 0x01 ; MOV R0, R1
   0x02 0x00 0x02 ; ADD R0, R2
   0xFF ; HLT
   ```

2. Load the program into memory.
3. Run the simulator and observe the results.

## **Step 8: Debugging Features**

### Goals:
* Add tools to debug the emulator.

### Actions:
1. Print the state of:
   * Registers.
   * Memory.
   * Flags.

2. Add a step-by-step execution mode.

## **Step 9: Assemble and Execute**

### Goals:
* Make it easy to write programs.

### Actions:
1. Write a simple assembler to convert assembly code to machine code.
2. Test with small programs:
   * Arithmetic calculations.
   * Loops and branches.

## **Step 10: Expand Functionality**

### Goals:
* Add advanced features over time.

### Actions:
1. Implement stack operations (`PUSH`, `POP`).
2. Add interrupts and I/O simulation.
3. Support additional addressing modes.

## Checklist Summary
- [x] Design the architecture.
- [ ] Write memory management functions.
- [ ] Simulate registers and flags.
- [ ] Implement the ALU.
- [ ] Define the instruction set.
- [ ] Build the fetch-decode-execute cycle.
- [ ] Load and execute programs.
- [ ] Add debugging tools.
- [ ] Write an assembler.
- [ ] Expand with stack, interrupts, and I/O.