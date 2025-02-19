#include <stdio.h>
#include <string.h>
void main() 
{
    int paymentmethod;
    char cardnum[17]; 
    char upi[50];     
    int bank;
    printf("Select payment method (1-3):\n");
    printf("1.credit/debit Card\n");
    printf("2.UPI\n");
    printf("3.Net banking\n");
    scanf("%d",&paymentmethod);
    switch (paymentmethod) 
    {
        case 1:
            printf("Enter your 16-digit card number: ");
            scanf("%s", cardnum);
            if (strlen(cardnum) == 16) 
            {
                printf("Payment Successful\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;

        case 2: 
            printf("Enter your UPI ID: ");
            scanf("%s",upi);
            printf("Payment Successful!\n");
            break;

        case 3: 
            printf("Select your bank:\n");
            printf("1. SBI\n");
            printf("2. HDFC\n");
            printf("3. ICICI\n");
            printf("Enter your choice: ");
            scanf("%d", &bank);
            if (bank>= 1 && bank<= 3)
            {
                printf("Payment successful!\n");
            } else {
                printf("Transaction failed please try again.\n");
            }
            break;

        default: 
            printf("Invalid payment method please try again.\n");
            break;
    }
}
