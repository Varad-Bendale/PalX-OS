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
    temp.c_lflag &= ~(ECHO|ICANON|ISIG ) ; 
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

