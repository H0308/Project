#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "Sports.h"

// ��Ŀ����ʵ��
// ��ʼ��
void SportsMeetingInit(int* school_num, int* male_event, int* female_event, 
	school** schools, SL* events)
{
	// ȷ������
	printf("�밴��˳������ѧУ�������˶���������Ŀ������Ů����Ŀ������");
	scanf("%d%*c%d%*c%d", school_num, male_event, female_event);

	//ΪѧУ���ٿռ�
	*schools = (school*)malloc(sizeof(school) * (*school_num));

	// ����ѧУ
	for (int i = 0; i < (*school_num); i++)
	{
		printf("������ѧУid��ѧУ���ƣ�");
		scanf("%d%*c%s", &((*schools)[i].sch_id), (*schools)[i].sch_name);
	}

	// ��ʼ���˶�����Ŀ
	SLInit(events);
	// ������Ŀ
	for (int i = 0; i < (*male_event); i++)
	{
		printf("������������Ŀid����Ŀ���ƣ�");
		event* tmp = (event*)malloc(sizeof(event));
		scanf("%d%*c%s", &(tmp->event_id), &(tmp->event_name));
		SLPushBack(events, (*tmp));
	}
	for (int i = (*male_event); i < ((*male_event) + (*female_event)); i++)
	{
		printf("������Ů����Ŀid����Ŀ���ƣ�");
		event* tmp = (event*)malloc(sizeof(event));
		scanf("%d%*c%s", &(tmp->event_id), &(tmp->event_name));
		SLPushBack(events, (*tmp));
	}
}

