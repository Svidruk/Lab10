#include "Students.h"

struct Slist* ReadStudents(FILE* pfInputFile) 
{
	struct Slist* pFirstStudent = malloc(sizeof(struct Slist));
	if (fscanf(pfInputFile, "%s %s %d %d %d", pFirstStudent->sSurname, pFirstStudent->sName,
		&(pFirstStudent->Birthday.nDay), &(pFirstStudent->Birthday.nMonth),
		&(pFirstStudent->Birthday.nYear)) < 0)
		return NULL;

	double dbAvg = 0;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) 
	{
		fscanf(pfInputFile, "%d", &(pFirstStudent->nMarks[i]));
		dbAvg += (pFirstStudent->nMarks[i]);
	}
	dbAvg /= NUMBER_OF_STUDENTS;
	pFirstStudent->dbMidMark = dbAvg;
	pFirstStudent->Next = NULL;

	struct Slist* pNewElement;

	while (!feof(pfInputFile)) 
	{
		pNewElement = malloc(sizeof(struct Slist));
		if (fscanf(pfInputFile, "%s %s %d %d %d", pNewElement->sSurname, pNewElement->sName,
			&(pNewElement->Birthday.nDay), &(pNewElement->Birthday.nMonth),
			&(pNewElement->Birthday.nYear)) > 0)
		{
			double dbAverage = 0;
			for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
			{
				fscanf(pfInputFile, "%d", &(pNewElement->nMarks[i]));
				dbAverage += (pNewElement->nMarks[i]);
			}
			dbAverage /= NUMBER_OF_STUDENTS;
			pNewElement->dbMidMark = dbAverage;

			AddStudent(&pFirstStudent, pNewElement);
		}
		else 
		{
			free(pNewElement);
		}
	}
	return pFirstStudent;
}

int CheckStudentsMarks(struct Slist* pStudent) {
	int k = 0;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		if (pStudent->nMarks[i] == 2) {
			k++;
		}
		if (k == 2)
			return 1;
	}
	return 0;
}

void PrintStudent(FILE* pfOutputFile, struct Slist* SP) {

	fprintf(pfOutputFile, "\t %10s| %10s| %5d| %5d| %5d|", SP->sSurname, SP->sName,
		(SP->Birthday.nDay), (SP->Birthday.nMonth),
		(SP->Birthday.nYear));

	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		fprintf(pfOutputFile, " %4d ", (SP->nMarks[i]));
	}
	fprintf(pfOutputFile, " |%5.2lf|\n", SP->dbMidMark);
}

void PrintStudents(FILE* pfOutputFile, struct Slist* pStudent) {
	if (pStudent)
		do {
			PrintStudent(pfOutputFile, pStudent);
		} while (pStudent = pStudent->Next);
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

void DeleteNextStudent(struct Slist* pList)
{
	struct Slist* pTemp = pList->Next;
	pList->Next = pTemp->Next;
	free(pTemp);
}

void DeleteFirstStudent(struct Slist** pFirstStudent) {
	struct Slist* pSecond = (*pFirstStudent)->Next;
	free(*pFirstStudent);
	*pFirstStudent = pSecond;
}

void DeleteStudents(struct Slist** pStudent) 
{
	do {
		DeleteFirstStudent(pStudent);
	} while (*pStudent);
}