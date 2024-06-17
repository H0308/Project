#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "employee.h"

// 系统主菜单
void menu()
{
	printf("*****************************\n");
	printf("******员工信息管理系统*******\n");
	printf("*1. 输入员工信息\n");
	printf("*2. 查找员工\n");
	printf("*3. 修改员工\n");
	printf("*4. 插入员工\n");
	printf("*5. 删除员工\n");
	printf("*6. 排序输出员工信息\n");
	printf("*7. 查看所有员工信息\n");
	printf("*8. 退出系统\n");
	printf("*****************************\n");
}

// 导入数据
// 加载上一次的数据
void LoadEmployee(SL* employees) 
{
	FILE* pf = fopen("employees.txt", "rb"); 
	if (pf == NULL) 
	{
		perror("fopen error!\n"); 
		return;
	}
	employee tmp;
	while (fread(&tmp, sizeof(employee), 1, pf))
	{
		SLPushBack(employees, tmp);
	}
	fclose(pf);
	printf("成功导入历史数据\n");
}

int GetMonthDays(int year, int month)
{
	int monthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
	{
		return monthDays[month] + 1;
	}
	return monthDays[month];
}

// 获取输入
void employeeInfoGet(SL* employees)
{
	int num = 0;
	printf("请输入员工个数：");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		employee tmp;
		printf("请输入第%d个员工\n", i + 1);
		printf("请输入员工id：");
		scanf("%d", &(tmp.id));
		printf("请输入姓名：");
		scanf("%s", tmp.name);
		printf("请输入员工性别：");
		scanf("%s", tmp.gender);
		printf("请按照年月日的顺序以空格间隔输入员工生日：");
	setBirth:
		scanf("%d%*c%d%*c%d", &(tmp.birthday.year),
							&(tmp.birthday.month),
							&(tmp.birthday.day));
		if (tmp.birthday.month < 1 || tmp.birthday.month > 12 ||
			(tmp.birthday.day < 1 ||
			tmp.birthday.day > GetMonthDays(tmp.birthday.year, tmp.birthday.month)))
		{
			printf("请重新输入生日\n");
			goto setBirth;
		}
		printf("请输入员工学历：");
		scanf("%s", tmp.qualification);
		printf("请输入员工职业：");
		scanf("%s", tmp.job);
		printf("请输入员工电话：");
		scanf("%s", tmp.teleNum);
		printf("请输入员工的住址：");
		scanf("%s", tmp.location);
		SLPushBack(employees, tmp);
	}
}

// 查找方式菜单
void menuForFind()
{
	printf("**************\n");
	printf("*1. 员工id\n");
	printf("*2. 员工姓名\n");
	printf("*3. 退出查找\n");
	printf("**************\n");
}

// 按照id查找
int findBy_id(SL* employees, int target)
{
	for (int i = 0; i < employees->size; i++)
	{
		if (employees->SeqList[i].id == target)
		{
			return i;// 返回对应位置下标
		}
	}
	return -1;
}

// 按照名字查找
int findBy_name(SL* employees, char* target)
{
	for (int i = 0; i < employees->size; i++)
	{
		if (strcmp(employees->SeqList[i].name, target) == 0)
		{
			return i;// 返回对应位置下标
		}
	}
	return -1;
}

// 查找员工——返回下标
int findEmployee(SL* employees)
{
	int choice = 0;
	int pos = 0;
	menuForFind();
	printf("请选择查找方式：");
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
		{
			int target = 0;
			printf("请输入需要查找的员工id：");
			scanf("%d", &target);
			pos = findBy_id(employees, target);
			return pos;
		}
		break;
		case 2:
		{
			char name[50] = { 0 };
			printf("请输入需要查找的员工姓名：");
			scanf("%s", name);
			pos = findBy_name(employees, name);
			return pos;
		}
		break;
		case 3:
			return -1;
		default:
			menuForFind();
			printf("请重新按照菜单输入：");
			break;
		}
		menuForFind();
		printf("请选择查找方式：");
	}
	return -1;
}

