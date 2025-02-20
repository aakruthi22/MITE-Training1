#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100
#define FILENAME "car_rentals.txt"

typedef struct {
    int carID;
    char model[50];
    union {
        float dailyRent;
        float totalRent;
    } rent;
} Car;

Car cars[MAX_CARS];
int carCount = 0;

void addCar() {
    if (carCount >= MAX_CARS) {
        printf("Cannot add more cars. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter Car ID: ");
    scanf("%d", &cars[carCount].carID);
    printf("Enter Model: ");
    scanf(" %[^\n]", cars[carCount].model);
    printf("Enter Rent Per Day: ₹");
    scanf("%f", &cars[carCount].rent.dailyRent);
    
    carCount++;
    printf("Car added successfully!\n");
}

void displayCars() {
    printf("\nCars Available:\n");
    for (int i = 0; i < carCount; i++) {
        printf("%d. %s - ₹%.2f/day\n", i + 1, cars[i].model, cars[i].rent.dailyRent);
    }
}

void saveToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < carCount; i++) {
        fprintf(file, "%d,%s,%.2f\n", cars[i].carID, cars[i].model, cars[i].rent.dailyRent);
    }
    
    fclose(file);
    printf("Data saved in \"%s\"\n", FILENAME);
}

void updateCar() {
    int id, found = 0;
    printf("Enter Car ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < carCount; i++) {
        if (cars[i].carID == id) {
            found = 1;
            printf("Updating details for %s:\n", cars[i].model);
            printf("Enter new Model: ");
            scanf(" %[^\n]", cars[i].model);
            printf("Enter new Rent Per Day: ₹");
            scanf("%f", &cars[i].rent.dailyRent);
            printf("Car updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Car with ID %d not found.\n", id);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nCar Rental System\n");
        printf("1. Add Car\n");
        printf("2. Display Cars\n");
        printf("3. Save to File\n");
        printf("4. Update Car\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                displayCars();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                updateCar();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
