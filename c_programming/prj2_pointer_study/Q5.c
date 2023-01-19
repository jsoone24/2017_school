#include <stdio.h>

void arrayprint(int*ptrarray, int arraysize);
void arraysort(int*ptrarray, int arraysize);

int main(void)
{
	int arraynumber[] = { 5,2,4,1,3 };

	printf("==정렬 전==\n");
	arrayprint(arraynumber, sizeof(arraynumber) / sizeof(int));

	arraysort(arraynumber, sizeof(arraynumber) / sizeof(int));

	printf("==정렬 후==\n");
	arrayprint(arraynumber, sizeof(arraynumber) / sizeof(int));

	return 0;
}

void arrayprint(int*ptrarray, int arraysize)
{
	for (int i = 0; i < arraysize; i++)
		printf("[%d] : %d\n", i, ptrarray[i]);
}

void arraysort(int*ptrarray, int arraysize)
{
	int temp, i, j, min;

	for (i = 0; i < arraysize; i++)
	{
		min = i;

		for (j = i; j < arraysize; j++)
			if (ptrarray[j] < ptrarray[min])
				min = j;

		temp = ptrarray[i];
		ptrarray[i] = ptrarray[min];
		ptrarray[min] = temp;
	}
}