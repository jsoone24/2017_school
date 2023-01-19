#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef enum SubjectNames		// 세 과목에 대한 열거형 정의부
{ 
	MATH,						// MATH = 0
	PHYSICS,					// PHYSICS = 1
	PROGRAMMING,				// PROGRAMMING = 2
	NUMBER_OF_SUBJECT			// NUMBER_OF_SUBJECT = 3
} SUBJECT_NAME;

typedef struct Student
{
	char studentName[15];					// 학생 성명(문자열)
	int studentNumber;						// 학생 학번(정수형)
	int scoreSubjects[NUMBER_OF_SUBJECT];	// 학생 세 과목 점수(정수형 배열, 길이는 3)
	int scoreTotal;							// 세 과목의 총점(정수형)
	double scoreAverage;					// 세 과목의 평균(실수형)
} StudentInfomation;

#define MAX_USERS 10

int countUsers = 0;				// 현재 저장된 데이터의 수를 확인할 수 있는 변수

void flushInputBuffer(void);	// 입력 버퍼에 남아있는 개행문자를 비워주는 함수

void printMenu(void);			// 메뉴화면 출력 함수

void userInformationPrint(StudentInfomation* ptrarray);	// 현재 메모리에 저장되어 있는 데이터를 출력하는 함수

int userInformationCreate(StudentInfomation* ptrarray, char* const ptrname, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);	// 입력 정보를 추가하는 함수

int userInformationUpdate(StudentInfomation* ptrarray, int seletedno, char* name, int studentnumber, int scoremath, int scorephysics, int scoreprogramming);	// 선택한 정보를 수정하는 함수

int userInformationDelete(StudentInfomation* ptrarray, int seletedno);	// 저장되어 있는 데이터 중 선택된 데이터를 삭제하는 함수

int main(void)
{
	// 학생 정보 저장을 위한 구조체 배열 선언 및 입력에 필요한 변수 선언
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

