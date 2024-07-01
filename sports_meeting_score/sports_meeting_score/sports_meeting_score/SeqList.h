#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct event event;
// 存储结构定义
typedef event SLDataType;
typedef struct SeqList_dynamic
{
	SLDataType* SeqList;//指向可以修改大小的数据空间
	int size;//有效数据个数
	int capacity;//数据空间的总大小
}SL;

//动态顺序表的实现
//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);
//顺序表的扩容 
void SLCheckCapacity(SL* ps);
//顺序表的头部插⼊删除 / 尾部插⼊删除 
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
//顺序表指定位置之前插⼊/删除数据 
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

