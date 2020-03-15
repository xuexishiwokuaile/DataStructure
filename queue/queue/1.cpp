#include<iostream>
#define MaxSize 10
using namespace std;

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

typedef struct
{
	ElemType data[MaxSize];
	int front;
	int count;
}QuType;

typedef struct qnode
{
	ElemType data;
	struct qnode * next;
}DataNode;

typedef struct
{
	DataNode * front;
	DataNode * rear;
}LinkQuNode;

typedef struct node
{
	ElemType data;
	struct node * next;
}LinkNode;

void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *q)
{
	free(q);
}

bool QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
	if (q->front == MaxSize - 1)                      //����
		return false; 
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//���ζ���
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

void DestroyQueue(SqQueue *&q)
{
	free(q);
}

bool QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)             //����
		return false;
	q->rear = (q->rear + 1)&MaxSize;                     //ѭ����1
	q->data[q->rear] = e;
	return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

void InitQueue(QuType *&qu)
{
	qu = (QuType *)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}

bool EnQueue(QuType *&qu, ElemType x)
{
	int rear;
	if (qu->count == MaxSize)
		return false;
	else
	{
		rear = (qu->front + qu->count) % MaxSize;
		rear = (rear + 1) % MaxSize;
		qu->data[rear] = x;
		qu->count++;
		return true;
	}
}

bool DeQueue(QuType *&qu, ElemType &x)
{
	if (qu->count == 0)
		return false;
	else
	{
		qu->front = (qu->front + 1) % MaxSize;
		x = qu->data[qu->front];
		qu->count--;
		return true;
	}
}

bool QueueEmpty(QuType *qu)
{
	return(qu->count == 0);
}

void InitQueue(LinkQuNode *&q)
{
	q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestroyQueue(LinkQuNode *&q)
{
	DataNode * pre = q->front, *p;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(q);
}

bool QueueEmpty(LinkQuNode *q)
{
	return(q->rear = NULL);
}

bool enQueue(LinkQuNode *&q, ElemType e)
{
	DataNode * p;
	p = (DataNode *)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

bool deQueue(LinkQuNode *&q, ElemType &e)
{
	DataNode * t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}

void initQueue(LinkNode *&rear)
{
	rear == NULL;
}

void enQueue(LinkNode *&rear, ElemType e)
{
	LinkNode * p;
	p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = e;
	if (rear == NULL)
	{
		p->next = p;
		rear = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
}

bool deQueue(LinkNode *&rear, ElemType &e)
{
	LinkNode *t;
	if (rear == NULL)
		return false;
	else if (rear->next == rear)
	{
		e = rear->data;
		free(rear);
		rear = NULL;
	}
	else
	{
		t = rear->next;
		e = t->data;
		rear->next = t->next;
		free(t);
	}
	return true;
}

bool ququeEmpty(LinkNode * rear)
{
	return(rear == NULL);
}