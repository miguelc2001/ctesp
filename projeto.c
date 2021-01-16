#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct student {
    char firstName[20];
    char lastName[20];
    int number;
} stu[20];

struct subject {
    char name[20];
    int year;
    int semester;
} sub[20];


void printMainMenu();
void printStudentsMenu();
void printSubjectsMenu();
void insertStudents();
void insertSubjects();

int main(){
    int choice;
   
    insertStudents();
    insertSubjects();

    return 0;
}

void printMainMenu(){
    
    printf("**** Welcome to School Management System ****\n\n\n");
    printf("          MAIN MENU\n");
    printf("==============================\n");
    printf("[1] Students Menu\n");
    printf("[2] Subjects Menu\n");
    printf("[0] Exit\n");
    printf("==============================\n");
}

void printStudentsMenu(){
    
    printf("**** Welcome to School Management System ****\n\n\n");
    printf("        STUDENTS MENU\n");
    printf("==============================\n");
    printf("[1] Add a new Student\n");
    printf("[2] List all Students\n");
    printf("[3] Search for a Student\n");
    printf("[4] Edit a Student information\n");
    printf("[5] Delete a Student\n");
    printf("[0] Exit\n");
    printf("==============================\n");
}

void printSubjectsMenu(){
    
    printf("**** Welcome to School Management System ****\n\n\n");
    printf("        SUBJECTS MENU\n");
    printf("==============================\n");
    printf("[1] Add a new Subject\n");
    printf("[2] List all Subject\n");
    printf("[3] Search for a Subject\n");
    printf("[4] Edit a Subject information\n");
    printf("[5] Delete a Subject\n");
    printf("[0] Exit\n");
    printf("==============================\n");
}

void insertStudents(){

    //number of students to add
    int n;
    printf("Number of Students to add: ");
    scanf("%d", &n);

    // storing information
    for (int i = 0; i < n; ++i){
        printf("Enter students number: ");
        scanf("%d", &stu[i].number);
        printf("Enter first name: ");
        scanf("%s", &stu[i].firstName);
        printf("Enter last name: ");
        scanf("%s", &stu[i].lastName);
    }
}

void insertSubjects(){

    //number of subjects to add
    int n;
    printf("Number of Subjects to add: ");
    scanf("%d", &n);

    //storing information
    for (int i = 0; i < n; i++){
        printf("Enter subjects name: ");
        scanf("%s", &sub[i].name);
        printf("Enter subjects year: ");
        scanf("%d", &sub[i].year);
        printf("Enter subjects semester: ");
        scanf("%d", &sub[i].semester);
    }

}