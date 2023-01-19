#define _CRT_SECURE_NO_WARNINGS
#define MAX_USERS 10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum SubjectNames // 세 과목에 대한 열거형 정의부
{
	MATH,			  // MATH = 0
	PHYSICS,		  // PHYSICS = 1
	PROGRAMMING,	  // PROGRAMMING = 2
	NUMBER_OF_SUBJECT // NUMBER_OF_SUBJECT = 3
} SUBJECT_NAME;

typedef struct Student
{
	char studentName[15];				  // 학생 성명(문자열)
	int studentNumber;					  // 학생 학번(정수형)
	int scoreSubjects[NUMBER_OF_SUBJECT]; // 학생 세 과목 점수(정수형 배열, 길이는 3)
	int scoreTotal;						  // 세 과목의 총점(정수형)
	double scoreAverage;				  // 세 과목의 평균(실수형)
} StudentInfomation;

int countUsers = 0; // 현재 저장된 데이터의 수를 확인할 수 있는 변수

void flushInputBuffer(void);																																 // 입력 버퍼에 남아있는 개행문자를 비워주는 함수
void printMenu(void);																																		 // 메뉴화면 출력 함수
void userInformationPrint(StudentInfomation *ptrarray);																										 // 현재 메모리에 저장되어 있는 데이터를 출력하는 함수
int userInformationCreate(StudentInfomation *ptrarray, char *const ptrname, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);		 // 입력 정보를 추가하는 함수
int userInformationUpdate(StudentInfomation *ptrarray, int seletedno, char *name, int studentnumber, int scoremath, int scorephysics, int scoreprogramming); // 선택한 정보를 수정하는 함수
int userInformationDelete(StudentInfomation *ptrarray, int seletedno);																						 // 저장되어 있는 데이터 중 선택된 데이터를 삭제하는 함수

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
	// 학생 정보 저장을 위한 구조체 배열 선언 및 입력에 필요한 변수 선언

	printf("안내: 최대 입력가능 학생 수 : %d\n", MAX_USERS);

	FILE *fp = fopen("./StudentData.txt", "rt");

	if (fp == NULL)
	{
		printf("\n\n파일 열기에 실패 하였습니다.\n\n");
		return -1;
	}
	else
		printf("안내 : StudentData.txt 파일을 읽어오는데 성공 하였습니다.\n");

	while (1)
	{
		int a = fscanf(fp, "%s %d %d %d %d", inputName, &inputStudentNumber,
					   &inputScoreMath, &inputScorePhysics, &inputScoreProgramming);

		if (feof(fp) && a == EOF)
			break;

		userInformationCreate(arrayStudent, inputName, inputStudentNumber,
							  inputScoreMath, inputScorePhysics, inputScoreProgramming);

		printf("\n안내: 요청하신 정보를 추가하였습니다.\n");
	}
	fclose(fp);
	// 파일을 읽기 모드로오픈하여 파일에 저장되어있는 학생 수집데이터를 구조체 배열에 저장한후 파일을 닫는다.
	while (1)
	{
		while (1)
		{
			printMenu();				   // 메뉴출력
			scanf("%d", &inputMenuNumber); // 메뉴선택 입력받음

			if (inputMenuNumber < 6 && inputMenuNumber > 0) // 1~5사이 수면 루프 탈출
				break;
			else
				printf("안내 : 유효하지 않는 메뉴입니다. 다시 입력하세요\n");
			flushInputBuffer(); // 숫자 말고 문자를 입력받았을때 입력버퍼를 지운다
		}

		if (inputMenuNumber == 1)
		{
			flushInputBuffer();
			printf("\n안내: 학생 정보 입력을 선택하였습니다.\n\n");
			printf("성명: ");
			scanf("%s", inputName);
			printf("학번: ");
			scanf("%d", &inputStudentNumber);
			printf("공학수학 점수:");
			scanf("%d", &inputScoreMath);
			printf("물리 점수: ");
			scanf("%d", &inputScorePhysics);
			printf("프로그래밍 점수: ");
			scanf("%d", &inputScoreProgramming);
			// 사용자로부터 이름, 학번, 점수들을 입력받아 임시 변수에 저장한다.

			if (userInformationCreate(arrayStudent, inputName, inputStudentNumber,
									  inputScoreMath, inputScorePhysics, inputScoreProgramming) == 0)
				printf("\n안내: 학생 정보 입력에 실패하였습니다.\n");
			else
				printf("\n안내: 학생 정보 입력에 성공하였습니다.\n");
			// 리턴 값에 따라 성공 실패 여부를 출력한다.
		}
		else if (inputMenuNumber == 2)
		{
			printf("안내: 학생 정보 출력을 선택하였습니다.\n\n");
			userInformationPrint(arrayStudent);
			// 학생 정보를 출력하는 함수를 실행한다.
		}
		else if (inputMenuNumber == 3)
		{
			printf("\n안내: 학생 정보 수정을 선택하였습니다.\n");
			flushInputBuffer();
			userInformationPrint(arrayStudent); // 현재 저장된 학생정보 출력
			printf("\n수정을 원하는 학생의 No: ");
			scanf("%d", &inputChooseNumber);
			printf("성명: ");
			scanf("%s", inputName);
			printf("학번: ");
			scanf("%d", &inputStudentNumber);
			printf("공학수학 점수:");
			scanf("%d", &inputScoreMath);
			printf("물리 점수: ");
			scanf("%d", &inputScorePhysics);
			printf("프로그래밍 점수: ");
			scanf("%d", &inputScoreProgramming);
			// 사용자로부터 수정할 학생의 연번, 이름, 학번, 점수들을 입력받아 임시 변수에 저장한다.
			if (userInformationUpdate(arrayStudent, inputChooseNumber, inputName, inputStudentNumber,
									  inputScoreMath, inputScorePhysics, inputScoreProgramming) == 0)
				printf("\n안내: 수정에 실패하였습니다.\n");
			else
				printf("안내: 수정에 성공하였습니다.\n");
			// 함수 실행 후 리턴 값에 따라 성공 실패 여부를 출력한다.
		}
		else if (inputMenuNumber == 4)
		{
			printf("\n안내: 학생 정보 삭제를 선택하였습니다.\n\n");
			userInformationPrint(arrayStudent);
			// 현재 저장된 학생 정보 출력
			printf("\n삭제를 원하는 학생의 No: ");
			scanf("%d", &inputChooseNumber);

			if (userInformationDelete(arrayStudent, inputChooseNumber) == 0)
				printf("\n안내: 삭제에 실패하였습니다.\n");
			else
				printf("안내: 삭제에 성공하였습니다.\n");
			// 함수 실행 후 리턴값에 따라서 성공 실패 여부를 출력한다.
		}
		else
		{
			printf("\n안내: 저장 후 프로그램을 종료합니다.\n");
			break;
		}
	}
	printf("\n안내: 현재 정보를 StudentData.txt 파일에 저장합니다.\n");

	fp = fopen("./StudentData.txt", "wt");

	if (fp == NULL)
	{
		printf("\n\n파일 열기에 실패 하였습니다.\n\n");
		return -1;
	}

	for (int i = 0; i < countUsers; i++)
		fprintf(fp, "%s %d %d %d %d\n", arrayStudent[i].studentName, arrayStudent[i].studentNumber,
				arrayStudent[i].scoreSubjects[MATH], arrayStudent[i].scoreSubjects[PHYSICS],
				arrayStudent[i].scoreSubjects[PROGRAMMING]);

	fclose(fp);

	printf("\nStudentData.txt 파일을 생성하였습니다.\n");
	printf("\n안내: 프로그램을 종료합니다.\n");
	// 파일을 쓰기모드로 오픈 후 구조체 배열에 저장된 정보들을 파일에 출력한후 파일을 닫는다.
	return 0;
}

