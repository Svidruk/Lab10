#include "students.h"
#include <conio.h>

int main() 
{
	struct Slist* pStudents;
	FILE* pfInputFile = fopen("InputData.txt", "r");
	FILE* pfOutputFile = fopen("OutputData.txt", "w");
	pStudents = ReadStudents(pfInputFile);
	PrintStudents(pfOutputFile, pStudents);
 
	struct Slist* FirstStudent = pStudents;

	while (CheckStudentsMarks(pStudents))DeleteFstStudent(&pStudents);
	FirstStudent = pStudents;
	do {
		while (FirstStudent->Next && CheckStudentsMarks(FirstStudent->Next))DeleteNextStudent(FirstStudent);
	} while ((FirstStudent = FirstStudent->Next) && FirstStudent->Next);

	fprintf(pfOutputFile, "\nstudents after deleting and sorting\n");
	PrintStudents(pfOutputFile, pStudents);

	DeleteStudents(&pStudents);

	fclose(pfInputFile);
	fclose(pfOutputFile);
	return 0;
}
