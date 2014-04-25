#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strrindex(char*, char*);
int strrindex2(char*, char*);
int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <search string>\n", __FILE__);
        return 1;
    }
    
    printf("The result: %d\n", strrindex(argv[1], argv[2]));
    printf("The result: %d\n", strrindex2(argv[1], argv[2]));
    return 0;
}

int strrindex(char *s, char* t)
{ 
    unsigned len1 = strlen(s);
    unsigned len2 = strlen(t);
    if (len1 == 0 || len2 == 0 || len1 < len2) {
        return -1;
    }
    
    int i,j,k;
    for(i=len1-len2; i >= 0; i--) {
        for(j=i, k=0; s[j] != '\0' && s[j] == t[k]; j++,k++);
        if (t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

int strrindex2(char *s, char* t)
{ 
    unsigned len1 = strlen(s);
    unsigned len2 = strlen(t);
    if (len1 == 0 || len2 == 0 || len1 < len2) {
        return -1;
    }
    
    int i,j,k;
    for(i=len1-1; i >= 0; i--) {
        for(j=i, k=len2-1; k>=0 && s[j] == t[k]; j--,k--);
        if (k == -1) {
            return j+1;
        }
    }
    return -1;
}
