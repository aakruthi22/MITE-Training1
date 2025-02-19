#include <stdio.h>
float calculate(float bill) 
{
    float discount = 0.0;
    if(bill>=500 && bill<=1000) 
    {
        discount = 0.10;
    } else if(bill>1000) 
    {
        discount = 0.20;
    }
    return bill*(1-discount); 
}
int main() 
{
    float bill;
    printf("Enter total bill amount:");
    scanf("%f", &bill);
    float final= calculate(bill);
    printf("Final Payable Amount: ₹%.2f\n", final);
    return 0;
}