// 查找并打印员工信息
void findEmployee_print(SL* employees)
{
	// 调用findEmployee函数
	int pos = findEmployee(employees);
	if (pos != -1)
	{
		printf("\t员工id：%d", employees->SeqList[pos].id);
		printf("\t姓名：%s", employees->SeqList[pos].name);
		printf("\t性别：%s", employees->SeqList[pos].gender);
		printf("\t生日：%d-%02d-%02d\n", employees->SeqList[pos].birthday.year,
			employees->SeqList[pos].birthday.month,
			employees->SeqList[pos].birthday.day);
		printf("\t学历：%s", employees->SeqList[pos].qualification);
		printf("\t职业：%s", employees->SeqList[pos].job);
		printf("\t电话：%s", employees->SeqList[pos].teleNum);
		printf("\t地址：%s\n", employees->SeqList[pos].location);
	}
	else
	{
		printf("查无此人\n");
	}
}

// 修改菜单
void menuForModify()
{
	printf("***修改内容*****\n");
	printf("*1. 员工id\n");
	printf("*2. 姓名\n");
	printf("*3. 性别\n");
	printf("*4. 生日\n");
	printf("*5. 学历\n");
	printf("*6. 职业\n");
	printf("*7. 电话\n");
	printf("*8. 地址\n");
	printf("*9. 退出修改\n");
	printf("**************\n");
}

// 生日菜单
//void menuForBirthday()
//{
//	printf("**************\n");
//	printf("*1. 年\n");
//	printf("*2. 月\n");
//	printf("*3. 日\n");
//	printf("*4. 退出修改\n");
//	printf("**************\n");
//}

// 修改员工
void modifyEmployee(SL* employees)
{
	// 调用查找函数找出需要修改的员工
	int pos = findEmployee(employees);
	if (pos == -1)
	{
		printf("查无此人\n");
		pos = findEmployee(employees);
	}
	int choice = 0;
	menuForModify();
	printf("请选择需要修改的内容：");
	while (scanf(" %d", &choice))
	{
		switch (choice)
		{
		case 1:
			printf("请输入需要修改的id：");
			scanf("%d", &(employees->SeqList[pos].id));
			printf("修改完成\n");
			break;
		case 2:
			printf("请输入需要修改的姓名：");
			scanf("%s", employees->SeqList[pos].name);
			printf("修改完成\n");
			break;
		case 3:
			printf("请输入需要修改的性别：");
			scanf("%s", employees->SeqList[pos].gender);
			printf("修改完成\n");
			break;
		case 4:
		{
			/*int ret = 0;
			menuForBirthday();
			printf("请选择生日中需要修改的字段：");
			while (scanf("%d", &ret))
			{
				switch (ret)
				{
				case 1:
					printf("请输入需要修改的年：");
				setYear:
					scanf("%d", &(employees->SeqList[pos].birthday.year));
					if (employees->SeqList[pos].birthday.year < 0)
					{
						printf("年份不合法，请重新输入需要修改的年份：\n");
						goto setYear;
					}
					
					printf("修改完成\n");
					break;
				case 2:
					printf("请输入需要修改的月：");
				setMonth:
					scanf("%d", &(employees->SeqList[pos].birthday.month));
					if (employees->SeqList[pos].birthday.month < 1 ||
						employees->SeqList[pos].birthday.month > 12)
					{
						printf("月份不合法，请重新输入月份：\n");
						goto setMonth;
					}
					printf("修改完成\n");
					break;
				case 3:
					printf("请输入需要修改的日：");
				setDay:
					scanf("%d", &(employees->SeqList[pos].birthday.day));
					if (employees->SeqList[pos].birthday.month < 1 ||
						employees->SeqList[pos].birthday.month > 12 ||
						(employees->SeqList[pos].birthday.day < 1 ||
							employees->SeqList[pos].birthday.day >
							GetMonthDays(employees->SeqList[pos].birthday.year,
								employees->SeqList[pos].birthday.month)))
					{
						printf("日不合法，请重新输入日：\n");
						goto setDay;
					}
					printf("修改完成\n");
					break;
				case 4:
					goto choose;
				default:
					printf("请重新按照菜单选择\n");
					break;
				}
				menuForBirthday();
				printf("请选择生日中需要修改的字段：");
			}*/
			modifyBirth:
			printf("请输入修改后的年月日，以空格间隔：");
			scanf("%d%*c%d%*c%d", &(employees->SeqList[pos].birthday.year),
				&(employees->SeqList[pos].birthday.month),
				&(employees->SeqList[pos].birthday.day));
			if (employees->SeqList[pos].birthday.month < 1 || 
				employees->SeqList[pos].birthday.month > 12 ||
				(employees->SeqList[pos].birthday.day < 1 ||
					employees->SeqList[pos].birthday.day > 
					GetMonthDays(employees->SeqList[pos].birthday.year, 
						employees->SeqList[pos].birthday.month)))
			{
				printf("日期不合法，请重新输入生日\n");
				goto modifyBirth;
			}
		}
			printf("修改完成\n");
			break;
		case 5:
			printf("请输入需要修改的学历：");
			scanf("%s", employees->SeqList[pos].qualification);
			printf("修改完成\n");
			break;
		case 6:
			printf("请输入需要修改的职业：");
			scanf("%s", employees->SeqList[pos].job);
			printf("修改完成\n");
			break;
		case 7:
			printf("请输入需要修改的电话：");
			scanf("%s", employees->SeqList[pos].teleNum);
			printf("修改完成\n");
			break;
		case 8:
			printf("请输入需要修改的地址：");
			scanf("%s", employees->SeqList[pos].location);
			printf("修改完成\n");
			break;
		case 9:
			return;
		default:
			printf("请重新选择\n");
			break;
		}
		menuForModify();
		printf("请选择需要修改的内容：");
	}
}

