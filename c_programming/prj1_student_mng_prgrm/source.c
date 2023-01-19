#define _CRT_SECURE_NO_WARNINGS
#define totalstudent 5 //최대 학생수를 설정하는 심벌릭 상수

#include <stdio.h>

int studentnum[totalstudent]; //학번을 저장하는 배열
int math[totalstudent]; //수학 점수를 저장하는 배열
int physics[totalstudent]; //물리 점수를 저장하는 배열
int programing[totalstudent]; //프로그래밍 점수를 저장하는 배열
int sum[totalstudent]; //세 과목 점수 합을 저장하는 배열
float average[totalstudent]; //세 과목 점수 평균을 저장하는 배열
int countnum = 0; //현재 얼마나 많은 학생들이 입력되었는가 기록하는 변수

int firstmenu(); //처음 메뉴화면을 출력하는 함수
int add(int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming);
//임시 저장된 학번 점수를 배열에 저장하는 함수
int print(); //현재 저장된 학생 목록 출력 함수
int adjust(int sujung, int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming);
//현재 저장된 학생중 정보 수정하는 함수
int delete(); //현재 저장된 목록에서 원하는 학생을 삭제하는 함수

void main()
{
	int sel, temp; //사용자가 입력한 메뉴번호변수 sel, 함수 호출 후 리턴값 임시 저장변수 temp
	char yesno; //프로그램 종료 여부 입력받는 변수
	int addtemp[4]; //입력받은 학번, 점수들을 임시 저장하기 위해 만든 배열

	printf("안내: 최대 입력가능 학생 수 : %d", totalstudent);
	while (1) {
		while (1) {
			firstmenu(); //메뉴출력
			scanf("%d", &sel); //메뉴선택 입력받음

			if (sel < 6 && sel>0) //1~5사이 수면 루프 탈출
				break;
			else
			{
				printf("안내 : 유효하지 않는 메뉴입니다. 다시 입력하세요\n");
				while (getchar() != '\n') {} //숫자 말고 문자를 입력받았을때 입력버퍼를 지운다
			}
		}


		if (sel == 1) {
			printf("\n안내: 학생 정보 입력을 선택하였습니다.\n\n");
			printf("학번: ");
			scanf("%d", &addtemp[0]);
			printf("공학수학 점수:");
			scanf("%d", &addtemp[1]);
			printf("물리 점수: ");
			scanf("%d", &addtemp[2]);
			printf("프로그래밍 점수: ");
			scanf("%d", &addtemp[3]); //사용자로부터 학번, 점수들을 입력받아 임시 배열에 저장한다.
			temp = add(addtemp[0], addtemp[1], addtemp[2], addtemp[3]); //학번, 점수를 전달인자로 보내고 리턴 값을 받는다.

			if (temp == 0) 
				printf("\n안내: 학생 정보 입력에 실패하였습니다.\n");
			else if(temp == 1) 
				printf("\n안내: 학생 정보 입력에 성공하였습니다.\n");

		}
		else if (sel == 2) {
			printf("안내: 학생 정보 출력을 선택하였습니다.\n\n");
			print();
		}
		else if (sel == 3) {
			int sujung = 0; //수정할 학생 번호를 입력받을 변수

			printf("\n안내: 학생 정보 수정을 선택하였습니다.\n");
			print(); //현재 저장된 학생정보 출력
			printf("\n수정을 원하는 학생의 No: ");
			scanf("%d", &sujung);
			printf("학번: ");
			scanf("%d", &addtemp[0]);
			printf("공학수학 점수:");
			scanf("%d", &addtemp[1]);
			printf("물리 점수: ");
			scanf("%d", &addtemp[2]);
			printf("프로그래밍 점수: ");
			scanf("%d", &addtemp[3]);
			temp = adjust(sujung, addtemp[0], addtemp[1], addtemp[2], addtemp[3]); //

			if (temp == 0)
				printf("\n안내: 수정에 실패하였습니다.\n");
			else if (temp == 1)
				printf("안내: 수정에 성공하였습니다.\n");
		}
		else if (sel == 4) {
			printf("\n안내: 학생 정보 삭제를 선택하였습니다.\n\n");
			temp = delete();

			if (temp == 0) 
				printf("\n안내: 삭제에 실패하였습니다.\n");
			else if (temp == 1) 
				printf("안내: 삭제에 성공하였습니다.\n");
		} // 메뉴1~4에서 각각의 리턴값에 따라서 성공 실패 여부를 출력한다.
		else
		{
			printf("\n안내: 정말 종료하시겠습니까?(Y/N):");
			while (getchar() != '\n') {}
			scanf("%c", &yesno);
			if (yesno == 'Y')
				break;
			else
				printf("\n안내: 메뉴로 복귀합니다.\n");
		} //사용자로부터 종료여부를 입력받는다.
	}
}

int firstmenu()
{
	printf("\n============================================\n");
	printf("		학사 관리 시스템\n");
	printf("============================================\n");
	printf("	1. 학생 정보 입력\n");
	printf("	2. 학생 정보 출력\n");
	printf("	3. 학생 정보 수정\n");
	printf("	4. 학생 정보 삭제\n");
	printf("	5. 프로그램 종료\n");
	printf("============================================\n");
	printf("메뉴 선택 : ");

	return 0;
}

