#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    float weight[n];
    int accepted_product = 0, rejected_product = 0;
   
    for(int i = 0; i < n; i++)
    {
        printf("Enter weight (in grams) for product %d: ", i + 1);
        scanf("%f", &weight[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(weight[i] >= 950 && weight[i] <= 1050)
        {
            accepted_product++;
        }
        else
        {
            rejected_product++;
        }
    }

    printf("Total accepted products: %d\n", accepted_product);
    printf("Total rejected products: %d\n", rejected_product);

    return 0;
}
