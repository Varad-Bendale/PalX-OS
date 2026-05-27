#include<stdio.h>
#include<unistd.h> 
#include<termios.h>
#include<ctype.h>
#include<stdlib.h>
struct termios original  ; 

void disable_raw_mode(){
    tcsetattr( STDIN_FILENO ,TCSAFLUSH ,  &original) ;
}

void rawmode(){
    tcgetattr( STDIN_FILENO , &original) ;
    struct termios temp = original ; 
    temp.c_iflag &= ~(IXON | ICRNL ) ; 
    temp.c_oflag &= ~(OPOST ) ; 
    temp.c_lflag &= ~(IEXTEN|ECHO|ICANON|ISIG ) ; 
    temp.c_cc[VMIN] = 0
    temp.c_cc[VTIME] = 1
    temp.c_oflag &= ~(OPOST ) ; 

    tcsetattr(STDIN_FILENO ,TCSAFLUSH ,  &temp) ; 
    atexit(disable_raw_mode ) ; 
}

int main(){
    rawmode() ; 
    char c  ; 
    while(read(STDIN_FILENO , &c , 1 ) == 1 && c != 'q') {
    if (iscntrl(c)){ 
       printf("%d\r\n" ,c) ; 
    }
    else { 
        printf("%d (%c) \r \n " , c , c ) ; 
    }
}
    return 0 ; 
} 

