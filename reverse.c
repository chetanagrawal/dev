#include <stdio.h>

void reverse(char* a, int i)
{
    if (a[i] == '\0') {
        return;
    }
    reverse(a, i+1);
    printf("%c ", a[i]);
}

void reverse_inplace(char* a, int i, int j)
{
    printf("a=%s i=%d j=%d\n", a, i, j);
    if (i >= j) {
        return;
    }
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    reverse_inplace(a, i+1, j-1);
}
int main()
{
    char name[] = "chetan";
    //reverse(name, 0) ;
    //printf("\n");
    reverse_inplace(name, 0, sizeof(name)-2);
    printf("After inplace reverse: %s\n", name);
    return 0;
}
