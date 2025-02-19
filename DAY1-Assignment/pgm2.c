#include <stdio.h>
void main() 
{
    int n,i,j;
    printf("Enter the number of rows for the triangle: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= i; j++) 
        {
            printf("* ");
        }
        printf("\n");
    }
}
