#define _CRT_SECURE_NO_WARNINGS
#define MAX_USERS 10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum SubjectNames // �� ���� ���� ������ ���Ǻ�
{
	MATH,			  // MATH = 0
	PHYSICS,		  // PHYSICS = 1
	PROGRAMMING,	  // PROGRAMMING = 2
	NUMBER_OF_SUBJECT // NUMBER_OF_SUBJECT = 3
} SUBJECT_NAME;

typedef struct Student
{
	char studentName[15];				  // �л� ����(���ڿ�)
	int studentNumber;					  // �л� �й�(������)
	int scoreSubjects[NUMBER_OF_SUBJECT]; // �л� �� ���� ����(������ �迭, ���̴� 3)
	int scoreTotal;						  // �� ������ ����(������)
	double scoreAverage;				  // �� ������ ���(�Ǽ���)
} StudentInfomation;

int countUsers = 0; // ���� ����� �������� ���� Ȯ���� �� �ִ� ����

void flushInputBuffer(void);																																 // �Է� ���ۿ� �����ִ� ���๮�ڸ� ����ִ� �Լ�
void printMenu(void);																																		 // �޴�ȭ�� ��� �Լ�
void userInformationPrint(StudentInfomation *ptrarray);																										 // ���� �޸𸮿� ����Ǿ� �ִ� �����͸� ����ϴ� �Լ�
int userInformationCreate(StudentInfomation *ptrarray, char *const ptrname, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);		 // �Է� ������ �߰��ϴ� �Լ�
int userInformationUpdate(StudentInfomation *ptrarray, int seletedno, char *name, int studentnumber, int scoremath, int scorephysics, int scoreprogramming); // ������ ������ �����ϴ� �Լ�
int userInformationDelete(StudentInfomation *ptrarray, int seletedno);																						 // ����Ǿ� �ִ� ������ �� ���õ� �����͸� �����ϴ� �Լ�

