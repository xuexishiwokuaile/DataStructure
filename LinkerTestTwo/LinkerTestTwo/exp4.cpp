#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreateListF(LinkNode *&L, ElemType a[], int n)
{
	LinkNode *s;
	int i;
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
	s = L->next;
	while (s->next != NULL)
		s = s->next;
	s->next = L;
}

void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	LinkNode *s, *r; int i;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
	s = L->next;
}

void InitList(LinkNode *&L)
{
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = L;                   //指向自己
}

void DestroyList(LinkNode *&L)
{
	LinkNode *pre = L, *p = pre->next;
	while (p != L)
	{
		free(pre);
	}
}

bool ListEmpty(LinkNode *L)
{
	return(L->next == L);
}

int ListLength(LinkNode *L)
{
	LinkNode *p = L; int i = 0;
	while ()
}