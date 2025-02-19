#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name; 
    int marks;
} Student;

int main() 
{
    int num, i;
    printf("Enter number of students: ");
    scanf("%d", &num);

    Student *stud = (Student *)malloc(num * sizeof(Student));
    if (stud == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1; 
    }

    for (i = 0; i < num; i++) 
    {
        stud[i].name = (char *)malloc(100 * sizeof(char));
        if (stud[i].name == NULL) 
        {
            printf("Memory allocation for name failed\n");
            return 1; 
        }
        printf("Enter student %d name: ", i + 1);
        scanf("%s", stud[i].name);
        printf("Enter marks: ");
        scanf("%d", &stud[i].marks);
    }

    printf("\nStudent Records:\n");
    for (i = 0; i < num; i++) 
    {
        printf("Name:%s\t Marks:%d\n", stud[i].name, stud[i].marks);
    }

    for (i = 0; i < num; i++)
    {
        free(stud[i].name);
    }
    free(stud); 

    return 0; 
}
