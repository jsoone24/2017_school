#include <stdio.h>

int main(void)
{
	int number = 100; //int���� ���� number�� 100���� ���� �ʱ�ȭ��Ų��.
	int*ptrnumber; //int���� ������ ���� ptrnumber�� �����Ѵ�.

	ptrnumber = &number; //ptrnumber�� ��ȯ�� number�� �ּҰ����� �ʱ�ȭ��Ų��.

	printf("���� number�� �� %d\n", number); //number�� ���� �����Ͽ� ����Ѵ�.
	printf("���� number�� �ּ� %p\n", &number); //number�� ��ȯ�� �ּ� ���� ����Ѵ�.
	printf("������ ���� ptrnumber�� �� %p\n", ptrnumber); //ptrnumber�� ����� ���� �����Ͽ� ����Ѵ�.
	printf("������ ���� ptrnumber�� �ּ� ���� ������ �������� ��(*ptrnumber)�� ��: %d\n", *ptrnumber);
	//ptrnumber�� �ּҸ� �����Ͽ� number�� ���� ����Ѵ�.
	
	return 0; //�Լ��� �����Ѵ�.
}