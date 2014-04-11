#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double myatof(char*);
int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <string>\n", __FILE__);
        return 1;
    }
    
    printf("The result: %f\n", myatof(argv[1]));
    return 0;
}

double myatof(char *s)
{ 
    unsigned len1 = strlen(s);
    if (len1 == 0) {
        return -1;
    }
    
    int i,j,sign= 1,afterdot = 0, divide = 1;
    double d,num = 0, fraction= 0.0;
    for(; *s == ' '; s++);
    if (*s == '+' || *s == '-') {
        sign = *s == '+' ? 1 : -1;
        s++; 
    } 
    printf("s=%s\n", s);
    while(*s != '\0')
    {
       if (*s >= '0' && *s <= '9') {
            if(!afterdot) {
                num = num * 10 + (*s - '0');
            } else {
                divide = divide * 10;
                fraction = fraction + ((double)(*s - '0')/divide);
            }
        } else if (*s == '.') {
            afterdot = 1;
        } else {
            printf("Invalid character seen: %c\n", *s);
            return -1;
        }
        s++;
    } 
    return sign * (num + fraction);
}
