#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[50];
    float cgpa;
};

void bubbleSort(struct Student students[], int n);
void displayStudents(struct Student students[], int n);
void addStudent(struct Student students[], int *n);
void deleteStudent(struct Student students[], int *n);

int main() {
    struct Student students[MAX_STUDENTS];
    int n = 0;
    int choice;

    while (1) {
        printf("\nStudent Tracker System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &n);
                break;
            case 2:
                bubbleSort(students, n);
                displayStudents(students, n);
                break;
            case 3:
                deleteStudent(students, &n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void bubbleSort(struct Student students[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (students[j].roll > students[j + 1].roll) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(struct Student students[], int n) {
    if (n == 0) {
        printf("No students found.\n");
    } else {
        printf("\nRoll\tName\tCGPA\n");
        for (int i = 0; i < n; i++) {
            printf("%d\t%s\t%.2f\n", students[i].roll, students[i].name, students[i].cgpa);
        }
    }
}

void addStudent(struct Student students[], int *n) {
    printf("Enter roll, name, and CGPA: ");
    scanf("%d%s%f", &students[*n].roll, students[*n].name, &students[*n].cgpa);
    (*n)++;
}

void deleteStudent(struct Student students[], int *n) {
    int roll, i, flag = 0;
    printf("Enter roll to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < *n; i++) {
        if (students[i].roll == roll) {
            flag = 1;
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!flag) {
        printf("Student not found.\n");
    }
}
