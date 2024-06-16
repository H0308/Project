#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//顺序表的初始化
void SLInit(SL* ps)
{
	assert(ps);//确保没有传入空指针
	ps->SeqList = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表的销毁
void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->SeqList)
	{
		free(ps->SeqList);
	}

	ps->SeqList = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表的扩容 
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	SLDataType* temp = NULL;
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity;
		temp = (SLDataType*)realloc(ps->SeqList, (newCapacity = (ps->capacity == 0) ? 4 : (ps->capacity * 2)) * sizeof(SLDataType));//扩容规则：成倍数增加（一般1.5倍或2倍）
		assert(temp);
		ps->SeqList = temp;
		ps->capacity = newCapacity;
		temp = NULL;
	}
}

//顺序表的尾部插入
//当顺序表有足够的空间插入时（包括有内容和顺序表为空）
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	//顺序表的扩容 
	SLCheckCapacity(ps);//确保SeqList指针不为空之后判断容量是否足够

	//当顺序表有足够的空间插入时（包括有内容和顺序表为空）
	ps->SeqList[ps->size] = x;
	ps->size++;

}

//顺序表的头部插入
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	//顺序表的扩容
	SLCheckCapacity(ps);//确保SeqList指针不为空之后判断容量是否足够

	//顺序表有足够的空间插入时（包括有内容和顺序表为空）
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->SeqList[i + 1] = ps->SeqList[i];//ps->SeqList[0] = ps->SeqList[1]
	}
	ps->SeqList[0] = x;
	ps->size++;

}

//顺序表的尾部删除
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//确保顺序表内不为空
	ps->size--;
}

//顺序表的头部删除
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	for (int i = 0; i < ps->size - 1; i++)//注意此处是size - 1的位置，防止把多余的数据进行了挪动
	{
		ps->SeqList[i] = ps->SeqList[i + 1];
	}
	ps->size--;
}

//顺序表的指定位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(0 <= pos && pos >= ps->size);//确保pos为有效位置
	//顺序表的扩容
	SLCheckCapacity(ps);//确保SeqList指针不为空之后判断容量是否足够

	for (int i = ps->size - 1; i >= pos - 1; i--)
	{
		if (pos != ps->size)
		{
			ps->SeqList[i + 1] = ps->SeqList[i];
		}
	}
	ps->SeqList[pos - 1] = x;
	ps->size++;
}

//顺序表的指定位置删除
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(0 <= pos && pos <= ps->size);//确保pos为有效位置

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->SeqList[i - 1] = ps->SeqList[i];
	}
	ps->size--;
}
