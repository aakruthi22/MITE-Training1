#include <stdio.h>

void read(float* sal, int* cred, int* work) 
{
    printf("Enter salary:\n");
    scanf("%f", sal);  
    printf("Enter credit score:\n");
    scanf("%d", cred);  
    printf("Enter work experience:\n");
    scanf("%d", work);  
}

int iseligible(float sal, int cred, int work) 
{
    return ((sal >= 30000) && (cred >= 750) && (work >= 2));
}

int main() 
{ 
    float sal;
    int cred, work;
    read(&sal, &cred, &work);
    if (iseligible(sal, cred, work))
    {
        printf("Loan approved\n");
    } else {
        printf("Not eligible for loan\n");
    }
    return 0;  
}
