#include <stdio.h>

int main(void)
{
	int number = 100; //int���� ���� number�� �����ϰ� ���� 100���� �ʱ�ȭ��Ų��.
	int*ptrnumber; //int���� �����ͺ��� ptrnumber�� �����Ѵ�.

	ptrnumber = &number; //ptrnumber�� ��ȯ�� number�� �ּҰ����� �ʱ�ȭ ��Ų��.

	printf("number�� �� %d\n", number); //number�� ���� �����Ͽ� ����Ѵ�.
	printf("ptrnumber�� ��: %d\n", *ptrnumber); //ptrnumber�� �ּҸ� �����Ͽ� ���� ����Ѵ�.
	printf("\n"); //���๮�ڸ� ����Ѵ�.

	*ptrnumber = 200; //�ּҸ� �����Ͽ� ���� ����� �޸𸮿� �����Ͽ� ���� �����Ѵ�.
	printf("number�� ��: %d\n", number); //number�� ���� �����Ͽ� ����Ѵ�.
	printf("*ptrnumber�� ��: %d\n", *ptrnumber); //ptrnumber�� �ּҸ� �����Ͽ� ���� ����Ѵ�.
	printf("\n"); //���๮�ڸ� ����Ѵ�.

	*ptrnumber = 0; //�ּҸ� �����Ͽ� ���� ����� �޸𸮿� �����Ͽ� ���� �����Ѵ�.
	printf("number�� ��: %d\n", number); //number�� ���� �����Ͽ� ����Ѵ�.
	printf("*ptrnumber�� ��: %d\n", *ptrnumber); //ptrnumber�� �ּҸ� �����Ͽ� ���� ����Ѵ�.
	printf("\n"); //���๮�ڸ� ����Ѵ�.

	return 0; //�Լ��� �����Ѵ�.
}