#include "Students.h"

struct Slist* ReadStudents(FILE* Inp) 
{
	struct Slist* FirstStudent = malloc(sizeof(struct Slist));
	if (fscanf(Inp, "%s %s %d %d %d", FirstStudent->sSurname, FirstStudent->sName,
		&(FirstStudent->Birthday.nDay), &(FirstStudent->Birthday.nMonth),
		&(FirstStudent->Birthday.nYear)) < 0)
		return NULL;

	double dbAverage = 0;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) 
	{
		fscanf(Inp, "%d", &(FirstStudent->nMarks[i]));
		dbAverage += (FirstStudent->nMarks[i]);
	}
	dbAverage /= NUMBER_OF_STUDENTS;
	FirstStudent->dbMidMark = dbAverage;
	FirstStudent->Next = NULL;

	struct Slist* NewElement;

	while (!feof(Inp)) 
	{
		NewElement = malloc(sizeof(struct Slist));
		if (fscanf(Inp, "%s %s %d %d %d", NewElement->sSurname, NewElement->sName,
			&(NewElement->Birthday.nDay), &(NewElement->Birthday.nMonth),
			&(NewElement->Birthday.nYear)) > 0)
		{
			double dbAverage = 0;
			for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
			{
				fscanf(Inp, "%d", &(NewElement->nMarks[i]));
				dbAverage += (NewElement->nMarks[i]);
			}
			dbAverage /= NUMBER_OF_STUDENTS;
			NewElement->dbMidMark = dbAverage;

			AddStudent(&FirstStudent, NewElement);
		}
		else 
		{
			free(NewElement);
		}
	}
	return FirstStudent;
}

int CheckStudentsMarks(struct Slist* student) {
	int k = 0;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		if (student->nMarks[i] == 2) {
			k++;
		}
		if (k == 2)
			return 1;
	}
	return 0;
}

void PrintStudent(FILE* Out, struct Slist* SP) {

	fprintf(Out, "\t %10s| %10s| %5d| %5d| %5d|", SP->sSurname, SP->sName,
		(SP->Birthday.nDay), (SP->Birthday.nMonth),
		(SP->Birthday.nYear));

	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		fprintf(Out, " %4d ", (SP->nMarks[i]));
	}
	fprintf(Out, " |%5.2lf|\n", SP->dbMidMark);
}

void PrintStudents(FILE* Out, struct Slist* student) {
	if (student)
		do {
			PrintStudent(Out, student);
		} while (student = student->Next);
}

void AddStudent(struct Slist** pStudent, struct Slist* pElement) {

	struct Slist* student = (*pStudent);
	if (student->dbMidMark > pElement->dbMidMark) {
		pElement->Next = student;
		(*pStudent) = pElement;
		return;
	}

	while (student->Next && (student->Next->dbMidMark>pElement->dbMidMark < 0)) {
		student = student->Next;
	}

	pElement->Next = student->Next;
	student->Next = pElement;
}

void DeleteNextStudent(struct Slist* list)
{
	struct Slist* pTemp = list->Next;
	list->Next = pTemp->Next;
	free(pTemp);
}

void DeleteFirstStudent(struct Slist** pFirstStudent) {
	struct Slist* pSecond = (*pFirstStudent)->Next;
	free(*pFirstStudent);
	*pFirstStudent = pSecond;
}

void DeleteStudents(struct Slist** student) 
{
	do {
		DeleteFirstStudent(student);
	} while (*student);
}