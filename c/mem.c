#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 10
int main()
{
    char *mem;
    mem = (char *)malloc(MAXLEN);
    memset(mem, 'a', MAXLEN/2);
    memset(mem + MAXLEN/2, 'b', MAXLEN/2);
    printf("Memory=%s\n", mem);
    printf("Size of memory=%d\n", (int)strlen(mem));
    char test[] = { 'c', 'h', 'e', 't', 'a', 'n', '\0'};
    printf("String=%s, Size of string=%d , array size=%d\n", test, (int)strlen(test), (int) sizeof(test));
    memcpy(mem + MAXLEN/2, mem +10, MAXLEN/2);
    printf("Memory=%s\n", mem);
    return 0;
}
