#include <stdio.h>

#define SIZE 10

void quicksort(int *a, size_t n);
int main()
{
    int i;
    int a[SIZE] = { 4, 6, 10, 6, 90,8, 1 , 34,77, 40 };
    for(i=0; i<SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    quicksort(a, SIZE);
    for(i=0; i<SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
void quicksort(int *a, size_t n)
{
    if (n <= 1) {
        return;
    }
    int i,j,k, mid, temp, pos;
    mid = a[n/2];
    int correct = mid;
    i=0;
    j=n-1;
    printf("Before exchange: i=%d mid=%d j=%d\n", i,mid,j);
    while(i < j)
    {
        while(a[i] <= mid)
        {
            i++;
        }
        while(a[j] > mid) 
        {
            j--;
        }
        if (i < j) {
            printf("\tExchanging %d and %d ... \n", a[i], a[j]);
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            pos = j;
            for(k=0; k<SIZE; k++) {
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
    printf("%d is now at correct position %d. n=%d i=%d j=%d\n", correct, pos, n, i, j);
            for(k=0; k<SIZE; k++) {
                printf("%d ", a[k]);
            }
            printf("\n");
    printf("Left quick sort with n = %d\n", pos-1);
    quicksort(a, pos-1);
    printf("Right quick sort starting at index %d with n = %d\n",pos+1, n-pos-1);
    quicksort(a+pos+1, n-pos-1);
    //quicksort(a+mid+1, n%2? mid : mid - 1);
} 
        
     