void flushInputBuffer(void) // 입력 버퍼에 남아있는 개행문자를 비워주는 함수
{
	while (getchar() != '\n')
	{
	}
}

void printMenu(void) // 메뉴화면 출력 함수
{
	printf("\n============================================\n");
	printf("		학사 관리 시스템\n");
	printf("============================================\n");
	printf("	1. 학생 정보 입력\n");
	printf("	2. 학생 정보 출력\n");
	printf("	3. 학생 정보 수정\n");
	printf("	4. 학생 정보 삭제\n");
	printf("	5. 저장하고 프로그램 종료\n");
	printf("============================================\n");
	printf("메뉴 선택 : ");
}

void userInformationPrint(StudentInfomation *ptrarray) // 현재 메모리에 저장되어 있는 데이터를 출력하는 함수
{
	int i = 0;

	printf("\n===========================================================================================================\n");
	printf("No.	성  명		  학번		공학수학	물리	프로그래밍	:	총점	  평균\n");
	printf("============================================================================================================\n");

	for (i = 0; i < countUsers; i++)
		printf("%d	%s		%d	   %d		%d	    %d			  %d	%0.2f\n", i + 1, ptrarray[i].studentName,
			   ptrarray[i].studentNumber, ptrarray[i].scoreSubjects[MATH], ptrarray[i].scoreSubjects[PHYSICS],
			   ptrarray[i].scoreSubjects[PROGRAMMING], ptrarray[i].scoreTotal, ptrarray[i].scoreAverage);

	printf("============================================================================================================\n");
	printf("\n안내: 출력이 완료 되었습니다.\n");
	// 현재 입력된 학생 수 까지 저장된 배열의 값을 출력한다
}

