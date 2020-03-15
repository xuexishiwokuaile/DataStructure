#include<iostream>
#define MaxSize 8
#define MaxSons 3
using namespace std;

typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];
typedef struct
{
	ElemType data;
	int parent;
}PTree[MaxSize];

typedef struct node
{
	ElemType data;
	struct node * sons[MaxSons];
}TSonNode;

typedef struct tnode
{
	ElemType data;
	struct tnode * hp;      //兄弟结点
	struct tnode * vp;      //孩子结点
}TSBNode;

typedef struct node
{
	ElemType data;
	struct node * lchild;          //左孩子
	struct node * rchild;          //右孩子
}BTNode;

typedef struct
{
	BTNode * data[MaxSize];
	int top;
}SqStack;

int TreeHeight1(TSonNode * t)
{
	TSonNode * p;
	int i, h, maxh = 0;
	if (t == NULL)	return 0;
	else
	{
		for (int i = 0; i < MaxSons; i++)
		{
			p = t->sons[i];
			if (p != NULL)
			{
				h = TreeHeight1(p);
				if (maxh < h)	maxh = h;
			}
		}
		return(maxh + 1);
	}
}

int TreeHeight2(TSBNode * t)
{
	TSBNode * p;
	int h, maxh = 0;
	if (t == NULL)	return 0;
	else
	{
		p = t->vp;
		while (p != NULL)
		{
			h = TreeHeight2(p);
			if (maxh < h)	maxh = h;
			p = p->hp;
		}
		return(maxh + 1);
	}
}

void CreateBTree(BTNode * &b, char * str)
{
	BTNode * St[MaxSize], *p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case'(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case')':
			
		}
	}
}

void PreOrder(BTNode * b)                       //先序遍历
{
	if (b != NULL)
	{
		cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BTNode * b)                        //中序遍历
{
	if (b != NULL)
	{
		InOrder(b->lchild);
		cout << b->data;
		InOrder(b->rchild);
	}
}

void PostOrder(BTNode * b)                      //后序遍历
{
	if (b != NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data;
	}
}

int Nodes(BTNode * b)                           //求结点个数
{
	if (b == NULL)
		return 0;
	else
	{
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
	}
}

void DispLeaf(BTNode * b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			cout << b->data;
		DispLeaf(b->lchild);
		DispLeaf(b->rchild);
	}
}

void DispLeaf1(BTNode * b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			cout << b->data;
		DispLeaf1(b->rchild);
		DispLeaf1(b->lchild);
	}
}

int Level(BTNode * b, ElemType x, int h)      //例7.13
{
	int l;
	if (b == NULL)
		return (0);
	else if (b->data == x)
		return(h);
	else
	{
		l = Level(b->lchild, x, h + 1);
		if (l != 0)
			return(l);
		else
			return(Level(b->rchild, x, h + 1));
	}
}

void Lnodenum(BTNode * b, int h, int k, int &n)        //例7.14
{
	if (b == NULL)
		return;
	else
	{
		if (h == k)	n++;
		else if (h < k)
		{
			Lnodenum(b->lchild, h + 1, k, n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}

bool Like(BTNode * b1, BTNode * b2)
{
	bool like1, like2;
	if (b1 == NULL && b2 == NULL)
		return true;
	else if (b1 == NULL || b2 = NULL)
		return false;
	else
	{
		like1 = Like(b1->lchild, b2->lchild);
		like2 = Like(b1->rchild, b2->rchild);
		return(like1&&like2);
	}
}

bool ancestor(BTNode * b, ElemType x)                   //例7.16
{
	if (b == NULL)
		return false;
	else if (b->lchild != NULL && b->lchild->data == x|| b->rchild != NULL && b->rchild->data == x)
	{
		cout << b->data;
		return true;
	}
	else if (ancestor(b->lchild, x) || ancestor(b->rchild, x))
	{
		cout << b->data;
	}
	else return false;
}

void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack *&s)
{
	free(s);
}

bool StackEmpty(SqStack * s)
{
	return(s->top == -1);
}

bool Push(SqStack *&s, BTNode* e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, BTNode* &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

void PreOrder1(BTNode * b)            //先序遍历非递归算法
{
	BTNode * p;
	SqStack * st;
	InitStack(st);
	if (b != NULL)
	{
		Push(st, b);
		while (!StackEmpty(st))
		{
			Pop(st, b);
			cout << p->data;
			if (p->rchild != NULL)
				Push(st, p->rchild);
			if (p->lchild != NULL)
				Push(st, p->lchild);
		}
	}
	cout << endl;
}

void PreOrder2(BTNode * b)
{
	BTNode * p;
	SqStack * st;
	InitStack(st);
	p = b;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{
			cout << p->data;
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			p = p->rchild;
		}
	}
	cout << endl;
	DestroyStack(st);
}

void InOrder1(BTNode * b)
{
	BTNode * p;
	SqStack * st;
	InitStack(st);
	p = b;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			cout << p->data;
			p = p->rchild;
		}
	}
	cout << endl;
	DestroyStack(st);
}