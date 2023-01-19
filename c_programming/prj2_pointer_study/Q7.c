#include <stdio.h>

int getstringlength(char*str);
void stringconcatenate(char*str_src1, char*str_src2, char*str_dest);

int main(void)
{
	char str1[10] = "Soongsil";
	char str2[20] = " University";
	char str3[30];

	stringconcatenate(str1, str2, str3);

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);

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

void stringconcatenate(char*str_src1, char*str_src2, char*str_dest)
{
	for (int i = 0; i < getstringlength(str_src1); i++)
		str_dest[i] = str_src1[i];

	for (int i = 0; i <= getstringlength(str_src2); i++)
		str_dest[i+getstringlength(str_src1)] = str_src2[i];
}