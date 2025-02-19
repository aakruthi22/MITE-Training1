#include <stdio.h>
#include <stdlib.h>
struct employee {
    char name[50];
    float salary;
    int id;
    int attendance;
};
int main()
{
    int i, n;
    struct employee *emp;
    printf("Enter total number of employees: ");
    scanf("%d", &n);
    emp = (struct employee *)malloc(n * sizeof(struct employee));
    if (emp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter employee name: ");
        scanf("%s", emp[i].name);

        printf("Enter %s salary: ", emp[i].name);
        scanf("%f", &emp[i].salary);

        printf("Enter %s id: ", emp[i].name);
        scanf("%d", &emp[i].id);

        printf("Enter %s attendance per month: ", emp[i].name);
        scanf("%d", &emp[i].attendance);
    }

    for (i = 0; i < n; i++) {
        if (emp[i].attendance > 25)
        {
            emp[i].salary=(emp[i].salary/100*5)+emp[i].salary;
            printf("Employee name: %s\t Employee id: %d\t", emp[i].name, emp[i].id);
            printf("Employee Salary: %.2f\t Employee attendance: %d\t Employee status: Excellent\n", emp[i].salary, emp[i].attendance);
        } else if (emp[i].attendance > 10 && emp[i].attendance <= 25) {
            printf("Employee name: %s\t Employee id: %d\t", emp[i].name, emp[i].id);
            printf("Employee Salary: %.2f\t Employee attendance: %d\t Employee status: Good\n", emp[i].salary, emp[i].attendance);
        } else if (emp[i].attendance < 10) {
            emp[i].salary /= 0.5;
            printf("Employee name: %s\t Employee id: %d\t", emp[i].name, emp[i].id);
            printf("Employee Salary: %.2f\t Employee attendance: %d\t Employee status: Needs improvement\n", emp[i].salary, emp[i].attendance);
        } else {
            printf("Invalid attendance data for %s\n", emp[i].name);
        }
    }

    free(emp);
    return 0;
}
