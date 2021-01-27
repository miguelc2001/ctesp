/**
 * @file projeto.c
 * @author Miguel Correia
 * @brief 
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Student struct Stud
#define Subject struct Sub

//estrutura dos estudantes
struct Stud {
    char firstName[20];
    char lastName[20];
    char number[10];
};

//estrutura das disciplinas
struct Sub {
    char name[50];
    int year;
    int semester;
};

//funções
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
FILE * delStudent(FILE * st);
FILE * delSubject(FILE * su);

int main()
{
    MainMenu();

    return 0;
}

void MainMenu()
{
    int option;
    int i = 1;

    //imprime o menu e dá a escolher entre o menu de estudantes ou disciplinas
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

void StudentsMenu()
{
    FILE * st;

    int option;
    int i = 1;

    //imprime o menu e dá a escolher as diversas opções para funções
    while(i == 1)
    {
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
            i++;
            break;
        default:
            break;
        }
    }
    fclose(st);
}

void SubjectsMenu()
{
    FILE * su;
    
    int option;
    int i = 1;

    //imprime o menu e dá a escolher as diversas opções para funções
    while(i == 1)
    {
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
            displaySubject(su);
            break;
        case 3:
            searchSubject(su);
            break;
        case 4:
            editSubject(su);
            break;
        case 5:
            delSubject(su);
            break;
        case 0:
            i++;
            break;
        default:
            break;
        }
    }
    fclose(su);
}

//função para adicionar estudantes
void insertStudent(FILE * st)
{
    Student stu;

    //abre o ficheiro em modo de escrita
    st = (fopen("students.txt","w"));
    if(st == NULL)
    {
        //imprime um erro caso não encontre o ficheiro e sai do programa
        printf("Error!\n\n");
        exit(1);
    }

    //pergunta quantos estudantes o utilizador quer adicionar
    int n;
    printf("Number of Students to add: ");
    scanf("%d", &n);

    //guarda a informação introduzida pelo utilizador
    for (int i = 0; i < n; ++i){
        printf("Enter students number: ");
        scanf("%s", &stu.number);
        printf("Enter first name: ");
        scanf("%s", &stu.firstName);
        printf("Enter last name: ");
        scanf("%s", &stu.lastName);
        fprintf(st, "\n%s, %s %s\n", stu.number, stu.firstName, stu.lastName);
        printf("\n");
    }

    //fecha o ficheiro
    fclose(st);
}

//função para adicionar disciplinas
void insertSubject(FILE * su)
{
    Subject sub;

    //abre o ficheiro em mode de escrita
    su = (fopen("subjects.txt","w"));
    if(su == NULL)
    {
        //imprime um erro caso não encontre o ficheiro e sai do programa
        printf("Error!\n\n");
        exit(1);
    }

    //pergunta quantas disciplinas o utilizador quer adicionar
    int n;
    printf("Number of Subjects to add: ");
    scanf("%d", &n);

    //guarda a informação introduzida pelo utilizador
    for (int i = 0; i < n; i++){
        printf("Enter subjects name: ");
        scanf("%s", &sub.name);
        printf("Enter subjects year: ");
        scanf("%d", &sub.year);
        printf("Enter subjects semester: ");
        scanf("%d", &sub.semester);
        fprintf(su, "\nAno %d, Semestre %d, %s\n", sub.year, sub.semester, sub.name);
        printf("\n");
    }

    //fecha o ficheiro
    fclose(su);
}

//função para listar todos os estudantes
void displayStudent(FILE * st)
{
    //abre o ficheiro em modo de leitura
    st = (fopen("students.txt","r"));
    if(st == NULL)
    {
        //imprime um erro caso não encontre o ficheiro e sai do programa
        printf("Error!\n\n");
        exit(1);
    }

    char ch;

    do{
        //lê um caracter do ficheiro
        ch = fgetc(st);

        //faz print do caracter no terminal
        printf("%c", ch);

    }while(ch != EOF); //repete até chegar ao fim do ficheiro

    //fecha o ficheiro
    fclose(st);
}

//função para listar todas as disciplinas
void displaySubject(FILE * su)
{
    //abre o ficheiro em modo de leitura
    su = (fopen("subjects.txt","r"));
    if(su == NULL)
    {
        //imprime um erro caso não encontre o ficheiro e sai do programa
        printf("Error!\n\n");
        exit(1);
    }

    char ch;

    do{
        //lê um caracter do ficheiro
        ch = fgetc(su);

        //faz print do caracter no terminal
        printf("%c", ch);

    }while(ch != EOF); //repete até chegar ao fim do ficheiro

    //fecha o ficheiro
    fclose(su);
}

//função para procurar estudantes
void searchStudent(FILE * st)
{
    //abre o ficheiro em modo de leitura
    st = (fopen("students.txt","r"));
    if(st == NULL)
    {
        //imprime um erro caso não encontre o ficheiro e sai do programa
        printf("Error!\n\n");
        exit(1);
    }

    char line[50];
    char p[20];

    //pede ao utilizador para inserir um parametro de busca (numero, primeiro ou ultimo nome)
    printf("Enter search parameter: ");
    scanf("%s", &p);
    printf("\nResults found:\n");
    
    //lê uma linha do ficheiro caso não seja nula e guarda informação
    while (fgets(line, sizeof(line), st) != NULL)
    {
        //imprime a string procurada caso encontre o parametro de busca nessa string
        if (strstr(line , p) != NULL)
        {
            printf("%s",line);
        }
    }

    //fecha o ficheiro
    fclose(st);
}

void searchSubject(FILE * su)
{
    //abre o ficheiro em modo de leitura
    su = (fopen("subjects.txt","r"));
    if(su == NULL)
    {
        printf("Error!\n\n");
        exit(1);
    }

    char line[50];
    char p[20];
    
    //pede ao utilizador para inserir um parametro de busca (numero, primeiro ou ultimo nome)
    printf("Enter search parameter: ");
    scanf("%s", &p);
    printf("\nResults found:\n");
    
    //lê uma linha do ficheiro caso não seja nula e guarda informação
    while(fgets(line, sizeof(line), su) != NULL)
    {
        //imprime a string procurada caso encontre o parametro de busca nessa string
        if (strstr(line, p) != NULL)
        {
            printf("%s",line);
        }
    }
    
    //fecha o ficheiro
    fclose(su);
}

void editStudent(FILE * st)
{

}

void editSubject(FILE * su)
{

}

FILE * delStudent(FILE * st)
{
    
}

FILE * delSubject(FILE * st)
{
    
}