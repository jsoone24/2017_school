#define _CRT_SECURE_NO_WARNINGS
#define totalstudent 5 //�ִ� �л����� �����ϴ� �ɹ��� ���

#include <stdio.h>

int studentnum[totalstudent]; //�й��� �����ϴ� �迭
int math[totalstudent]; //���� ������ �����ϴ� �迭
int physics[totalstudent]; //���� ������ �����ϴ� �迭
int programing[totalstudent]; //���α׷��� ������ �����ϴ� �迭
int sum[totalstudent]; //�� ���� ���� ���� �����ϴ� �迭
float average[totalstudent]; //�� ���� ���� ����� �����ϴ� �迭
int countnum = 0; //���� �󸶳� ���� �л����� �ԷµǾ��°� ����ϴ� ����

int firstmenu(); //ó�� �޴�ȭ���� ����ϴ� �Լ�
int add(int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming);
//�ӽ� ����� �й� ������ �迭�� �����ϴ� �Լ�
int print(); //���� ����� �л� ��� ��� �Լ�
int adjust(int sujung, int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming);
//���� ����� �л��� ���� �����ϴ� �Լ�
int delete(); //���� ����� ��Ͽ��� ���ϴ� �л��� �����ϴ� �Լ�

void main()
{
	int sel, temp; //����ڰ� �Է��� �޴���ȣ���� sel, �Լ� ȣ�� �� ���ϰ� �ӽ� ���庯�� temp
	char yesno; //���α׷� ���� ���� �Է¹޴� ����
	int addtemp[4]; //�Է¹��� �й�, �������� �ӽ� �����ϱ� ���� ���� �迭

	printf("�ȳ�: �ִ� �Է°��� �л� �� : %d", totalstudent);
	while (1) {
		while (1) {
			firstmenu(); //�޴����
			scanf("%d", &sel); //�޴����� �Է¹���

			if (sel < 6 && sel>0) //1~5���� ���� ���� Ż��
				break;
			else
			{
				printf("�ȳ� : ��ȿ���� �ʴ� �޴��Դϴ�. �ٽ� �Է��ϼ���\n");
				while (getchar() != '\n') {} //���� ���� ���ڸ� �Է¹޾����� �Է¹��۸� �����
			}
		}


		if (sel == 1) {
			printf("\n�ȳ�: �л� ���� �Է��� �����Ͽ����ϴ�.\n\n");
			printf("�й�: ");
			scanf("%d", &addtemp[0]);
			printf("���м��� ����:");
			scanf("%d", &addtemp[1]);
			printf("���� ����: ");
			scanf("%d", &addtemp[2]);
			printf("���α׷��� ����: ");
			scanf("%d", &addtemp[3]); //����ڷκ��� �й�, �������� �Է¹޾� �ӽ� �迭�� �����Ѵ�.
			temp = add(addtemp[0], addtemp[1], addtemp[2], addtemp[3]); //�й�, ������ �������ڷ� ������ ���� ���� �޴´�.

			if (temp == 0) 
				printf("\n�ȳ�: �л� ���� �Է¿� �����Ͽ����ϴ�.\n");
			else if(temp == 1) 
				printf("\n�ȳ�: �л� ���� �Է¿� �����Ͽ����ϴ�.\n");

		}
		else if (sel == 2) {
			printf("�ȳ�: �л� ���� ����� �����Ͽ����ϴ�.\n\n");
			print();
		}
		else if (sel == 3) {
			int sujung = 0; //������ �л� ��ȣ�� �Է¹��� ����

			printf("\n�ȳ�: �л� ���� ������ �����Ͽ����ϴ�.\n");
			print(); //���� ����� �л����� ���
			printf("\n������ ���ϴ� �л��� No: ");
			scanf("%d", &sujung);
			printf("�й�: ");
			scanf("%d", &addtemp[0]);
			printf("���м��� ����:");
			scanf("%d", &addtemp[1]);
			printf("���� ����: ");
			scanf("%d", &addtemp[2]);
			printf("���α׷��� ����: ");
			scanf("%d", &addtemp[3]);
			temp = adjust(sujung, addtemp[0], addtemp[1], addtemp[2], addtemp[3]); //

			if (temp == 0)
				printf("\n�ȳ�: ������ �����Ͽ����ϴ�.\n");
			else if (temp == 1)
				printf("�ȳ�: ������ �����Ͽ����ϴ�.\n");
		}
		else if (sel == 4) {
			printf("\n�ȳ�: �л� ���� ������ �����Ͽ����ϴ�.\n\n");
			temp = delete();

			if (temp == 0) 
				printf("\n�ȳ�: ������ �����Ͽ����ϴ�.\n");
			else if (temp == 1) 
				printf("�ȳ�: ������ �����Ͽ����ϴ�.\n");
		} // �޴�1~4���� ������ ���ϰ��� ���� ���� ���� ���θ� ����Ѵ�.
		else
		{
			printf("\n�ȳ�: ���� �����Ͻðڽ��ϱ�?(Y/N):");
			while (getchar() != '\n') {}
			scanf("%c", &yesno);
			if (yesno == 'Y')
				break;
			else
				printf("\n�ȳ�: �޴��� �����մϴ�.\n");
		} //����ڷκ��� ���Ῡ�θ� �Է¹޴´�.
	}
}

