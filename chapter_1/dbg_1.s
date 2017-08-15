# check this code on A-profile (bus interuption)
# __asm__("BKPT");
# or:
##include <debugbreak.h>
#...
#debug_break();
# or:
#
.section .text
.global _start

_start:
 mov r0, pc
 mov r1, #2
 add r2, r1, r1
 bkpt # examine this instruction