// 插入数据
void insertEmployee(SL* employees)
{
	// 复用输入函数
	employeeInfoGet(employees);
}

// 删除员工
void deleteEmployee(SL* employees)
{
	// 调用查找函数
	int pos = findEmployee(employees);
	if (pos < 0)
	{
		printf("查无此人，删除失败");
	}
	SLErase(employees, pos);
	printf("删除完成\n");
}

// 排序菜单
void menuForSort()
{
	printf("**************\n");
	printf("*1. 员工id\n");
	printf("*2. 员工姓名\n");
	printf("*3. 员工生日\n");
	printf("*4. 退出排序\n");
	printf("**************\n");
}

// 按照id排序
int cmp_id(const void* p1, const void* p2)
{
	return ((employee*)p1)->id - ((employee*)p2)->id;
}

// 名字比较
int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((employee*)p1)->name, ((employee*)p2)->name);
}

// 日期比较
int birthdayCmp(const void* p1, const void* p2)
{
	//如果年大就直接返回1
	if (((employee*)p1)->birthday.year > ((employee*)p2)->birthday.year)
	{
		return 1;
	}
	else if (((employee*)p1)->birthday.year == ((employee*)p2)->birthday.year &&
		((employee*)p1)->birthday.month > ((employee*)p2)->birthday.month)//年相等时比较月份，月份大就直接返回true
	{
		return 1;
	}
	else if (((employee*)p1)->birthday.year == ((employee*)p2)->birthday.year &&
		((employee*)p1)->birthday.month == ((employee*)p2)->birthday.month && ((employee*)p1)->birthday.day > ((employee*)p2)->birthday.day)//年相等，月份相等时，天大就直接返回true
	{
		return 1;
	}
	else//其他情况均返回-1
	{
		return -1;
	}
}

// 打印排序后的内容
void printSortedEmp(employee* tmp, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("第%d名员工:\n", i + 1);
		printf("\t员工id：%d", tmp[i].id);
		printf("\t姓名：%s", tmp[i].name);
		printf("\t性别：%s", tmp[i].gender);
		printf("\t生日：%d-%02d-%02d\n", tmp[i].birthday.year,
			tmp[i].birthday.month,
			tmp[i].birthday.day);
		printf("\t学历：%s", tmp[i].qualification);
		printf("\t职业：%s", tmp[i].job);
		printf("\t电话：%s", tmp[i].teleNum);
		printf("\t地址：%s\n", tmp[i].location);
	}
}

