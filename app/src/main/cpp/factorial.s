
.text
.globl Factorial

Factorial:
    cmp x0, 0
    beq end
    sub x0, x0, #1
    bl Factorial
    add x0, x0, #1
    mul x0, x0, x1
    ret
end:
    mov x0, #1
    ret