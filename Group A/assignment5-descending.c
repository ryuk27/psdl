#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void) {
    int i,j,temp;
    int num_desc[]= {10,2,5,1,6};

    for(i=0; i<=4; i++){                  // point to LHS number
        for(j=i+1;j<=4;j++)               // point to RHS number
        if (num_desc[i] < num_desc[j]){     // if LHS > RHS , change the position
            temp = num_desc[i];
            num_desc[i] =num_desc[j];
            num_desc[j]= temp;
        }
    }
}
