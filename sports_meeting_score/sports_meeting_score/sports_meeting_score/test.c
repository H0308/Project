#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "Sports.h"

void menu()
{
	printf("*************************************\n");
	printf("***********�˶������ͳ��************\n");
	printf("*1. ������Ϣ 2.������Ŀ��ǰ��/ǰ����*\n");
	printf("*3. ָ����Ŀ��ǰ��/ǰ���� 4.��ѯѧУ*\n");
	printf("*************************************\n");
	printf("*������5���߷������ַ��������ݲ��˳�*\n");
}

int main()
{
	menu();
	int choice = 0;
	int school_num = 0, male_event = 0, female_event = 0;// ������Ϣ
	school* schools = NULL;
	SL events;
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
			//��ʼ��
			SportsMeetingInit(&school_num, &male_event, &female_event, &schools, &events);
			break;
		case 2:
			printf("������Ŀ��ǰ��/ǰ����\n");
			break;
		case 3:
			printf("ָ����Ŀ��ǰ��/ǰ����\n");
			break;
		case 4:
			printf("��ѯѧУ\n");
			break;
		case 5:
			printf("�˳�����\n");
			SLDestroy(&events);
			free(schools);
			return 1;
			break;
		default:
			printf("�밴�ղ˵�����ѡ��\n");
			break;
		}
	}

	return 0;
}