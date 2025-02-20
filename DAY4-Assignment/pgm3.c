#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMPLOYEES 100
#define FILENAME "payroll.txt"

typedef struct 
{
    int empID;
    char name[50];
    float basicSalary;
    float allowances;
    float grossSalary;
}Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Cannot add more employees\n");
        return;
    }
    
    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].empID);
    printf("Enter Name: ");
    scanf(" %[^\n]", employees[employeeCount].name);
    printf("Enter Basic Salary: ₹");
    scanf("%f", &employees[employeeCount].basicSalary);
    printf("Enter Allowances: ₹");
    scanf("%f", &employees[employeeCount].allowances);
        employees[employeeCount].grossSalary = employees[employeeCount].basicSalary + employees[employeeCount].allowances;
    
    employeeCount++;
    printf("Employee added successfully!\n");
}

void saveToFile() 
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < employeeCount; i++) {
        fprintf(file, "%d,%s,%.2f,%.2f,%.2f\n", employees[i].empID, employees[i].name, employees[i].basicSalary, employees[i].allowances, employees[i].grossSalary);
    }
    
    fclose(file);
    printf("Record saved in \"%s\"\n", FILENAME);
}

void retrieveEmployeeSalary()
{
    int id, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].empID == id) {
            found = 1;
            printf("Employee: %s\n", employees[i].name);
            printf("Gross Salary: ₹%.2f\n", employees[i].grossSalary);
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() 
{
    int choice;
    do {
        printf("\nEmployee Payroll System\n");
        printf("1. Add Employee\n");
        printf("2. Save to File\n");
        printf("3. Retrieve Employee Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                addEmployee();
                break;
            case 2:
                saveToFile();
                break;
            case 3:
                retrieveEmployeeSalary();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}
