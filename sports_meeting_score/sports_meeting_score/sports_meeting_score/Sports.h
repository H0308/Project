#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 设置变量阈值
#define Max_school 20 // 学校最大个数
#define Max_maleEvent 20 // 男子项目最大个数
#define max_femaleEvent 20 // 女子项目最大个数

// 学校结构设计
typedef struct school
{
	int sch_id; // 学校编号
	char sch_name[50]; // 学校名称
	int totalScore; // 学校总成绩
}school;

// 活动设计
typedef struct event
{
	int event_id; // 活动编号
	char event_name[50]; // 活动名称
	int* score; // 记录每个学校的总分
}event;

// 项目功能

// 初始化
void SportsMeetingInit(int* school_num, int* male_event, int* female_event, 
	school** schools, SL* events);

