#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================= ENUM ================= */
// Define an enum called ProgramType
typedef enum {
    UNDERGRADUATE,
    POSTGRADUATE
} ProgramType;

/* ================= UNION ================= */
// Define a union called AcademicInfo
typedef union {
    float gpa;
    int research_hours;
} AcademicInfo;

/* ================= STRUCT ================= */
// Define a struct called Student
typedef struct {
    char name[100];
    int age;
    ProgramType program;
    AcademicInfo info; 
} Student;

/* ================= FUNCTION PROTOTYPES ================= */
void inputStudent(Student *s);
void displayStudent(Student s);

/* ================= MAIN FUNCTION ================= */
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    Student *students = (Student *)malloc(n * sizeof(Student));

    // Check if memory allocation failed
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit program with an error code
    }

    // Loop to input student data
    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        inputStudent(&students[i]);
    }

    // Display all student records
    printf("\n===== Student Records =====\n");
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    // Free allocated memory
    free(students);

    return 0;
}

/* ================= INPUT FUNCTION ================= */
void inputStudent(Student *s) {
    // Input name using the suggested format to capture spaces
    printf("Enter name: ");
    scanf(" %[^\n]", s->name);

    // Input age
    printf("Enter age: ");
    scanf("%d", &s->age);

    // Input program type
    int progChoice;
    printf("Enter Program (0 for Undergraduate, 1 for Postgraduate): ");
    scanf("%d", &progChoice);
    s->program = (ProgramType)progChoice;

    // Based on program: input GPA or research hours
    if (s->program == UNDERGRADUATE) {
        printf("Enter GPA: ");
        scanf("%f", &s->info.gpa);
    } else if (s->program == POSTGRADUATE) {
        printf("Enter research hours: ");
        scanf("%d", &s->info.research_hours);
    } else {
        printf("Invalid program selected.\n");
    }
}

/* ================= DISPLAY FUNCTION ================= */
void displayStudent(Student s) {
    printf("\nName: %s\n", s.name);
    printf("Age: %d\n", s.age);

    // Display program type and corresponding AcademicInfo
    if (s.program == UNDERGRADUATE) {
        printf("Program: Undergraduate\n");
        printf("GPA: %.2f\n", s.info.gpa);
    } else if (s.program == POSTGRADUATE) {
        printf("Program: Postgraduate\n");
        printf("Research Hours: %d\n", s.info.research_hours);
    } else {
        printf("Program: Unknown\n");
    }
}