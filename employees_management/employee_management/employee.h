#pragma once

#include "SeqList.h"

typedef struct SeqList_dynamic SL;

typedef struct birthday
{
	int year;
	int month;
	int day;
}birthday;

typedef struct employee
{
	int id;
	char name[50];
	char gender[10];
	birthday birthday;
	char qualification[20];
	char job[30];
	char teleNum[15];
	char location[50];
}employee;

// 程序菜单
void menu();

// 导入数据
void LoadEmployee(SL* employees);

// 初始化——输入
void employeeInfoGet(SL* employees);

// 查找员工
// 查找方式菜单
void menuForFind();
// 查找员工——返回下标
int findEmployee(SL* employees);
// 查找员工——显示对应员工信息
void findEmployee_print(SL* employees);

// 修改菜单
void menuForModify();
// 修改员工信息
void modifyEmployee(SL* employees);

// 插入员工信息
void insertEmployee(SL* employees);

// 删除员工信息
void deleteEmployee(SL* employees);

// 排序菜单
void menuForSort();
// 按照指定内容排序
void sortEmployees(SL* employees);
// 打印排序后的内容
void printSortedEmp(employee* tmp, int size);

// 向文件中写入数据
void writeIntoFile(SL* employees);

// 销毁系统数据
void destroyEmployee(SL* employees);

// 打印所有员工信息
void printEmployees(SL* employees);
