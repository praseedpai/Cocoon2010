

long Add( long a , long b ) {

    return a + b;
}


char addfunc[] = { 0x55,                 // push EBP 
                   0x8B, 0xEC,           // mov ebp,esp   
                   0x8B, 0x45 , 0x08,    // mov eax,dword ptr [ebp+8] 
                   0x03, 0x45 , 0x0c,    // add eax,dword ptr [ebp+12]
                   0x5D,                 // pop ebp
                   0xC3                  // ret
                 };


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef long (*BIN_FUNC)( long a , long b );

int main( int argc , char **argv )
{

    DWORD oldprotect ;

    VirtualProtect(addfunc, 128 , PAGE_EXECUTE, &oldprotect);
    BIN_FUNC func  = (BIN_FUNC)((void *)addfunc); 
    FlushInstructionCache(GetCurrentProcess(),0,0);
    long c = (*func)(4,3);    
    VirtualProtect(addfunc, 128, oldprotect, &oldprotect);
    printf("%d\n",c );


}