int userInformationCreate(StudentInfomation *ptrarray, char *const ptrname,
						  int studentnumber, int scoremath, int scorephysics, int scoreprogramming) // 입력 정보를 추가하는 함수
{
	if (countUsers >= MAX_USERS)
	{
		printf("\n안내: 최대 입력 학생 수 %d명을 초과하였습니다.\n", MAX_USERS);

		return 0; // 만약 최대 입력 가능 학생 수를 초과하면 0을 리턴하며 종료된다.
	}
	else
	{
		// 전달인자로 입력된 데이터를 가지고 데이터입력 함수를 호출하여 정보를 각 배열에 추가
		strcpy(ptrarray[countUsers].studentName, ptrname);
		ptrarray[countUsers].studentNumber = studentnumber;
		ptrarray[countUsers].scoreSubjects[MATH] = scoremath;
		ptrarray[countUsers].scoreSubjects[PHYSICS] = scorephysics;
		ptrarray[countUsers].scoreSubjects[PROGRAMMING] = scoreprogramming;
		ptrarray[countUsers].scoreTotal = scoremath + scorephysics + scoreprogramming;
		ptrarray[countUsers].scoreAverage = (double)ptrarray[countUsers].scoreTotal / 3;

		countUsers++;

		return 1; // 임시 저장된 정보를 배열에 넣고 입력된 학생 수를 한명 증가시키고 1을 리턴하며 종료한다.
	}
}

int userInformationUpdate(StudentInfomation *ptrarray, int selectedno, char *name,
						  int studentnumber, int scoremath, int scorephysics, int scoreprogramming) // 선택한 정보를 수정하는 함수
{
	if (selectedno <= countUsers && selectedno > 0)
	{
		selectedno -= 1; // 배열은 0부터 저장되지만 출력은 1부터 하므로 1을 뺀다

		strcpy(ptrarray[selectedno].studentName, name);
		ptrarray[selectedno].studentNumber = studentnumber;
		ptrarray[selectedno].scoreSubjects[MATH] = scoremath;
		ptrarray[selectedno].scoreSubjects[PHYSICS] = scorephysics;
		ptrarray[selectedno].scoreSubjects[PROGRAMMING] = scoreprogramming;
		ptrarray[selectedno].scoreTotal = scoremath + scorephysics + scoreprogramming;
		ptrarray[selectedno].scoreAverage = (double)ptrarray[selectedno].scoreTotal / 3;

		// 수정할 숫자 배열에 전달인자로 전달받은 정보들을 저장한다.
		printf("\n안내: 수정이 완료 되었습니다. 메뉴로 돌아갑니다.\n\n");
		// 만약 수정할 번호가 현재 입력된 학생 수 보다 적고, 0보다 큰 수일때 수정한다
		return 1;
	}
	else if (selectedno <= MAX_USERS && selectedno > countUsers)
	{
		printf("\n안내: 아직 입력 되지 않은 정보입니다. 수정 요청 정보로 학생정보를 추가합니다..\n");

		userInformationCreate(ptrarray, name, studentnumber, scoremath, scorephysics, scoreprogramming);

		printf("\n안내: 요청하신 정보를 추가하였습니다.\n");
		// 만약 수정할 번호가 현재 입력된 학생 수보다 많고, 최대 입력가능 학생수 보다 작을 때 학생정보를 새로이 추가한다
		return 1; // 수정에 성공하면 1을 리턴한다
	}
	else
	{
		printf("\n안내: 부적절한 No입니다.\n");
		// 그 외의 수를 입력하면 수정에 실패 한다.
		return 0; // 수정에 실패하면 0을 리턴한다
	}
}

int userInformationDelete(StudentInfomation *ptrarray, int selectedno)
// 저장되어 있는 데이터 중 선택된 데이터를 삭제하는 함수
{
	char yesno = 0; // 삭제 여부를 입력 받을 변수

	if (selectedno > 0 && selectedno <= countUsers)
	{
		printf("정말 이 정보를 삭제하시겠습니까?(Y/N): ");
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
			// 배열에 저장된 값을 하나씩 앞당기며, 현재 입력된 학생 수를 1 감소시킨다.
			return 1; // 삭제한 후 1을 리턴한다.
		}
		else if (yesno == 'N')
		{
			printf("\n안내: 삭제하지 않습니다.\n");
			flushInputBuffer();
			return 0;
		}
	}
	else if (selectedno > countUsers && selectedno <= MAX_USERS)
	{
		printf("\n안내: 해당 No에 데이터가 없습니다.\n");
		// 만약 현재 저장된 값의 수 보다 많고 최대 입력 가능한 사람의 수보다 큰 수를 입력 받았을때 삭제 하지 않는다.
		return 0;
	}
	else if (selectedno > MAX_USERS)
	{
		printf("\n안내: 최대 학생 수%d를 초과하는 No입니다.\n", MAX_USERS);

		return 0;
	}
	else
	{
		printf("\n안내: 유효하지 않은 No. 입니다.\n");

		return 0;
	}
}