int add(int scanstudentnum, int scanmath,int scanphysics, int scanprogrammming)
{
	if (countnum >= totalstudent) {
		printf("\n안내: 최대 입력 학생 수 %d명을 초과하였습니다.\n", totalstudent);

		return 0; //만약 최대 입력 가능 학생 수를 초과하면 0을 리턴하며 종료된다.
	}
	else 
	{
		//전달인자로 입력된 데이터를 가지고 데이터입력 함수를 호출하여 정보를 각 배열에 추가

		studentnum[countnum] = scanstudentnum;
		math[countnum] = scanmath;
		physics[countnum] = scanphysics;
		programing[countnum] = scanprogrammming;
		sum[countnum] = scanmath + scanphysics + scanprogrammming;
		average[countnum] = (float)sum[countnum] / 3;

		countnum++;

		return 1; //임시 저장된 정보를 배열에 넣고 입력된 학생 수를 한명 증가시키고 1을 리턴하며 종료한다.
	}
}

int print()
{
	int i = 0;

	printf("\n========================================================================================\n");
	printf("No.	학번		공학수학	물리	프로그래밍	:	총점	평균\n");
	printf("========================================================================================\n");

	for (i = 0; i < countnum; i++)
		printf("%d	%d	%d		%d	%d			%d	%f\n",i+1,studentnum[i],math[i],physics[i], programing[i], sum[i], average[i]);
	
	printf("========================================================================================\n");
	printf("\n안내: 출력이 완료 되었습니다.\n");
	//현재 입력된 학생 수 까지 저장된 배열의 값을 출력한다
	return 0;
}

int adjust(int sujung, int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming)
{
	if (sujung <= countnum && sujung>0) {
		sujung -= 1; //배열은 0부터 저장되지만 출력은 1부터 하므로 1을 뺀다

		studentnum[sujung] = scanstudentnum;
		math[sujung] = scanmath;
		physics[sujung] = scanphysics;
		programing[sujung] = scanprogrammming;
		sum[sujung] = scanmath + scanphysics + scanprogrammming;
		average[sujung] = (float)sum[sujung] / 3;
		//수정할 숫자 배열에 전달인자로 전달받은 정보들을 저장한다.
		printf("\n안내: 수정이 완료 되었습니다. 메뉴로 돌아갑니다.\n\n");
		//만약 수정할 번호가 현재 입력된 학생 수 보다 적고, 0보다 큰 수일때 수정한다
		return 1;
	}
	else if (sujung <= totalstudent && sujung> countnum) {
		printf("\n안내: 아직 입력 되지 않은 정보입니다. 수정 요청 정보로 학생정보를 추가합니다..\n");

		studentnum[countnum] = scanstudentnum;
		math[countnum] = scanmath;
		physics[countnum] = scanphysics;
		programing[countnum] = scanprogrammming;
		sum[countnum] = scanmath + scanphysics + scanprogrammming;
		average[countnum] = (float)sum[countnum] / 3;
		countnum++;

		printf("\n안내: 요청하신 정보를 추가하였습니다.\n");
		//만약 수정할 번호가 현재 입력된 학생 수보다 많고, 최대 입력가능 학생수 보다 작을 때 학생정보를 새로이 추가한다
		return 1;//수정에 성공하면 1을 리턴한다
	}
	else {
		printf("\n안내: 부적절한 No입니다.\n", totalstudent);
		//그 외의 수를 입력하면 수정에 실패 한다.
		return 0; //수정에 실패하면 0을 리턴한다
	}
}

int delete()
{
	int deletenum = 0, i; //삭제할 번호를 받을 변수 deletenum을 설정한다.
	char yesno = 0; //삭제 여부를 입력 받을 변수

	print(); //목록 출력
	printf("삭제를 원하는 학생의 No: ");
	scanf("%d", &deletenum); //삭제할 연번 입력받음

	if (deletenum > 0 && deletenum <= countnum) {
		printf("정말 이 정보를 삭제하시겠습니까?(Y/N): ");
		while (getchar() != '\n') {}
		scanf("%c", &yesno);
		
		if (yesno == 'Y') {
			for (i = deletenum; i <= countnum; i++) {
				studentnum[i - 1] = studentnum[i];
				math[i - 1] = math[i];
				physics[i - 1] = physics[i];
				programing[i - 1] = programing[i];
				sum[i - 1] = sum[i];
				average[i - 1] = average[i];
			}
			countnum--;
			//배열에 저장된 값을 하나씩 앞당기며, 현재 입력된 학생 수를 1 감소시킨다.
			return 1; //삭제한 후 1을 리턴한다.
		}
		else if (yesno == 'N') {
			printf("\n안내: 삭제하지 않습니다.\n");
			return 0; 
		}
	}
	else if (deletenum > countnum && deletenum <= totalstudent) {
		printf("\n안내: 해당 No에 데이터가 없습니다.\n");
		//만약 현재 저장된 값의 수 보다 많고 최대 입력 가능한 사람의 수보다 큰 수를 입력 받았을때 삭제 하지 않는다.
		return 0;
	}
	else if(deletenum>totalstudent){
		printf("\n안내: 최대 학생 수%d를 초과하는 No입니다.\n", totalstudent);
		
		return 0;
	}
	else {
		printf("\n안내: 유효하지 않은 No. 입니다.\n");

		return 0;
	}
}