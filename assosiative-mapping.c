#include <stdio.h>
#include <string.h>

struct Student {
    char roll[20];
    char name[50];
    int mark;
};

struct Student students[100];
int count = 0;

void add_student() {
    printf("Enter Roll Number: ");
    scanf("%s", students[count].roll);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Mark: ");
    scanf("%d", &students[count].mark);

    count++;
    printf("Student added successfully!\n\n");
}

int find_student(char roll[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].roll, roll) == 0)
            return i;
    }
    return -1;
}

void update_mark() {
    char roll[20];
    printf("Enter Roll Number to Update: ");
    scanf("%s", roll);

    int idx = find_student(roll);
    if (idx != -1) {
        printf("Enter New Mark: ");
        scanf("%d", &students[idx].mark);
        printf("Mark updated!\n\n");
    } else {
        printf("Student not found!\n\n");
    }
}

void delete_student() {
    char roll[20];
    printf("Enter Roll Number to Delete: ");
    scanf("%s", roll);

    int idx = find_student(roll);
    if (idx != -1) {
        for (int i = idx; i < count - 1; i++) {
            students[i] = students[i + 1];
        }
        count--;
        printf("Student deleted!\n\n");
    } else {
        printf("Student not found!\n\n");
    }
}

void search_student() {
    char roll[20];
    printf("Enter Roll Number to Search: ");
    scanf("%s", roll);

    int idx = find_student(roll);
    if (idx != -1) {
        printf("Name: %s\n", students[idx].name);
        printf("Mark: %d\n\n", students[idx].mark);
    } else {
        printf("Student not found!\n\n");
    }
}

void display_all() {
    if (count == 0) {
        printf("No students found!\n\n");
        return;
    }

    printf("\n---- All Students ----\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %s | Name: %s | Mark: %d\n",
               students[i].roll,
               students[i].name,
               students[i].mark);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Student\n");
        printf("2. Update Mark\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: update_mark(); break;
            case 3: delete_student(); break;
            case 4: search_student(); break;
            case 5: display_all(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n\n");
        }
    }

    return 0;
}