int main(void)
{
	StudentInfomation arrayStudent[MAX_USERS];
	int inputMenuNumber;
	char inputName[15];
	int inputStudentNumber;
	int inputScoreMath;
	int inputScorePhysics;
	int inputScoreProgramming;
	int inputChooseNumber;
	// �л� ���� ������ ���� ����ü �迭 ���� �� �Է¿� �ʿ��� ���� ����

	printf("�ȳ�: �ִ� �Է°��� �л� �� : %d\n", MAX_USERS);

	FILE *fp = fopen("./StudentData.txt", "rt");

	if (fp == NULL)
	{
		printf("\n\n���� ���⿡ ���� �Ͽ����ϴ�.\n\n");
		return -1;
	}
	else
		printf("�ȳ� : StudentData.txt ������ �о���µ� ���� �Ͽ����ϴ�.\n");

	while (1)
	{
		int a = fscanf(fp, "%s %d %d %d %d", inputName, &inputStudentNumber,
					   &inputScoreMath, &inputScorePhysics, &inputScoreProgramming);

		if (feof(fp) && a == EOF)
			break;

		userInformationCreate(arrayStudent, inputName, inputStudentNumber,
							  inputScoreMath, inputScorePhysics, inputScoreProgramming);

		printf("\n�ȳ�: ��û�Ͻ� ������ �߰��Ͽ����ϴ�.\n");
	}
	fclose(fp);
	// ������ �б� ���ο����Ͽ� ���Ͽ� ����Ǿ��ִ� �л� ���������͸� ����ü �迭�� �������� ������ �ݴ´�.
	while (1)
	{
		while (1)
		{
			printMenu();				   // �޴����
			scanf("%d", &inputMenuNumber); // �޴����� �Է¹���

			if (inputMenuNumber < 6 && inputMenuNumber > 0) // 1~5���� ���� ���� Ż��
				break;
			else
				printf("�ȳ� : ��ȿ���� �ʴ� �޴��Դϴ�. �ٽ� �Է��ϼ���\n");
			flushInputBuffer(); // ���� ���� ���ڸ� �Է¹޾����� �Է¹��۸� �����
		}

		if (inputMenuNumber == 1)
		{
			flushInputBuffer();
			printf("\n�ȳ�: �л� ���� �Է��� �����Ͽ����ϴ�.\n\n");
			printf("����: ");
			scanf("%s", inputName);
			printf("�й�: ");
			scanf("%d", &inputStudentNumber);
			printf("���м��� ����:");
			scanf("%d", &inputScoreMath);
			printf("���� ����: ");
			scanf("%d", &inputScorePhysics);
			printf("���α׷��� ����: ");
			scanf("%d", &inputScoreProgramming);
			// ����ڷκ��� �̸�, �й�, �������� �Է¹޾� �ӽ� ������ �����Ѵ�.

			if (userInformationCreate(arrayStudent, inputName, inputStudentNumber,
									  inputScoreMath, inputScorePhysics, inputScoreProgramming) == 0)
				printf("\n�ȳ�: �л� ���� �Է¿� �����Ͽ����ϴ�.\n");
			else
				printf("\n�ȳ�: �л� ���� �Է¿� �����Ͽ����ϴ�.\n");
			// ���� ���� ���� ���� ���� ���θ� ����Ѵ�.
		}
		else if (inputMenuNumber == 2)
		{
			printf("�ȳ�: �л� ���� ����� �����Ͽ����ϴ�.\n\n");
			userInformationPrint(arrayStudent);
			// �л� ������ ����ϴ� �Լ��� �����Ѵ�.
		}
		else if (inputMenuNumber == 3)
		{
			printf("\n�ȳ�: �л� ���� ������ �����Ͽ����ϴ�.\n");
			flushInputBuffer();
			userInformationPrint(arrayStudent); // ���� ����� �л����� ���
			printf("\n������ ���ϴ� �л��� No: ");
			scanf("%d", &inputChooseNumber);
			printf("����: ");
			scanf("%s", inputName);
			printf("�й�: ");
			scanf("%d", &inputStudentNumber);
			printf("���м��� ����:");
			scanf("%d", &inputScoreMath);
			printf("���� ����: ");
			scanf("%d", &inputScorePhysics);
			printf("���α׷��� ����: ");
			scanf("%d", &inputScoreProgramming);
			// ����ڷκ��� ������ �л��� ����, �̸�, �й�, �������� �Է¹޾� �ӽ� ������ �����Ѵ�.
			if (userInformationUpdate(arrayStudent, inputChooseNumber, inputName, inputStudentNumber,
									  inputScoreMath, inputScorePhysics, inputScoreProgramming) == 0)
				printf("\n�ȳ�: ������ �����Ͽ����ϴ�.\n");
			else
				printf("�ȳ�: ������ �����Ͽ����ϴ�.\n");
			// �Լ� ���� �� ���� ���� ���� ���� ���� ���θ� ����Ѵ�.
		}
		else if (inputMenuNumber == 4)
		{
			printf("\n�ȳ�: �л� ���� ������ �����Ͽ����ϴ�.\n\n");
			userInformationPrint(arrayStudent);
			// ���� ����� �л� ���� ���
			printf("\n������ ���ϴ� �л��� No: ");
			scanf("%d", &inputChooseNumber);

			if (userInformationDelete(arrayStudent, inputChooseNumber) == 0)
				printf("\n�ȳ�: ������ �����Ͽ����ϴ�.\n");
			else
				printf("�ȳ�: ������ �����Ͽ����ϴ�.\n");
			// �Լ� ���� �� ���ϰ��� ���� ���� ���� ���θ� ����Ѵ�.
		}
		else
		{
			printf("\n�ȳ�: ���� �� ���α׷��� �����մϴ�.\n");
			break;
		}
	}
	printf("\n�ȳ�: ���� ������ StudentData.txt ���Ͽ� �����մϴ�.\n");

	fp = fopen("./StudentData.txt", "wt");

	if (fp == NULL)
	{
		printf("\n\n���� ���⿡ ���� �Ͽ����ϴ�.\n\n");
		return -1;
	}

	for (int i = 0; i < countUsers; i++)
		fprintf(fp, "%s %d %d %d %d\n", arrayStudent[i].studentName, arrayStudent[i].studentNumber,
				arrayStudent[i].scoreSubjects[MATH], arrayStudent[i].scoreSubjects[PHYSICS],
				arrayStudent[i].scoreSubjects[PROGRAMMING]);

	fclose(fp);

	printf("\nStudentData.txt ������ �����Ͽ����ϴ�.\n");
	printf("\n�ȳ�: ���α׷��� �����մϴ�.\n");
	// ������ ������� ���� �� ����ü �迭�� ����� �������� ���Ͽ� ������� ������ �ݴ´�.
	return 0;
}

