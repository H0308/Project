#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "Sports.h"

void menu()
{
	printf("*************************************\n");
	printf("***********运动会分数统计************\n");
	printf("*1. 输入信息 2.所有项目的前三/前五名*\n");
	printf("*3. 指定项目的前三/前五名 4.查询学校*\n");
	printf("*************************************\n");
	printf("*按数字5或者非数字字符保存数据并退出*\n");
}

int main()
{
	menu();
	int choice = 0;
	int school_num = 0, male_event = 0, female_event = 0;// 数量信息
	school* schools = NULL;
	SL events;
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
			//初始化
			SportsMeetingInit(&school_num, &male_event, &female_event, &schools, &events);
			break;
		case 2:
			printf("所有项目的前三/前五名\n");
			break;
		case 3:
			printf("指定项目的前三/前五名\n");
			break;
		case 4:
			printf("查询学校\n");
			break;
		case 5:
			printf("退出程序\n");
			SLDestroy(&events);
			free(schools);
			return 1;
			break;
		default:
			printf("请按照菜单重新选择\n");
			break;
		}
	}

	return 0;
}