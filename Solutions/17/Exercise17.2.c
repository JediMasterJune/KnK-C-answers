//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplicate(char* str);

int main(void)
{
    char* str = "hello, world\n";
    char* str2 = duplicate(str);
    printf("%s%s", str, str2);
    printf("%d %d", sizeof(str), strlen(str) + 1);
    return 0;
}

char* duplicate(char* str)
{
    char* str_cpy = malloc(strlen(str) + 1);
    if (str_cpy == NULL) {
        return str_cpy;
    }
    strcpy(str_cpy, str);
    return str_cpy;
}
