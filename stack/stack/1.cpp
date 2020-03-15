#include<iostream>
#define MaxSize 5
using namespace std;

typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct
{
	double data[MaxSize];
	int top;
}SqStack1;

typedef struct
{
	ElemType data[MaxSize];
	int top1, top2;
}DStack;                       //共享栈

typedef struct linknode
{
	ElemType data;
	struct linknode * next;
}LinkStNode;                   //链栈

typedef struct
{
	int i;
	int j;
	int di;                    //下一个相邻可走方位的方位号
}Box;

typedef struct
{
	Box data[MaxSize];
	int top; 
}StType;

void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack *&s)
{
	free(s);
}

bool StackEmpty(SqStack *s)
{
	return(s->top == -1);
}

bool Push(SqStack *&s, ElemType e)                   //进栈
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, ElemType &e)                    //出栈
{
	if (s->top = -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *s, ElemType &e)                   //取栈顶元素
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

bool symmetry(ElemType str[])                 //例3.4
{
	int i; ElemType e;
	SqStack *st;
	InitStack(st);                   //初始化
	for (i = 0; str[i] != '\0'; i++)
		Push(st, str[i]);
	for (i = 0; str[i] != '\0'; i++)
	{
		Pop(st, e);
		if (str[i] != e)
		{
			DestroyStack(st);
			return false;
		}
	}
	DestroyStack(st);
	return true;
}

void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestroyStack(LinkStNode *&s)
{
	LinkStNode *pre = s, *p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(p);
}

bool StackEmpty(LinkStNode *s)
{
	return(s->next = NULL);
}

void Push(LinkStNode *&s,ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;                        //头插法
}

bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)
		return false;                    //空栈
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

bool Match(char exp[], int n)                   //例3.5(***)
{
	int i = 0; char e;
	bool match = true;
	LinkStNode * st;
	InitStack(st);
	while (i < n&&match)
	{
		if (exp[i] == '(')
			Push(st, exp[i]);
		else if (exp[i] == ')')
		{
			if (GetTop(st,e) == true)
			{
				if (e != '(')
					match = false;
				else
					Pop(st, e);
			}
			else match = false;             //无法取栈顶元素
		}
		i++;
	}
	if (!StackEmpty(st))                    //扫描完之后栈非空
		match = false;               
	DestroyStack(st);
	return match;
}

void trans(char *exp, char postexp[])
{
	char e;
	SqStack *Optr;
	InitStack(Optr);
	int i = 0;
	while (*exp != '\0')
	{
		switch (*exp)
		{
		case'(':
			Push(Optr, '(');                    //( 直接进栈
			exp++;
			break;
		case')':
			Pop(Optr, e);
			while (e != '(')
			{
				postexp[i++] = e;
				Pop(Optr, e);
			}
			exp++;
			break;
		case'+':
		case'-':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e != '(')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else
					break;
			}
			Push(Optr, *exp);
			exp++;
			break;
		case'*':
		case'/':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e == '*' || e == '/')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else
					break;
			}
			Push(Optr, *exp);
			exp++;
			break;
		default:                                       //处理数字字符
			while (*exp >= '0'&&*exp <= '9')
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';
		}
	}
	while (!StackEmpty(Optr))
	{
		Pop(Optr, e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';
	DestroyStack(Optr);
}

void InitStack1(SqStack1 *&s)
{
	s = (SqStack1 *)malloc(sizeof(SqStack1));
	s->top = -1;
}

bool Pop1(SqStack1 *&s, double &e)                    //出栈
{
	if (s->top = -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool Push1(SqStack1 *&s, double e)                   //进栈
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool GetTop1(SqStack1 *s, double &e)                   //取栈顶元素
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

void DestroyStack1(SqStack1 *&s)
{
	free(s);
}

double compvalue(char *postexp)
{
	double d, a, b, c, e;
	SqStack1 * Opnd;
	InitStack1(Opnd);
	while (*postexp != '\0')
	{
		switch (*postexp)
		{
		case'+':
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b + a;
			Push1(Opnd, c);
			break;
		case'-':
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b - a;
			Push1(Opnd, c);
			break;
		case'*':
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b * a;
			Push1(Opnd, c);
			break;
		case'/':
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				Push1(Opnd, c);
				break;
			}
			else
			{
				printf("\n\t除零错误！\n");
				exit(0);
			}
			break;
		default:                                      //处理数字字符
			d = 0;
			while (*postexp >= '0'&&*postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push1(Opnd, d);
			break;
		}
		postexp++;
	}
	GetTop1(Opnd, e);
	DestroyStack1(Opnd);
	return e;
}

const int M = 8;
const int N = 8;
int mg[M + 2][N + 2] =
{
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};

void InitStack(StType *&s)
{
	s = (StType *)malloc(sizeof(StType));
	s->top = -1;
}

bool Pop(StType *&s, Box &e)                    //出栈
{
	if (s->top = -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool Push(StType *&s, Box e)                   //进栈
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool GetTop(StType *s, Box &e)                   //取栈顶元素
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

void DestroyStack(StType *&s)
{
	free(s);
}

bool StackEmpty(StType *s)
{
	return(s->top == -1);
}

bool mgpath(int xi, int yi, int xe, int ye)                //入口、出口
{
	Box path[MaxSize], e;
	int i, j, di, i1, j1, k;
	bool find;
	StType * st;
	InitStack(st);
	e.i = xi; e.j = yi; e.di = -1;                         //设置e为入口
	Push(st, e);
	mg[xi][yi] = -1;
	while (!StackEmpty(st))
	{
		GetTop(st, e);
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye)                           //找到了出口
		{
			printf("一条迷宫的路径如下：\n");
			k = 0;
			while (!StackEmpty(st))
			{
				Pop(st, e);
				path[k++] = e;
			}
			DestroyStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find)                   //检测相邻方块
		{
			di++;
			switch (di)
			{
			case 0:
				i1 = i - 1;
				j1 = j;
				break;
			case 1:
				i1 = i;
				j1 = j + 1;
				break;
			case 2:
				i1 = i + 1;
				j1 = j;
				break;
			case 3:
				i1 = i;
				j1 = j - 1;
				break;
			}
			if (mg[i1][j1] == 0)
				find = true;
		}
		if (find)
		{
			st->data[st->top].di = di;               //修改原栈顶元素的di值
			e.i = i1; e.j = j1; e.di = -1;
			Push(st, e);
			mg[i1][j1] = -1;
		}
		else
		{
			Pop(st, e);                              //栈顶元素退栈
			mg[e.i][e.j] = 0;                        //退栈方块变为其他路径可走方块
		}
	}
	DestroyStack(st);
	return false;
}