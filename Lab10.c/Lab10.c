#include "students.h"
#include <conio.h>

int main() 
{
	struct Slist* pStudents;
	FILE* pfInputFile = fopen("InputData.txt", "r");
	FILE* pfOutputFile = fopen("OutputData.txt", "w");
	pStudents = ReadStudents(pfInputFile);
	OutputStudentsInFile(pfOutputFile, pStudents);
 
	struct Slist* pFirstStudent = pStudents;

	if (CheckStudentsMarks(pStudents))
	{
		DeleteFirstStudent(&pStudents);
	}
	pFirstStudent = pStudents;
	do {
		while (pFirstStudent->pNext && CheckStudentsMarks(pFirstStudent->pNext))DeleteNextStudent(pFirstStudent);
	} while ((pFirstStudent = pFirstStudent->pNext) && pFirstStudent->pNext);

	fprintf(pfOutputFile, "\nstudents after deleting and sorting\n");
	OutputStudentsInFile(pfOutputFile, pStudents);

	DeleteStudents(&pStudents);

	fclose(pfInputFile);
	fclose(pfOutputFile);
	return 0;
}
