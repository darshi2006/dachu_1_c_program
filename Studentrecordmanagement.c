#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M#AX_STUDENTS 100
typedef struct {
    int id;
    char name[50];
    int rollNumber;
    float marks;
} Student;
Student students[MAX_STUDENTS];
int studentCount = 0;
void addStudent();
void viewStudents();
void editStudent();
void deleteStudent();
void displayMenu();
int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:               addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void displayMenu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Edit Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
}
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }
    Student s;
    s.id = studentCount + 1; 
    printf("Enter name: ");
    getchar();
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter roll number: ");
    scanf("%d", &s.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    students[studentCount++] = s;
    printf("Student added successfully!\n");
}
void viewStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tRoll Number\tMarks\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", students[i].id, students[i].name, students[i].rollNumber, students[i].marks);
    }
}
void editStudent() {
    int id, found = 0;
    printf("Enter the ID of the student to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Editing student with ID %d:\n", id);
            printf("Enter new name: ");
            getchar(); 
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; 
            printf("Enter new roll number: ");
            scanf("%d", &students[i].rollNumber);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
void deleteStudent() {
    int id, found = 0;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1]; 
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
