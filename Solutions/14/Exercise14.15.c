#include <stdio.h>

//#define ENGLISH
#define SPANISH
//#define FRENCH

int main(void)
{
#if defined(ENGLISH)
    printf("Insert Disk 1\n");
#elif defined(SPANISH)
    printf("Inserte El Disco 1\n");
#elif defined(FRENCH)
    printf("Inserez Le Disque 1\n");
#endif
    
    return 0;
}