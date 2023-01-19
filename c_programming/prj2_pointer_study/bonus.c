#include <stdio.h>

void main()
{
	int arr[3][2] = { 1,2,3,4,5,6 };

	printf("%d\n%p\n%p\n%p\n", *(*(arr+1)), *(arr+1), *(arr), *(arr[1]));
}