void flushInputBuffer(void) // �Է� ���ۿ� �����ִ� ���๮�ڸ� ����ִ� �Լ�
{
	while (getchar() != '\n')
	{
	}
}

void printMenu(void) // �޴�ȭ�� ��� �Լ�
{
	printf("\n============================================\n");
	printf("		�л� ���� �ý���\n");
	printf("============================================\n");
	printf("	1. �л� ���� �Է�\n");
	printf("	2. �л� ���� ���\n");
	printf("	3. �л� ���� ����\n");
	printf("	4. �л� ���� ����\n");
	printf("	5. �����ϰ� ���α׷� ����\n");
	printf("============================================\n");
	printf("�޴� ���� : ");
}

void userInformationPrint(StudentInfomation *ptrarray) // ���� �޸𸮿� ����Ǿ� �ִ� �����͸� ����ϴ� �Լ�
{
	int i = 0;

	printf("\n===========================================================================================================\n");
	printf("No.	��  ��		  �й�		���м���	����	���α׷���	:	����	  ���\n");
	printf("============================================================================================================\n");

	for (i = 0; i < countUsers; i++)
		printf("%d	%s		%d	   %d		%d	    %d			  %d	%0.2f\n", i + 1, ptrarray[i].studentName,
			   ptrarray[i].studentNumber, ptrarray[i].scoreSubjects[MATH], ptrarray[i].scoreSubjects[PHYSICS],
			   ptrarray[i].scoreSubjects[PROGRAMMING], ptrarray[i].scoreTotal, ptrarray[i].scoreAverage);

	printf("============================================================================================================\n");
	printf("\n�ȳ�: ����� �Ϸ� �Ǿ����ϴ�.\n");
	// ���� �Էµ� �л� �� ���� ����� �迭�� ���� ����Ѵ�
}

int userInformationCreate(StudentInfomation *ptrarray, char *const ptrname,
						  int studentnumber, int scoremath, int scorephysics, int scoreprogramming) // �Է� ������ �߰��ϴ� �Լ�
{
	if (countUsers >= MAX_USERS)
	{
		printf("\n�ȳ�: �ִ� �Է� �л� �� %d���� �ʰ��Ͽ����ϴ�.\n", MAX_USERS);

		return 0; // ���� �ִ� �Է� ���� �л� ���� �ʰ��ϸ� 0�� �����ϸ� ����ȴ�.
	}
	else
	{
		// �������ڷ� �Էµ� �����͸� ������ �������Է� �Լ��� ȣ���Ͽ� ������ �� �迭�� �߰�
		strcpy(ptrarray[countUsers].studentName, ptrname);
		ptrarray[countUsers].studentNumber = studentnumber;
		ptrarray[countUsers].scoreSubjects[MATH] = scoremath;
		ptrarray[countUsers].scoreSubjects[PHYSICS] = scorephysics;
		ptrarray[countUsers].scoreSubjects[PROGRAMMING] = scoreprogramming;
		ptrarray[countUsers].scoreTotal = scoremath + scorephysics + scoreprogramming;
		ptrarray[countUsers].scoreAverage = (double)ptrarray[countUsers].scoreTotal / 3;

		countUsers++;

		return 1; // �ӽ� ����� ������ �迭�� �ְ� �Էµ� �л� ���� �Ѹ� ������Ű�� 1�� �����ϸ� �����Ѵ�.
	}
}

