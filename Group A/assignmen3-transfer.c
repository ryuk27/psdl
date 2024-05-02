#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>
void main(void) {

    int temp,i;
    int source1[] = {0x21,0x22,0x23,0x24,0x25};   // source mem block
    int dest[] = {0x00,0x00,0x00,0x00,0x00};      // destination mem block

    for(i=0; i<=4;i++){                          // counter = 5
      
      dest[i] = source1[i];                      // source to destination
      
    }
}
