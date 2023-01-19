#include <stdio.h>

int main(void)
{
	int number = 10; //int형의 변수 number을 선언한 후, 10으로 값을 초기화시킨다.
	int*ptr1 = &number; //int형의 포인터변수 ptr1 선언후 number의 주소값을 반환하여 초기화시킨다.
	int*ptr2 = ptr1; //int형의 포인터변수 ptr2선언후 ptr1에 저장된 값을 참조하여 초기화시킨다.

	(*ptr1)++; //ptr1에 저장된 주소를 참조하여 메모리에 접근해 그 값을 1 증가시킨다.
	(*ptr2)++; //ptr2에 저장된 주소를 참조하여 메모리에 접근해 그 값을 1 증가시킨다.

	printf("number = %d\n", number); //number의 값을 참조하여 출력한다.

	return 0; //함수를 종료한다.
}