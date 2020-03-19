#ifndef _STRUCT_STUDENTS
#define _STRUCT_STUDENTS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 50
#define NUMBER_OF_STUDENTS 5

struct SStudentBirthday {
	int nDay, nMonth, nYear;
};

struct Slist {
	char szSurname[SIZE], szName[SIZE];
	struct SStudentBirthday Birthday;
	int nMarks[NUMBER_OF_STUDENTS];
	double dbAvgMark;
	struct Slist* pNext;
};
//Функція що додає елемент у список
void AddStudent(struct Slist** pStudent, struct Slist* pElement); 

//функція видалення елемента зі списку
void DeleteNextStudent(struct Slist* pStudent);            

//функція видалення першого елемента списку і зміни його на наступний
void DeleteFirstStudent(struct Slist** pFirstStudent);

//функція видалення списку з памяті
void DeleteStudents(struct Slist** pStudent);

//провірка середнього балу для подальшого сортування 
int CheckStudentsMarks(struct Slist* pStudent);

//Функція що зчитує дані про студентів з файлу
struct Slist* ReadStudents(FILE* pfInputFile);

//Виводить інформацію про студента у файл
void PrintStudent(FILE* pfOutputFile, struct Slist* SP);

//Виводить інформацію про кожного студента у списку у файл
void OutputStudentsInFile(FILE* pfOutputFile, struct Slist* pStudent);


#endif 
