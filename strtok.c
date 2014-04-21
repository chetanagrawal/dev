#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char del[10];
    char *token;
    printf("Eneter: <string> <delimiter>\n");
    scanf("%s%s", str, del);
    token = strtok(str, del);
    if (token) {
        printf("Token = %s\n", token);
    }
    while((token = strtok(NULL, del)) != NULL) {
        printf("Token = %s\n", token);
    }
    //printf("String=%s\nDelimiter=%s\n", str, del);
    return 0;
}

