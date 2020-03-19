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

void AddStudent(struct Slist** pStudent, struct Slist* pElement); 

void DeleteNextStudent(struct Slist* pStudent);            

void DeleteFirstStudent(struct Slist** pFirstStudent);

void DeleteStudents(struct Slist** pStudent);

int CheckStudentsMarks(struct Slist* pStudent);

struct Slist* ReadStudents(FILE* pfInputFile);

void PrintStudent(FILE* pfOutputFile, struct Slist* SP);

void PrintStudents(FILE* pfOutputFile, struct Slist* pStudent);


#endif 
