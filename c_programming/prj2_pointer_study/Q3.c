#include <stdio.h>

int main(void)
{
	int number = 10; //int���� ���� number�� ������ ��, 10���� ���� �ʱ�ȭ��Ų��.
	int*ptr1 = &number; //int���� �����ͺ��� ptr1 ������ number�� �ּҰ��� ��ȯ�Ͽ� �ʱ�ȭ��Ų��.
	int*ptr2 = ptr1; //int���� �����ͺ��� ptr2������ ptr1�� ����� ���� �����Ͽ� �ʱ�ȭ��Ų��.

	(*ptr1)++; //ptr1�� ����� �ּҸ� �����Ͽ� �޸𸮿� ������ �� ���� 1 ������Ų��.
	(*ptr2)++; //ptr2�� ����� �ּҸ� �����Ͽ� �޸𸮿� ������ �� ���� 1 ������Ų��.

	printf("number = %d\n", number); //number�� ���� �����Ͽ� ����Ѵ�.

	return 0; //�Լ��� �����Ѵ�.
}