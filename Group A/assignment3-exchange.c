#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>
void main(void) {

    int temp,i;
    int source1[] = {0x21,0x22,0x23,0x24,0x25};
    int dest[] = {0x91,0x92,0x93,0x94,0x95};

    for(i=0; i<=4;i++){
      temp = source1[i];
      source1[i] = dest[i];
      dest[i] = temp;

    }
}
