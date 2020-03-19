#ifndef _STRUCT_STUDENTS
#define _STRUCT_STUDENTS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 50
#define NUMBER_OF_STUDENTS 5

struct Sbd {
	int nDay, nMonth, nYear;
};

struct Slist {
	char sSurname[SIZE], sName[SIZE];
	struct Sbd Birthday;
	int nMarks[NUMBER_OF_STUDENTS];
	double dbMidMark;
	struct Slist* Next;
};

void AddStudent(struct Slist** pstudent, struct Slist* Element); 

void DeleteNextStudent(struct Slist* student);            

void DeleteFirstStudent(struct Slist** FstStudent);

void DeleteStudents(struct Slist** student);

int CheckStudentsMarks(struct Slist* student);

struct Slist* ReadStudents(FILE* Inp);

void PrintStudent(FILE* Out, struct Slist* SP);

void PrintStudents(FILE* Out, struct Slist* student);


#endif 
