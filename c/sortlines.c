#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
#define MAXLINES 100

int getnewline(char*line, int limit)
{
    int i=0,c;
    while((c=getchar()) != EOF && c != '\n' && i<limit) {
        line[i++]=c;
    }
    if (c =='\n') {
        line[i++]=c;
    }
    line[i]='\0';
    return i;
}


int main()
{
    int i=0,j=0,n;
    char line[MAXLEN];
    char *lines[MAXLINES];
    while((n=getnewline(line, MAXLEN)) > 0) {
        lines[i]= (char *)malloc(n*sizeof(int));;
        strcpy(lines[i], line);
        i++;
    }
    while(j<=i) {
        printf("%s", lines[j++]);
        //free(lines[j]);
    } 
    return 0;
}
        
