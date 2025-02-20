#include <stdio.h>
struct employee 
{
    int id;
    char name[50];
    float salary;
};

typedef struct employee emp;
void reademployee(emp empl[], int n);
void displayemployee(emp empl[], int n);
void findhighest(emp empl[],int n);

int main() 
{
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    emp employees[1000];
    reademployee(employees,n);
    displayemployee(employees,n);
    findhighest(employees,n);
    return 0;
}

void reademployee(emp empl[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter employee name: ");
        scanf("%s", empl[i].name);
        printf("Enter employee id: ");
        scanf("%d", &empl[i].id);
        printf("Enter employee salary: ");
        scanf("%f", &empl[i].salary);
    }
}

void displayemployee(emp empl[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("Employee %d name: %s\n",i+1, empl[i].name);
        printf("Employee %d id: %d\n", i + 1, empl[i].id);
        printf("Employee %d salary: %0.2f\n", i + 1, empl[i].salary);
        printf("\n");
    }
}
void findhighest(emp empl[],int n)
{
   emp highest=empl[0];
    for (int i=1;i<n;i++) 
    {
        if (empl[i].salary>highest.salary) {
            highest=empl[i];
        }
    }
    printf("Employee with highest salary:%s\n", highest.name);
}
