; this code blocks implement two common loop schemes on ARM
; suppose that the second cycle is wrapped into a function, which processes an array. 
; try to reconstruct minimum argument number and types of this function. (foo(type,...)).

;1) "abstract"
	MOV Rn, #<START_N> ; put start number into counter register
	B chk

body:
	; do smth
	; then increment cnt (according to shift)
	ADD Rn, Rn, #1

chk:	
	CMP Rn, #<END_NUMBER>
	BLT body

;2) "address"
    add        r1, r0, r1, lsl #2

loop:
    cmp     r0, r1
    bge     end
; do smth
; then increment cnt       
    adds    r0, r0, #4
    b        loop

end: