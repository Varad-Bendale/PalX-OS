gdt_start : 


gdt_null : 
dd 0x0 
dd 0x0

gdt_code : 
dw 0xffff
dw 0x0 
db 0x0 
db 10011010b
db 11001111b
db 0x0 

gdt_data : 
dw 0xffff
dw 0x0 
db 0x0 
db 10010010b
db 11001111b
db 0x0 

gdt_end: 

gdt_description: 
dw gdt_start - gdt_end -1 
dd gdt_start 

; okay this is manual okay see here think of like db dw dd are just like the int double and double double they are like see for our
; dw -> 0->15 so like 16 bits and its like initializes the thing to direct 0 as per the 32 bits 
; db -> 15->23 so here we have like 32 bits cpu na so we like make the registers of the 15-23 bits to 0 
; db -> 23 -> 31 same make it to zero 
; here now the last thing is taken because of incovinece intel already did it earlier and then they just added it further nothing can be done 
; and just for info dd means the whole 32 bits register for the cpu we did define it in the like gdt null okay so yeah that is taken in consideration as well 
; now there is this 0xffff these are like see limit to all the bits for the cpu as the main work of gdt is to make the cpu ready for the 32 bit thing work now we have 2 different differetn segments data and ;code so this is the limit for the thing so now ofc this is very low so there is like 1111 hidden thing which is added to the limit which makes the thing like 0xFFFFF which is insanely huge number like a mil;lion bit which is like 1 mb but still its too much low so we got the granuality which makes us use the 4kb inspite of 1 byte so our storage / limit increases significantly makes it to like 4gb which is awes;ome amount of limit the real nesecessity for the limit is like the memory thing see if any of the code / data looks for the memory and picks something if it is anything it would just start giving up random ; stupid ass garbage value so we need to like set up the limit for the thing which makes it better like see there are two segments data and code the process should reach in each others teretoy simply we need; to look for the same thing 

;for code Access byte 10011010b:
;1 → present (segment exists)
;00 → ring 0 (kernel privilege)
;1 → it's a code/data segment (not system)
;1 → executable (it's code)
;0 → not readable from data side / grows up
;1 → readable
;0 → not accessed yet

;Flags 11001111b:
;1 → granularity = 4KB pages (so limit 0xfffff × 4KB = 4GB)
;1 → 32-bit protected mode
;00 → reserved/zero
;1111 → limit bits 16-19 (upper nibble of limit)
;same things we can get it for the data as well 