int firstmenu()
{
	printf("\n============================================\n");
	printf("		�л� ���� �ý���\n");
	printf("============================================\n");
	printf("	1. �л� ���� �Է�\n");
	printf("	2. �л� ���� ���\n");
	printf("	3. �л� ���� ����\n");
	printf("	4. �л� ���� ����\n");
	printf("	5. ���α׷� ����\n");
	printf("============================================\n");
	printf("�޴� ���� : ");

	return 0;
}

int add(int scanstudentnum, int scanmath,int scanphysics, int scanprogrammming)
{
	if (countnum >= totalstudent) {
		printf("\n�ȳ�: �ִ� �Է� �л� �� %d���� �ʰ��Ͽ����ϴ�.\n", totalstudent);

		return 0; //���� �ִ� �Է� ���� �л� ���� �ʰ��ϸ� 0�� �����ϸ� ����ȴ�.
	}
	else 
	{
		//�������ڷ� �Էµ� �����͸� ������ �������Է� �Լ��� ȣ���Ͽ� ������ �� �迭�� �߰�

		studentnum[countnum] = scanstudentnum;
		math[countnum] = scanmath;
		physics[countnum] = scanphysics;
		programing[countnum] = scanprogrammming;
		sum[countnum] = scanmath + scanphysics + scanprogrammming;
		average[countnum] = (float)sum[countnum] / 3;

		countnum++;

		return 1; //�ӽ� ����� ������ �迭�� �ְ� �Էµ� �л� ���� �Ѹ� ������Ű�� 1�� �����ϸ� �����Ѵ�.
	}
}

int print()
{
	int i = 0;

	printf("\n========================================================================================\n");
	printf("No.	�й�		���м���	����	���α׷���	:	����	���\n");
	printf("========================================================================================\n");

	for (i = 0; i < countnum; i++)
		printf("%d	%d	%d		%d	%d			%d	%f\n",i+1,studentnum[i],math[i],physics[i], programing[i], sum[i], average[i]);
	
	printf("========================================================================================\n");
	printf("\n�ȳ�: ����� �Ϸ� �Ǿ����ϴ�.\n");
	//���� �Էµ� �л� �� ���� ����� �迭�� ���� ����Ѵ�
	return 0;
}

