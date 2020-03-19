#include "students.h"
#include <conio.h>

int main() 
{
	struct Slist* pStudents;
	FILE* pfInputFile = fopen("InputData.txt", "r");
	FILE* pfOutputFile = fopen("OutputData.txt", "w");
	pStudents = ReadStudents(pfInputFile);
	PrintStudents(pfOutputFile, pStudents);
 
	struct Slist* pFirstStudent = pStudents;

	while (CheckStudentsMarks(pStudents))DeleteFstStudent(&pStudents);
	pFirstStudent = pStudents;
	do {
		while (pFirstStudent->Next && CheckStudentsMarks(pFirstStudent->Next))DeleteNextStudent(pFirstStudent);
	} while ((pFirstStudent = pFirstStudent->Next) && pFirstStudent->Next);

	fprintf(pfOutputFile, "\nstudents after deleting and sorting\n");
	PrintStudents(pfOutputFile, pStudents);

	DeleteStudents(&pStudents);

	fclose(pfInputFile);
	fclose(pfOutputFile);
	return 0;
}
