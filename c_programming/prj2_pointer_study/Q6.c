#include <stdio.h>

int getstringlength(char*str);
void stringcopy(char*str_src, char*str_dest);

int main(void)
{
	char str1[10] = "Hello";
	char str2[20];

	stringcopy(str1, str2);

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	return 0;
}

int getstringlength(char*str)
{
	int length = 0, i = 0;

	while (str[i] != '\0')
	{
		length++;
		i++;
	}

	return length;
}

void stringcopy(char*str_src, char*str_dest)
{
	for (int i = 0; i <= getstringlength(str_src); i++)
		str_dest[i] = str_src[i];
}