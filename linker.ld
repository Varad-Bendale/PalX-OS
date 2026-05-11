ENTRY ( kernel) 
SECTIONS { 
  . = 0x100000
  .text : { *(.text) } 
  .data : { *(.data) } 
  .bss : { *(.bss) } 
 }


/* okay listen this thing is known as lnker the main thing of it is to store the address of the programme in the ram liek if you recall in the idt there was the thing where 
we like kept the address of the thing the compiler had the job to assign it well compiler makes a .o file which is completly binary and now its the job of the linker to give it the address and the header looking at the all the code in there  why not in the idt itself well it is used in all the files all the boot all the kernel and all of those so yeah it is like so the address is like this well also 
why not keep the address standerd cause each and everyu processor each and every ram are different the ram which are occupied ealrier are different dso making a seperate 
file was kinda nessesary 
about the .text :- CPU should EXECUTE this
          .data :- CPU should READ/WRITE this
          .bss  :- CPU should just ZERO this out at start

okay so what are these these are different different types of things in the code wwe havce like the variable or the funtion name like htere are spepcifc tasks to it elike
 see our compiler first compiles the code and converts it in to the binary thing but now the cpu needs the persmissions and only limit permissions are there for each and 
every of these names they have like only read write is there the cpu cannot execute it like that so the linker does is it looks in the code stores all of the thing 
segereagtes all of it and then the header is created whats header suppose like a manual for the machine it contains all the infornmation about eveyrhting what size what it
 is what are the persmissions given all of them in header and before the cpu goes towards thwe main code to run the code the cpu looks for all the header and persmssions 
knowing all the context and only run as per it 
why segregations is important think of like a hacker is there he changed some file and tries to execute it but as the cpu only have permission to read write not the excute
 he cannot execue and enter in the system like that you can imagine 

now why not just keep it in the compiler itself well you can each and every file which is present the compiler is very much self sufficient to store all these parts and 
segreagate them on its own but one of the levrage which this linker got is it have all the files access right so in any case we changed some settings or changed some things 
in the file the linker can automatically detect that okjay this was changed and these funtions are present in these all different different files and need to be changed as
 well now how does the linker get it it uses the tol known as make it is called whenever the thing is changed then we like get this funtion  things and then it figuers out what is changed and what needs to be changed so yeah its useful that way 

so see like the rules or the permissions were manually written down by our great tech people and even the as per permissions our cpu does its job as per it its all linked 
up thats why linker haha  */