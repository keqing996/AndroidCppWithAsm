
.global GetHelloStr
.section .rodata
str:
    .asciz "hello"

.text
GetHelloStr:
    adrp x0, str
    add x0, x0, :lo12:str
    ret
