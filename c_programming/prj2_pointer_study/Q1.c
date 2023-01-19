#include <stdio.h>

int main(void)
{
	int number = 100; //int형의 변수 number을 100으로 값을 초기화시킨다.
	int*ptrnumber; //int형의 포인터 변수 ptrnumber을 선언한다.

	ptrnumber = &number; //ptrnumber을 반환된 number의 주소값으로 초기화시킨다.

	printf("변수 number의 값 %d\n", number); //number의 값을 참조하여 출력한다.
	printf("변수 number의 주소 %p\n", &number); //number의 반환된 주소 값을 출력한다.
	printf("포인터 변수 ptrnumber의 값 %p\n", ptrnumber); //ptrnumber에 저장된 값을 참조하여 출력한다.
	printf("포인터 변수 ptrnumber의 주소 참조 연산자 적용했을 때(*ptrnumber)의 값: %d\n", *ptrnumber);
	//ptrnumber의 주소를 참조하여 number의 값을 출력한다.
	
	return 0; //함수를 종료한다.
}