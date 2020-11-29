#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main (void) {

    int last = 0;
    create_stack();
    push(0);
    
    printf("> ");
    

    while (1) {
	
	int input_char;
	
        input_char = getchar();
	
	if (input_char == ' ') {
		last = 1;
	}

        if (input_char == '\n') break;

	if ('0' <= input_char && input_char <= '9') {
            int cval = input_char - '0';
	    if (last == 1) {
	    	push(cval); 
		last = 0;
	    } else {
	    	push(pop() * 10 + cval);
	    }  
        }
        
 	if (input_char == '+') 
             push(pop() + pop());
        
        if (input_char == '-') {
            int arg2 = pop();
            int arg1 = pop();
            push(arg1 - arg2);
        }
	
        if (input_char == '*') 
            push(pop() * pop()) ;
       
	
    } 

    printf("> %d\n", top());
    
    return 0;
}
