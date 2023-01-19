#include <stdio.h>

void swapvalueuseptr(int*ptr1, int*ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void swapptr(int**dptr1, int**dptr2)
{
	int *temp = *dptr1;
	*dptr1 = *dptr2;
	*dptr2 = temp;
}

int main(void)
{
	int number1 = 7;
	int number2 = 10;

	printf("number1: %d, number2: %d\n", number1, number2);

	int*ptrnumber1 = &number1;
	int*ptrnumber2 = &number2;

	printf("\nswapptr 호출\n");
	swapptr(&ptrnumber1, &ptrnumber2);
	printf("number1: %d, number2: %d\n", number1, number2);
	printf("*ptrnumber1: %d, *ptrnumber2: %d\n", *ptrnumber1, *ptrnumber2);

	printf("\nswapvalueuseptr 호출\n");
	swapvalueuseptr(&number1, &number2);
	printf("number1: %d, number2: %d\n", number1, number2);

	return 0;
}