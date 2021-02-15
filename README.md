# VCPU
A virtual CPU written in C++.

# OPCODES
01: load the next number in RAM into reg0  
10: load the next number in RAM into reg1  
11: Add reg0 and reg1; store result in reg2  
100: Call interrupt located in next place in memory  
101: Multiply reg0 and reg1; store result in reg2

# Interrupts
10: Print reg2 into the console

# Registers
reg0: General Purpose Register  
reg1: General Purpose Regsiter  
reg2: Arithmetic Result Storage  

# NOTES
You currently have to manually input program into RAM. The above opcodes are the only ones implemented. Currently does not support binary.

# COMPILING
```make```  
```make run```
