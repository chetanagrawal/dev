#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strindex(char*, char*);
int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <search string>\n", __FILE__);
        return 1;
    }
    
    printf("The result: %d\n", strindex(argv[1], argv[2]));
    return 0;
}

int strindex(char *s, char* t)
{ 
    unsigned len1 = strlen(s);
    unsigned len2 = strlen(t);
    if (len1 == 0 || len2 == 0 || len1 < len2) {
        return -1;
    }
    
    int i,j,k;
    for(i=0; s[i] != '\0'; i++) {
        for(j=i, k=0; s[j] != '\0' && s[j] == t[k]; j++,k++);
        if (t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
