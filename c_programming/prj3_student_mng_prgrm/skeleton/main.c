#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef enum SubjectNames		// �� ���� ���� ������ ���Ǻ�
{ 
	MATH,						// MATH = 0
	PHYSICS,					// PHYSICS = 1
	PROGRAMMING,				// PROGRAMMING = 2
	NUMBER_OF_SUBJECT			// NUMBER_OF_SUBJECT = 3
} SUBJECT_NAME;

typedef struct Student
{
	char studentName[15];					// �л� ����(���ڿ�)
	int studentNumber;						// �л� �й�(������)
	int scoreSubjects[NUMBER_OF_SUBJECT];	// �л� �� ���� ����(������ �迭, ���̴� 3)
	int scoreTotal;							// �� ������ ����(������)
	double scoreAverage;					// �� ������ ���(�Ǽ���)
} StudentInfomation;

#define MAX_USERS 10

int countUsers = 0;				// ���� ����� �������� ���� Ȯ���� �� �ִ� ����

void flushInputBuffer(void);	// �Է� ���ۿ� �����ִ� ���๮�ڸ� ����ִ� �Լ�

void printMenu(void);			// �޴�ȭ�� ��� �Լ�

void userInformationPrint(StudentInfomation* ptrarray);	// ���� �޸𸮿� ����Ǿ� �ִ� �����͸� ����ϴ� �Լ�

int userInformationCreate(StudentInfomation* ptrarray, char* const ptrname, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);	// �Է� ������ �߰��ϴ� �Լ�

int userInformationUpdate(StudentInfomation* ptrarray, int seletedno, char* name, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);	// ������ ������ �����ϴ� �Լ�

int userInformationDelete(StudentInfomation* ptrarray, int seletedno);	// ����Ǿ� �ִ� ������ �� ���õ� �����͸� �����ϴ� �Լ�

int main(void)
{
	// �л� ���� ������ ���� ����ü �迭 ���� �� �Է¿� �ʿ��� ���� ����
	StudentInfomation arrayStudent[MAX_USERS];

	int inputMenuNumber;
	char inputName[15];
	int inputStudentNumber;
	int inputScoreMath;
	int inputScorePhysics;
	int inputScoreProgramming;
	int inputChooseNumber;


	return 0;

}

