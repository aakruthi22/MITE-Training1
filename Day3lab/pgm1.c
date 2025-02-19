#include <stdio.h>
void calculate(int marks[][6],int n,int totalMarks[]) 
{
    for(int i=0;i<n;i++)
    {
        totalMarks[i] = 0;
        for (int j = 0; j < 6; j++) {
            totalMarks[i] += marks[i][j];
        }
    }
}

void sortStudents(int totalMarks[], int n) 
{
    for(int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (totalMarks[j]<totalMarks[j+1])
            {
                int temp=totalMarks[j];
                totalMarks[j]=totalMarks[j+1];
                totalMarks[j+1]=temp;
            }
        }
    }
}

int main() 
{
    int n,m;
    int marks[100][6];
    int totalMarks[100];

    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        printf("Enter marks for Student %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    calculate(marks, n, totalMarks);
    sortStudents(totalMarks, n);

    printf("\nSorted Total Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Total Marks = %d\n", i + 1, totalMarks[i]);
    }
    return 0;
}
