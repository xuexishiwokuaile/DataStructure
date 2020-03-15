#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n)         //整体建立顺序表
{
	L = (SqList *)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

void InitList(SqList *&L)       //初始化线性表
{
	L = (SqList *)malloc(sizeof(SqList));            //分配存放线性表的空间
	L->length = 0;
}

void DestroyList(SqList *&L)                 //销毁线性表
{
	free(L);
}

bool ListEmpty(SqList *L)              //判断线性表是否为空表
{
	return(L->length == 0);
}

int ListLength(SqList *L)              //求线性表的长度
{
	return(L->length);
}

void DispList(SqList *L)               //输出线性表
{
	for (int i = 0; i < L->length; i++)
	{
		std::cout << L->data[i];
	}
	std::cout << std::endl;
}

bool GetElem(SqList *L, int i, ElemType &e)          //求线性表中第i个元素值
{
	if (i<1 || i>L->length)
	{
		return false;
	}
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList *L, ElemType e)                  //查找第一个值域为e的元素符号
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e)          //插入第i个元素
{
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;              //验证一下
}

bool ListDelete(SqList *&L, int i, ElemType &e)        //删除第i个元素
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}