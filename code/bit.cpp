#include <stdio.h>

int main()
{

   char v = 0x0D;
   if  ( ( v & 0x0F ) == 0x0D )
        printf("Correct bit..");

   printf("%d\n", v );   

}