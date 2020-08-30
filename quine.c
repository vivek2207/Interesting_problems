#include <stdio.h> 
   
int main(void) 
{ 
    //  This code can be appended into any source code to print the code itself.
  
    char c;  
    FILE *fp = fopen(__FILE__, "r"); 
   
    do
    { 
        c = fgetc(fp); 
        putchar(c); 
    } 
    while (c != EOF); 
   
    fclose(fp); 
   
    return 0; 
}
