#include <stdio.h>
#include <string.h>

int main()
{
    int i,n,total=0;
    char vehicle[100];
    int car=50;
    int truck= 100;
    int bike=20;
    printf("Enter number of vehicles:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Enter vehicle type (Car/Truck/Bike): ");
        scanf("%s", vehicle);
        if (strcmp(vehicle, "car") == 0) 
        {
            total+= car;
        } else if (strcmp(vehicle, "truck") == 0)
        {
            total += truck;
        } else if (strcmp(vehicle, "bike") == 0) 
        {
            total += bike;
        } else {
            printf("Invalid vehicle type.\n");
            i--; 
        }
    }

    printf("Total Toll Collection: ₹%d\n", total);

    return 0;
}  
