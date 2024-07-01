#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "Sports.h"

// 项目功能实现
// 初始化
void SportsMeetingInit(int* school_num, int* male_event, int* female_event, 
	school** schools, SL* events)
{
	// 确定个数
	printf("请按照顺序输入学校个数、运动会男子项目个数和女子项目个数：");
	scanf("%d%*c%d%*c%d", school_num, male_event, female_event);

	//为学校开辟空间
	*schools = (school*)malloc(sizeof(school) * (*school_num));

	// 插入学校
	for (int i = 0; i < (*school_num); i++)
	{
		printf("请输入学校id和学校名称：");
		scanf("%d%*c%s", &((*schools)[i].sch_id), (*schools)[i].sch_name);
	}

	// 初始化运动会项目
	SLInit(events);
	// 插入项目
	for (int i = 0; i < (*male_event); i++)
	{
		printf("请输入男生项目id和项目名称：");
		event* tmp = (event*)malloc(sizeof(event));
		scanf("%d%*c%s", &(tmp->event_id), &(tmp->event_name));
		SLPushBack(events, (*tmp));
	}
	for (int i = (*male_event); i < ((*male_event) + (*female_event)); i++)
	{
		printf("请输入女生项目id和项目名称：");
		event* tmp = (event*)malloc(sizeof(event));
		scanf("%d%*c%s", &(tmp->event_id), &(tmp->event_name));
		SLPushBack(events, (*tmp));
	}
}

