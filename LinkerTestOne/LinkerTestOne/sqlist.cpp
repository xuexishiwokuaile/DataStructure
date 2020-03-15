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

void CreateList(SqList *&L, ElemType a[], int n)         //���彨��˳���
{
	L = (SqList *)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

void InitList(SqList *&L)       //��ʼ�����Ա�
{
	L = (SqList *)malloc(sizeof(SqList));            //���������Ա�Ŀռ�
	L->length = 0;
}

void DestroyList(SqList *&L)                 //�������Ա�
{
	free(L);
}

bool ListEmpty(SqList *L)              //�ж����Ա��Ƿ�Ϊ�ձ�
{
	return(L->length == 0);
}

int ListLength(SqList *L)              //�����Ա�ĳ���
{
	return(L->length);
}

void DispList(SqList *L)               //������Ա�
{
	for (int i = 0; i < L->length; i++)
	{
		std::cout << L->data[i];
	}
	std::cout << std::endl;
}

bool GetElem(SqList *L, int i, ElemType &e)          //�����Ա��е�i��Ԫ��ֵ
{
	if (i<1 || i>L->length)
	{
		return false;
	}
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList *L, ElemType e)                  //���ҵ�һ��ֵ��Ϊe��Ԫ�ط���
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e)          //�����i��Ԫ��
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
	return true;              //��֤һ��
}

bool ListDelete(SqList *&L, int i, ElemType &e)        //ɾ����i��Ԫ��
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