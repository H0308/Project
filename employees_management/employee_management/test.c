#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "employee.h"

int main()
{
	SL employees;
	SLInit(&employees);
	char ans = 0;
	printf("是否需要导入上次的数据：y/n");
	scanf(" %c", &ans);
	if (ans == 'y')
	{
		LoadEmployee(&employees);
	}
	menu();
	printf("请输入选项：");
	int choice = 0;
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
			employeeInfoGet(&employees);
			break;
		case 2:
			find(&employees);
			break;		
		case 3:
			remedy(&employees);
			break;
		case 4:
			insertEmployee(&employees);
			break;
		case 5:
			deleteEmployee(&employees);
			break;
		case 6:
			sortEmployees(&employees);
			break;
		case 7:
			printEmployees(&employees);
			break;
		case 8:
			destroyEmployee(&employees);
			printf("谢谢使用");
			return 1;
			break;
		default:
			printf("请按照菜单重新输入：");
			break;
		}
		menu();
		printf("请输入选项：");
	}
}