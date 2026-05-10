#include<IDT.h>

struct idt = IDT[255] ; 
struct limits = idt_lims ; 
void default_idt_data_fill(int num , unsigned_int32_t  address ){
  IDT[num].lower_sec =  address & 0xffff   
  IDT[num].gdt_selector  = 0x08; 
  IDT[num].zero  =  0 ; 
  IDT[num].interupts  = 0x8E ; 
  IDT[num].higher_sec  = (  address << 16 )  & 0xffff ; 
}

void main () { 
idt_lims.limit = ( sizeof(struct(IDT))*255 ) -1 
idt_lims.base = (uint32_t)&idt
default_idt()
asm volatile("lidt %0" : : "m"(idtp))
} 

void default_idt() { 
for ( int i = 0 ; i <=255 ; i++){
default_idt_data_fill(i , addr) 
} 
} 

void addr(){ 
} 

/* okay lets address the elephant in the room what the hell is this idt and why is it there so listen its like all the iot devices like keyboard the mouse or maybe
 all the special programmes which are there which the funtions would be formedd of everything like for an example we need like a keybaord we wanbt like if the 
keybaord is hit the alphabet should appear on the computer so its just like this is a funtion we need those but before that we need like a table and the prerequists 
of certain infornmation of each and every of the thing what are those have a look in the idt.h i have wrote over there so its just like we have a struct of the each 
and every programme and then we like call those funtions as per the programme think its like a hashmap it just points out all the funtions as per the programme so 
here we just have given all the prequists the default one and which ever requires a new one we can manually edit it as we want limit and base same explained in the 
different file and now about the & with the 0xffff see its like the we want to segregate the 16-16 bit things right so we just like 0xffff is like 16 ones and if we 
do the ampersant with it we just get the lower 16 bits thing directly and get those values and same statergy with the upper part and about the addr now listen its 
the work of compiler .  compiler gives the address of the thing and and for compiler to do the work we just keep the empty funtion for it see compiler dont actually 
need an empty  but if any of the interupts comes in it sees the empty funtion the thing is fine like it doesnt go like raises issues or like trigger some error 
control things funtion handlin g interupts is it like interupts comes it sees something new it looks any funtion like that it finds and the interupots is gone and as 
there is nothing in there nothing happens and then the compiler assings the address to the thing is it like that 
okay one more thing i need you to know is like see here we have done the addr itself the compiler goes look at the new word assigns in the ram give the address of it
 now listen it shows the same address to everywhere okay each adn every 256 things same adrress only the things with real hardware needs to be changed or real 
funtionalisites needs to be changed or overwirted rest of them are never called why make them in firsrt place intel stuff bruh i hope it clears out */
