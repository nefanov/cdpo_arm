#include <stdio.h>
#include <string.h>
// put your shellcode here:
char *shellcode =   "\x01\x01\x01\x01"
                   
                    "\x94\x95\x96";
 
int main()
{
        printf(stdout,"Length of your code is: %d bytes\n",strlen(shellcode));
        (*(void(*)()) shellcode)(); // run your code as function
        return 0;
}