// 排序主体
#if 0
void sortEmployees(SL* employees)
{
	int choice = 0;
	//employee* tmp;
	//int size = employees->size;
	//tmp = (employee*)malloc(sizeof(employee) * size);
	//assert(tmp);
	//memcpy(tmp, employees->SeqList, sizeof(employee) * size);
	menuForSort();
	printf("请选择需要排序的字段：");
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
			qsort(employees->SeqList, employees->size, sizeof(employee), cmp_id);
			printSortedEmp(employees->SeqList, employees->size);
			break;
		case 2:
			qsort(employees->SeqList, employees->size, sizeof(employee), cmp_name);
			printSortedEmp(employees->SeqList, employees->size);
			break;
		case 3:
			qsort(employees->SeqList, employees->size, sizeof(employee), birthdayCmp);
			printSortedEmp(employees->SeqList, employees->size);
			break;
		case 4:
			return;
		default:
			menuForSort();
			printf("请重新按照菜单输入：");
			break;
		}
		menuForSort();
		printf("请选择需要排序的字段：");
	}
}
#endif
// 转移表优化
void sortEmployees(SL* employees)
{
	int choice = 0;
	//employee* tmp;
	//int size = employees->size;
	//tmp = (employee*)malloc(sizeof(employee) * size);
	//assert(tmp);
	//memcpy(tmp, employees->SeqList, sizeof(employee) * size);
	menuForSort();
	printf("请选择需要排序的字段：");
	// 定义函数指针数组
	int (*cmp[4])(const void*, const void*) = {0, cmp_id, cmp_name, birthdayCmp};
	//cmp arr[4] = {0, cmp_id, cmp_name, birthdayCmp};
	while (scanf("%d", &choice))
	{
		if (choice >= 1 && choice <= 3)
		{
			qsort(employees->SeqList, employees->size, sizeof(employee), cmp[choice]);
			printSortedEmp(employees->SeqList, employees->size);
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			menuForSort();
			printf("请重新输入：");
		}
		menuForSort();
		printf("请选择需要排序的字段：");
	}
}

// 向文件中写入数据
void writeIntoFile(SL* employees)
{
	FILE* pf = fopen("employees.txt", "wb"); 
	if (pf == NULL) 
	{
		perror("fopen error!\n"); 
		return;
	}
	//将通讯录数据写⼊⽂件
	for (int i = 0; i < employees->size; i++)
	{
		fwrite(employees->SeqList + i, sizeof(employee), 1, pf);
	}
	fclose(pf);
	printf("数据保存成功！\n");
}

// 员工信息销毁函数
void destroyEmployee(SL* employees)
{
	char ans = 0;
	printf("是否需要保存数据：y/n");
	scanf(" %c", &ans);
	if (ans == 'y')
	{
		writeIntoFile(employees);
	}
	SLDestroy(employees);
}

// 打印所有员工信息
void printEmployees(SL* employees)
{
	// 没有员工直接返回
	if (employees->size == 0)
	{
		printf("暂无数据\n");
		return;
	}
	for (int i = 0; i < employees->size; i++)
	{
		printf("第%d名员工:\n", i + 1);
		printf("\t员工id：%d", employees->SeqList[i].id);
		printf("\t姓名：%s", employees->SeqList[i].name);
		printf("\t性别：%s", employees->SeqList[i].gender);
		printf("\t生日：%d-%02d-%02d\n", employees->SeqList[i].birthday.year,
			employees->SeqList[i].birthday.month,
			employees->SeqList[i].birthday.day);
		printf("\t学历：%s", employees->SeqList[i].qualification);
		printf("\t职业：%s", employees->SeqList[i].job);
		printf("\t电话：%s", employees->SeqList[i].teleNum);
		printf("\t地址：%s\n", employees->SeqList[i].location);
	}
}