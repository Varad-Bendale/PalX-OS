#include <stdint.h>

struct idt { 
unsigned_int16_t  lower_sec ; 
unsigned_int16_t   gdt_selector ; 
unsigned_int8_t  zero ; 
unsigned_int8_t  interupts ; 
unsigned_int16_t  higher_sec  ; 
} __attribute__((packed));

struct limits { 
unsigned_int16_t limit  ; 
unsigned_int32_t base  ; 
} __attribute__((packed));



/* okay listen its the intel thing here all the idt needs to be in the struct at the same position like if we call something all of them needs to be in one place itself its the intel thing again 
 nothing can be done for it 
okay each and every idt first need some data within them think like pre requists okay so listen here the data is the 32 bits right so like the 32 bit address of the thing or the usecase 
of idt so the address of it is 32 bits in the ram so its broken in 2 parts 16 bits and 16 bits those are stored in the lower and the upper sec you can see that and then the zero again intel thing its just there reserved so think like if the address is like 0x10004000. so maybe like the lower is 0x4000 and the upper is the 0x1000 so how are these decided listen the compiler decides this one how ther compiler decides ?? its simply is the first come first serve thing whichever thing comes first it is given the thing so if the keybaord comes first it is somerthing like 100 if it comes later it maybe 500
the gdt selector in the gdt if you recall there are code and the data thing which of the thing is code and which is the data is we define the thing but the cpu needs to be modified for each of the things it is picked from the gdt and used it  if you recall the gdt was called in like the conversion of the cpu from the 16 bit to 32 bits so here like only and only the parts db 10011010b db 11001111b these thibngs in the code are the most important but with those we get those conversion fo all the parts to 0 so see its like the data is sotred in the ram and once these things are done we decide the code or data then we like get the data in our cpu and the interrupts which odf the interupts are there and which of them are not it have one thing 
now see the gdt is required in the thing the base here is the 32 bit cause see it is 32 bit cpu we got and its adrress of the gdt in the ram it represnets that and the limit is that we have the 255 idts and the each of the 8 bytes so the limit is that 
now see unsigned means positive in here and the int is integer we know it and the 16/8/32 there are bits which should be there so its like memory manangement here and the -t is just there its like inditicaton of we modified it */
