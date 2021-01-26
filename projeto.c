#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct student {
    char firstName[20];
    char lastName[20];
    int number;
}stu;

struct subject {
    char name[20];
    int year;
    int semester;
}sub;


void MainMenu();
void StudentsMenu();
void SubjectsMenu();
void insertStudent(FILE * st);
void insertSubject(FILE * su);
void displayStudent(FILE * st);
void displaySubject(FILE * su);
void searchStudent(FILE * st);
void searchSubject(FILE * su);
void editStudent(FILE * st);
void editSubject(FILE * su);
FILE delStudent(FILE * st);
FILE delSubject(FILE * su);


int main(){
    
    MainMenu();

    return 0;
}

void MainMenu(){
    
    int option;
    int i = 1;

    while (i == 1)
    {
        printf("**** Welcome to School Management System ****\n\n");
        printf("          MAIN MENU\n");
        printf("==============================\n");
        printf("[1] Students Menu\n");
        printf("[2] Subjects Menu\n");
        printf("[0] Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            StudentsMenu();
            i = 1;
            break;
        case 2:
            SubjectsMenu();
            i = 1;
            break;
        case 0:
            i++; 
            break;
        default:
            break;
        }
    }
    
    
}

void StudentsMenu(){
    
    FILE * st;
    st = (fopen("students.txt","w+"));
    if(st == NULL)
    {
        printf("Error!");
        exit(1);
    }

    int option;

    printf("\n\n\n        STUDENTS MENU\n");
    printf("==============================\n");
    printf("[1] Add a new Student\n");
    printf("[2] List all Students\n");
    printf("[3] Search for a Student\n");
    printf("[4] Edit a Student information\n");
    printf("[5] Delete a Student\n");
    printf("[0] Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        insertStudent(st);
        break;
    case 2:
        displayStudent(st);
        break;
    case 3:
        searchStudent(st);
        break;
    case 4:
        editStudent(st);
        break;
    case 5:
        delStudent(st);
        break;
    case 0:
        break;
    default:
        break;
    }

    fclose(st);
}

void SubjectsMenu(){

    FILE * su;
    su = (fopen("subjects.txt","w+"));
    if(su == NULL)
    {
        printf("Error!");
        exit(1);
    }
    
    int option;

    printf("\n\n\n        SUBJECTS MENU\n");
    printf("==============================\n");
    printf("[1] Add a new Subject\n");
    printf("[2] List all Subject\n");
    printf("[3] Search for a Subject\n");
    printf("[4] Edit a Subject information\n");
    printf("[5] Delete a Subject\n");
    printf("[0] Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        insertSubject(su);
        break;
    case 2:
        displaySubject;
        break;
    case 3:
        searchSubject;
        break;
    case 4:
        editSubject;
        break;
    case 5:
        delSubject;
        break;
    default:
        break;
    }

    fclose(su);
}

void insertStudent(FILE * st){

    //number of students to add
    int n;
    printf("Number of Students to add: ");
    scanf("%d", &n);

    // storing information
    for (int i = 0; i < n; ++i){
        printf("Enter students number: ");
        scanf("%d", &stu.number);
        printf("Enter first name: ");
        scanf("%s", &stu.firstName);
        printf("Enter last name: ");
        scanf("%s", &stu.lastName);
        fprintf(st, "\nNumber: %d \nName: %s %s \n", stu.number, stu.firstName, stu.lastName);
        printf("\n");
    }
}

void insertSubject(FILE * su){

    //number of subjects to add
    int n;
    printf("Number of Subjects to add: ");
    scanf("%d", &n);

    //storing information
    for (int i = 0; i < n; i++){
        printf("Enter subjects name: ");
        scanf("%s", &sub.name);
        printf("Enter subjects year: ");
        scanf("%d", &sub.year);
        printf("Enter subjects semester: ");
        scanf("%d", &sub.semester);
        fprintf(su, "\nAno: %d \nSemestre: %d \nNome: %s \n", sub.year, sub.semester, sub.name);
        printf("\n");
    }

}

void displayStudent(FILE * st){

    char ch;

    do{
        //lê um caracter do ficheiro
        ch = fgetc(st);

        //faz print do caracter no terminal
        putchar(ch);

    }while(ch != EOF); //repete se o caracter não é o fim do ficheiro

}

void displaySubject(FILE * su){

    char ch;

    do{
        //lê um caracter do ficheiro
        ch = fgetc(su);

        //faz print do caracter no terminal
        putchar(ch);

    }while(ch != EOF); //repete se o caracter não é o fim do ficheiro

}