int adjust(int sujung, int scanstudentnum, int scanmath, int scanphysics, int scanprogrammming)
{
	if (sujung <= countnum && sujung>0) {
		sujung -= 1; //�迭�� 0���� ��������� ����� 1���� �ϹǷ� 1�� ����

		studentnum[sujung] = scanstudentnum;
		math[sujung] = scanmath;
		physics[sujung] = scanphysics;
		programing[sujung] = scanprogrammming;
		sum[sujung] = scanmath + scanphysics + scanprogrammming;
		average[sujung] = (float)sum[sujung] / 3;
		//������ ���� �迭�� �������ڷ� ���޹��� �������� �����Ѵ�.
		printf("\n�ȳ�: ������ �Ϸ� �Ǿ����ϴ�. �޴��� ���ư��ϴ�.\n\n");
		//���� ������ ��ȣ�� ���� �Էµ� �л� �� ���� ����, 0���� ū ���϶� �����Ѵ�
		return 1;
	}
	else if (sujung <= totalstudent && sujung> countnum) {
		printf("\n�ȳ�: ���� �Է� ���� ���� �����Դϴ�. ���� ��û ������ �л������� �߰��մϴ�..\n");

		studentnum[countnum] = scanstudentnum;
		math[countnum] = scanmath;
		physics[countnum] = scanphysics;
		programing[countnum] = scanprogrammming;
		sum[countnum] = scanmath + scanphysics + scanprogrammming;
		average[countnum] = (float)sum[countnum] / 3;
		countnum++;

		printf("\n�ȳ�: ��û�Ͻ� ������ �߰��Ͽ����ϴ�.\n");
		//���� ������ ��ȣ�� ���� �Էµ� �л� ������ ����, �ִ� �Է°��� �л��� ���� ���� �� �л������� ������ �߰��Ѵ�
		return 1;//������ �����ϸ� 1�� �����Ѵ�
	}
	else {
		printf("\n�ȳ�: �������� No�Դϴ�.\n", totalstudent);
		//�� ���� ���� �Է��ϸ� ������ ���� �Ѵ�.
		return 0; //������ �����ϸ� 0�� �����Ѵ�
	}
}

int delete()
{
	int deletenum = 0, i; //������ ��ȣ�� ���� ���� deletenum�� �����Ѵ�.
	char yesno = 0; //���� ���θ� �Է� ���� ����

	print(); //��� ���
	printf("������ ���ϴ� �л��� No: ");
	scanf("%d", &deletenum); //������ ���� �Է¹���

	if (deletenum > 0 && deletenum <= countnum) {
		printf("���� �� ������ �����Ͻðڽ��ϱ�?(Y/N): ");
		while (getchar() != '\n') {}
		scanf("%c", &yesno);
		
		if (yesno == 'Y') {
			for (i = deletenum; i <= countnum; i++) {
				studentnum[i - 1] = studentnum[i];
				math[i - 1] = math[i];
				physics[i - 1] = physics[i];
				programing[i - 1] = programing[i];
				sum[i - 1] = sum[i];
				average[i - 1] = average[i];
			}
			countnum--;
			//�迭�� ����� ���� �ϳ��� �մ���, ���� �Էµ� �л� ���� 1 ���ҽ�Ų��.
			return 1; //������ �� 1�� �����Ѵ�.
		}
		else if (yesno == 'N') {
			printf("\n�ȳ�: �������� �ʽ��ϴ�.\n");
			return 0; 
		}
	}
	else if (deletenum > countnum && deletenum <= totalstudent) {
		printf("\n�ȳ�: �ش� No�� �����Ͱ� �����ϴ�.\n");
		//���� ���� ����� ���� �� ���� ���� �ִ� �Է� ������ ����� ������ ū ���� �Է� �޾����� ���� ���� �ʴ´�.
		return 0;
	}
	else if(deletenum>totalstudent){
		printf("\n�ȳ�: �ִ� �л� ��%d�� �ʰ��ϴ� No�Դϴ�.\n", totalstudent);
		
		return 0;
	}
	else {
		printf("\n�ȳ�: ��ȿ���� ���� No. �Դϴ�.\n");

		return 0;
	}
}