ifndef pic
#define pic 
#define pic_master 0x20 
#define pic_slave  0xA0
#define pic_master_data 0x21
#define pic_slave_data 0xA1
#define pic_end 0x20

#endif 

/* okay pic are all the interrupts which the cpu use for like the executing all the programmes see the cpu needs a interrupts that okay this function or this programme needs to be executed stop all and focus on this one so thats why the interrupts are needed and also see we are working on the x-86 processor to make the os atp so making it is the thing is or the architecture goes like 

Master PIC          Slave PIC
──────────          ──────────
IRQ 0 → Timer       IRQ 8  → RTC
IRQ 1 → Keyboard    IRQ 9  → Network
IRQ 2 → SLAVE ──→   IRQ 10 → USB
IRQ 3 → COM2        IRQ 11 → unused
IRQ 4 → COM1        IRQ 12 → Mouse
IRQ 5 → Sound       IRQ 13 → FPU
IRQ 6 → Floppy      IRQ 14 → Primary Disk
IRQ 7 → Printer     IRQ 15 → Secondary Disk

At the earlier times there existed only the 8 interrupts port on the cpu so yes they made it like a nested thing to get access to all of them 
Now listen here all the first 2 are the commands which needs to be given and the last 2 are the data which the interrupts need to carry are like the instructions which are there like follow this and ignore these like that stuff 

Now listen here we are like posting all the functions name here reason see the c compiler issue it is see the compiler gives error if it doesn't see the stuff earlier on like in main function t sees the function name and if the function is defined in the lower of the main function then it gives out error now we can be careful with these at one file but at the multiple files it can be the issue to make them in order so we initialise it in the .h files only it is better like it would show error as it would have seen the name earlier one */ 