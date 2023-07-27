#include <stdio.h>
#include <stdlib.h>

#define NUM_COURSES 10
#define NUM_CLASSES 10
#define NUM_LEVELS 7
#define NUM_LEN 15
#define CELL_LEN 11
#define STUDENTS_FILE "students.txt"


//------------ structs ------------//
typedef struct {
    struct Student* DB[NUM_LEVELS][NUM_CLASSES];
} School;

typedef struct {
    char fname[NUM_LEN];
    char lname[NUM_LEN];
    char cellphone[CELL_LEN];
    int courses_grades[NUM_COURSES];
    int level, class; // for now, not sure if it will stay
    struct Student* next;
} Student;

//typedef struct { for now, not sure if it will stay
//    int name;
//    int grade;
//} Course;

//------------ global variables ------------//
static School school;

//------------ memory functions ------------//
void freeSchool(){
    int i, j;
    for (i = 0; i < NUM_LEVELS; i++) {
        for (j = 0; j < NUM_CLASSES; j++) {
            Student* curr = school.DB[i][j];
            while (curr != NULL) {
                Student* next = curr->next;
                free(curr);
                curr = next;
            }
        }
    }
}

void programFailed(char* msg){
    perror(msg);
    freeSchool();
    exit(-1);
}

Student* allocateStudent(){
    Student* stud = malloc(sizeof(Student));
    if(stud == NULL) {
        programFailed("Error allocating memory for student\n");
    }
    return stud;
}

FILE* fileopen(const char* filename){

    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        perror("Can not open input file\n");
        exit(-1);
    }
    return fp;
}

void clearStdin(){
    while ((getchar()) != '\n'); // clear stdin
}

//------------ DB functions ------------//
void parseStudentFromFileLine(char* line){
    int offset = 0;

    Student* stud = allocateStudent();
    int scannedItemsNum = sscanf(line, "%s %s %s %d %d%n", stud->fname, stud->lname, stud->cellphone, &stud->level, &stud->class, &offset);
    if(scannedItemsNum != 5){
        programFailed("Error reading student info\n");
    }

    for(int i = 0, n = 0; i < NUM_COURSES; i++){
        scannedItemsNum = sscanf(line + offset, "%d%n", &stud->courses_grades[i], &n);
        if(scannedItemsNum != 1) {
            programFailed("Error reading grade for course %d\n");
        }
        offset += n;
    }

    //enter student to DB as first in list class
    //TODO: implement sorting insertion  by names
    stud->next = school.DB[stud->level][stud->class];
    school.DB[stud->level][stud->class] = stud;
}

void initDB(){
    FILE* fp = fileopen(STUDENTS_FILE);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        parseStudentFromFileLine(line);
    }

    free(line);
    fclose(fp);
}

void printDB(){
    for(int i = 0; i < NUM_LEVELS; i++){
        for(int j = 0; j < NUM_CLASSES; j++){
            printf("Level %d, Class %d:\n", i, j);
            Student* curr = school.DB[i][j];
            while(curr != NULL){
                printf("%s %s %s ", curr->fname, curr->lname, curr->cellphone);
                for(int k = 0; k < NUM_COURSES; k++){
                    printf("%d ", curr->courses_grades[k]);
                }
                printf("\n");
                curr = curr->next;
            }
        }
    }
}

//------------ menu functions ------------//
void printMenu(){
    printf("Choose task:\n");
    printf("1. Add student\n");
    printf("2. Remove student\n");
    printf("3. Update student\n");
    printf("4. Search student by name\n");
    printf("5. Search excellent students\n");
    printf("6. Search unstable students\n");
    printf("7. Calculate level average\n");
    printf("8. Print DB\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

void addStudent(){
    printf("Enter student info:\n First name, Last name, Cellphone, Level, Class, Grades of the classes courses\n");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if((read = getline(&line, &len, stdin)) == -1){
        programFailed("Error reading student info\n");
    }
    parseStudentFromFileLine(line);
}

void executeTask(const int task){

    switch(task){
        case 1:
            addStudent();
            break;
        case 2:
            printf("Remove student\n");
            break;
        case 3:
            printf("Update student\n");
            break;
        case 4:
            printf("Search student by name\n");
            break;
        case 5:
            printf("Search excellent students\n");
            break;
        case 6:
            printf("Search unstable students\n");
            break;
        case 7:
            printf("Calculate level average\n");
            break;
        case 8:
            printDB();
            break;
        case 0:
            printf("Exit\n");
            break;
        default:
            printf("Invalid task\n");
            break;
    }

}

void menu(){
    int task, inpStatus;

    do{
        printMenu();
        inpStatus = scanf("%d", &task);
        clearStdin();
        if(inpStatus != 1){
            printf("Invalid input\n");
            continue;
        }
        executeTask(task);
    }while(task != 0);
}


int main(){

    initDB();
  //  printDB();
    menu();
    freeSchool();

    return 0;
}
