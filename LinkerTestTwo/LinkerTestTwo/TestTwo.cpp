#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;       //指向后继节点
}LinkNode;

typedef struct DNode
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DLinkNode;

void CreateListF(LinkNode *&L, ElemType a[], int n)                //头插法
{
	LinkNode *s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateLinkR(LinkNode *&L, ElemType a[],int n)                       //尾插法
{
	LinkNode *s, *r;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void DestroyList(LinkNode *&L)                //销毁
{
	LinkNode *pre = L, *p = L->next;
	while (p != NULL)
	{
		free(pre);             //先销毁
		pre = p;
		p = pre->next;
	}
	free(pre);
}

int ListLength(LinkNode *L)                  //求长度
{
	int n = 0;
	LinkNode *p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

void DispList(LinkNode *L)
{
	LinkNode *p = L->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L;
	if (i <= 0)	return false;             //检测是否存在第i个元素
	while (j < i&&p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}

int LocateElem(LinkNode *L, ElemType e)
{
	int i = 1;
	LinkNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

bool ListInsert(LinkNode *&L, int i, ElemType e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0)	return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L, *q;
	if (i <= 0)	return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		q = p->next;
		if (q == NULL)
		{
			return false;
		}
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}

//void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2)
//{
//	LinkNode *p = L->next, *q, *r1;
//	L1 = L;
//	r1 = L1;
//	L2 = (LinkNode *)malloc(sizeof(LinkNode));
//}

void CreateListF(DLinkNode *&L, ElemType a[], int n)                   //头插法
{
	DLinkNode *s;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void CreateListR(DLinkNode *&L, ElemType a[], int n)                         //尾插法
{
	DLinkNode *s, *r;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s; s->prior = r;
		r = s;
	}
	r->next = NULL;
}