int userInformationUpdate(StudentInfomation *ptrarray, int selectedno, char *name,
						  int studentnumber, int scoremath, int scorephysics, int scoreprogramming) // ������ ������ �����ϴ� �Լ�
{
	if (selectedno <= countUsers && selectedno > 0)
	{
		selectedno -= 1; // �迭�� 0���� ��������� ����� 1���� �ϹǷ� 1�� ����

		strcpy(ptrarray[selectedno].studentName, name);
		ptrarray[selectedno].studentNumber = studentnumber;
		ptrarray[selectedno].scoreSubjects[MATH] = scoremath;
		ptrarray[selectedno].scoreSubjects[PHYSICS] = scorephysics;
		ptrarray[selectedno].scoreSubjects[PROGRAMMING] = scoreprogramming;
		ptrarray[selectedno].scoreTotal = scoremath + scorephysics + scoreprogramming;
		ptrarray[selectedno].scoreAverage = (double)ptrarray[selectedno].scoreTotal / 3;

		// ������ ���� �迭�� �������ڷ� ���޹��� �������� �����Ѵ�.
		printf("\n�ȳ�: ������ �Ϸ� �Ǿ����ϴ�. �޴��� ���ư��ϴ�.\n\n");
		// ���� ������ ��ȣ�� ���� �Էµ� �л� �� ���� ����, 0���� ū ���϶� �����Ѵ�
		return 1;
	}
	else if (selectedno <= MAX_USERS && selectedno > countUsers)
	{
		printf("\n�ȳ�: ���� �Է� ���� ���� �����Դϴ�. ���� ��û ������ �л������� �߰��մϴ�..\n");

		userInformationCreate(ptrarray, name, studentnumber, scoremath, scorephysics, scoreprogramming);

		printf("\n�ȳ�: ��û�Ͻ� ������ �߰��Ͽ����ϴ�.\n");
		// ���� ������ ��ȣ�� ���� �Էµ� �л� ������ ����, �ִ� �Է°��� �л��� ���� ���� �� �л������� ������ �߰��Ѵ�
		return 1; // ������ �����ϸ� 1�� �����Ѵ�
	}
	else
	{
		printf("\n�ȳ�: �������� No�Դϴ�.\n");
		// �� ���� ���� �Է��ϸ� ������ ���� �Ѵ�.
		return 0; // ������ �����ϸ� 0�� �����Ѵ�
	}
}

int userInformationDelete(StudentInfomation *ptrarray, int selectedno)
// ����Ǿ� �ִ� ������ �� ���õ� �����͸� �����ϴ� �Լ�
{
	char yesno = 0; // ���� ���θ� �Է� ���� ����

	if (selectedno > 0 && selectedno <= countUsers)
	{
		printf("���� �� ������ �����Ͻðڽ��ϱ�?(Y/N): ");
		flushInputBuffer();
		scanf("%c", &yesno);

		if (yesno == 'Y')
		{
			for (int i = selectedno; i <= countUsers; i++)
			{
				strcpy(ptrarray[i - 1].studentName, ptrarray[i].studentName);
				ptrarray[i - 1].studentNumber = ptrarray[i].studentNumber;
				ptrarray[i - 1].scoreSubjects[MATH] = ptrarray[i].scoreSubjects[MATH];
				ptrarray[i - 1].scoreSubjects[PHYSICS] = ptrarray[i].scoreSubjects[PHYSICS];
				ptrarray[i - 1].scoreSubjects[PROGRAMMING] = ptrarray[i].scoreSubjects[PROGRAMMING];
				ptrarray[i - 1].scoreTotal = ptrarray[i].scoreTotal;
				ptrarray[i - 1].scoreAverage = ptrarray[i].scoreAverage;
			}
			countUsers--;
			// �迭�� ����� ���� �ϳ��� �մ���, ���� �Էµ� �л� ���� 1 ���ҽ�Ų��.
			return 1; // ������ �� 1�� �����Ѵ�.
		}
		else if (yesno == 'N')
		{
			printf("\n�ȳ�: �������� �ʽ��ϴ�.\n");
			flushInputBuffer();
			return 0;
		}
	}
	else if (selectedno > countUsers && selectedno <= MAX_USERS)
	{
		printf("\n�ȳ�: �ش� No�� �����Ͱ� �����ϴ�.\n");
		// ���� ���� ����� ���� �� ���� ���� �ִ� �Է� ������ ����� ������ ū ���� �Է� �޾����� ���� ���� �ʴ´�.
		return 0;
	}
	else if (selectedno > MAX_USERS)
	{
		printf("\n�ȳ�: �ִ� �л� ��%d�� �ʰ��ϴ� No�Դϴ�.\n", MAX_USERS);

		return 0;
	}
	else
	{
		printf("\n�ȳ�: ��ȿ���� ���� No. �Դϴ�.\n");

		return 0;
	}
}