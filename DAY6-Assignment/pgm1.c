#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    int marks;
} Student;

int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->marks - studentA->marks;
}

int binarySearch(Student students[], int size, int roll_no) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].roll_no == roll_no) {
            return mid;
        } else if (students[mid].roll_no < roll_no) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void displayTopStudents(Student students[], int size) {
    printf("Top 3 Students:\n");
    for (int i = 0; i < size && i < 3; i++) {
        printf("%s (Roll No: %d, Marks: %d)\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Roll No, Name and Marks for student %d: ", i + 1);
        scanf("%d %s %d", &students[i].roll_no, students[i].name, &students[i].marks);
    }

    qsort(students, n, sizeof(Student), compare);

    printf("\nSorted by Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Roll No: %d, Marks: %d)\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    displayTopStudents(students, n);

    int roll_no_to_search;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll_no_to_search);
    int index = binarySearch(students, n, roll_no_to_search);
    if (index != -1) {
        printf("Found: %s (Roll No: %d, Marks: %d)\n", students[index].name, students[index].roll_no, students[index].marks);
    } else {
        printf("Student with Roll No %d not found.\n", roll_no_to_search);
    }

    return 0;
}
