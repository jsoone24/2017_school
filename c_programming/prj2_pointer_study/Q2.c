#include <stdio.h>

int main(void)
{
	int number = 100; //int형의 변수 number을 선언하고 값을 100으로 초기화시킨다.
	int*ptrnumber; //int형의 포인터변수 ptrnumber을 선언한다.

	ptrnumber = &number; //ptrnumber을 반환된 number의 주소값으로 초기화 시킨다.

	printf("number의 값 %d\n", number); //number의 값을 참조하여 출력한다.
	printf("ptrnumber의 값: %d\n", *ptrnumber); //ptrnumber의 주소를 참조하여 값을 출력한다.
	printf("\n"); //개행문자를 출력한다.

	*ptrnumber = 200; //주소를 참조하여 값이 저장된 메모리에 접근하여 값을 수정한다.
	printf("number의 값: %d\n", number); //number의 값을 참조하여 출력한다.
	printf("*ptrnumber의 값: %d\n", *ptrnumber); //ptrnumber의 주소를 참조하여 값을 출력한다.
	printf("\n"); //개행문자를 출력한다.

	*ptrnumber = 0; //주소를 참조하여 값이 저장된 메모리에 접근하여 값을 수정한다.
	printf("number의 값: %d\n", number); //number의 값을 참조하여 출력한다.
	printf("*ptrnumber의 값: %d\n", *ptrnumber); //ptrnumber의 주소를 참조하여 값을 출력한다.
	printf("\n"); //개행문자를 출력한다.

	return 0; //함수를 종료한다.
}