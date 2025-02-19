#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[50];
    int age;
    char dest[50];
} Passenger;

void addPassenger(Passenger pas[],int *count)
{
    if (*count>=100) {
        printf("Cannot add more passengers\n");
        return;
    }
    
    printf("Passenger %d: ", *count+1);
    printf("Enter name: ");
    scanf("%s", pas[*count].name);
    printf("Enter age: ");
    scanf("%d", &pas[*count].age);
    printf("Enter destination: ");
    scanf("%s", pas[*count].dest);
    
    (*count)++;
}

void sortPassengers(Passenger pas[], int count)
{
    Passenger temp;
    for (int i=0;i<count-1;i++) {
        for (int j=i+1;j<count;j++) {
            if (strcmp(pas[i].dest, pas[j].dest) > 0) {
                temp=pas[i];
                pas[i]=pas[j];
                pas[j]=temp;
            }
        }
    }
}

void search(Passenger pas[], int count, const char *dest) 
{
    int found=0;
    printf("Passengers traveling to %s: ",dest);
    for (int i=0;i<count;i++) {
        if (strcmp(pas[i].dest,dest)==0) {
            printf("%s",pas[i].name);
            found=1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() 
{
    Passenger pas[100];
    int count=0;
    int n;
    printf("Enter number of passengers: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
    {
        addPassenger(pas,&count);
    }
    sortPassengers(pas,count);
    printf("\nSorted List (by destination):\n");
    for (int i=0;i<count;i++) {
        printf("%s - %s\n", pas[i].name, pas[i].dest);
    }
    char searchd[50];
    printf("\nEnter destination to search: ");
    scanf("%s", searchd);
    search(pas,count,searchd);
    return 0;
}
