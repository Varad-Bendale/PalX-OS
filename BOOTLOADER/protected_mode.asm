[bits 16] 
protected_mode : 
cli 
lgdt [gdt descriptor]
mov exa  , cr0 
or cr0 , 1 
mov cr0 , exa 
jmp 0x08 : init_protected

[bits 32]
init_protected : 
mov ax , 0 
mov ds , ax 
mov ss , ax
mov es , ax 
mov fs , ax 
mov gs , ax 
mov ebp , 0x90000 
mov esp , ebp

call kernel_main 

; okay see here we are simply switching the cpu from 16 bit to 32 bit so first we terminate all the interupts pressent or comming and then we bring gdt purpose of gdt is simply to take the things and make al; cpu ready for the 32 bit ways it just initializes all the segments code/data and like sets all the boundiries and limits so this is the thing now ourt cr0 is the register in the cpu which is responsible to; cpu to be protected see the list of the cr are like the settings of the cpu and to change each of the settings just lik emake use of diffetn different hash maps like exa used in here and the nest part all ; the necessary registers are requried to directly like flush to 0 as all those registers now store the value as per the 16 bit but we need to erase those values so we just erase them again same thing we nee; d to use the temporary bits/registers for the  thing cuase if not it breaks so thats thew thing and the ebp and esp are the 2 stack variables these are like we used the temporary varaibles for dfoinfg the ; thing na we dont need to use them spserately again and again in the thing we just simply use these stacks simply and then we switch and then to directly kernel simple 
