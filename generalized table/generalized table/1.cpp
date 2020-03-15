#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct lnode
{
	int tag;
	union
	{
		ElemType data;
		struct lnode * sublist;          //二选一，内存只会存储一个
	}val;
	struct londe * link;
}GLNode;

void fun1(GLNode * g)
{
	GLNode * g1 = g->val.sublist;   //val.
	while (g1 != NULL)
	{
		if (g1->tag == 1)
			fun1(g1);      //递归算法
		//else
			//原子处理语句

		//g1 = g1->link;  ??        //处理后继元素
	}
}

void fun2(GLNode * g)
{
	if (g != NULL)
	{
		if (g->tag == 1)
			fun2(g->val.sublist);
		//else
			//原子处理语句

		//fun2(g->link);
	}
}

int GLLength(GLNode * g)
{
	int n = 0;
	GLNode * g1;
	g1 = g->val.sublist;
	while (g1 != NULL)
	{
		n++;
		g1 = g1->link;
	}
	return n;
}

int GLDepth(GLNode * g)
{
	GLNode * g1;
	int maxd = 0, dep;
	if (g->tag == 0)
		return 0;
	g1 = g->val.sublist;
	while (g1 != NULL)
	{
		if (g1->tag == 1)
		{
			dep = GLDepth(g1);
			if (dep > maxd)
				maxd = dep;
		}
		g1 = g1->link;
	}
	return(maxd + 1);
}

void DispGL(GLNode * g)
{
	if (g != NULL)
	{
		if (g->tag == 0)
		{
			cout << g->val.data << endl;
		}
		else
		{
			cout << "(";
			if (g->val.sublist == NULL)
				cout << "#";
			else
				DispGL(g->val.sublist);
			cout << ")";
		}
		if (g->link != NULL)
		{
			cout << ",";
			DispGL(g->link);
		}
	}
}

GLNode * CreateGL(char * &s)
{
	GLNode * g;
	char ch = *s++;
	if (ch != '\0')
	{
		g = (GLNode *)malloc(sizeof(GLNode));
		if (ch == '(')
		{
			g->tag = 1;
			g->val.sublist = CreateGL(s);
		}
		else if (ch == ')')
			g = NULL;
		else if (ch == '#')
			g = NULL;
		else
		{
			g->tag = 0;
			g->val.data = ch;
		}
	}
	else
		g = NULL;
	ch = *s++;
	if (g != NULL)
		if (ch == ',')
			g->link = CreateGL(s);      //兄弟结点
		else
			g->link = NULL;               //没有兄弟了
	return g;
}

void DestroyGL(GLNode * &g)
{
	GLNode * g1, *g2;
	g1 = g->val.sublist;
	while (g1 != NULL)
	{
		if (g1->tag == 0)
		{
			g2 = g1->link;         //保存兄弟结点
			free(g1);
			g1 = g2;
		}
		else
		{
			g2 = g1->link;
			DestroyGL(g1);
			g1 = g2;
		}
	}
	free(g);    //释放头结点
}

int Count1(GLNode * g)
{
	int n = 0;
	GLNode * g1 = g->val.sublist;
	while (g1 != NULL)
	{
		if (g1->tag == 0)
		{
			g++;
		}
		else
			n += Count1(g1);
		g1 = g1->link;
	}
	return n;
}

int Count2(GLNode * g)
{
	int n = 0;
	if (g != NULL)
	{
		if (g->tag == 0)
			n++;
		else
			n += Count2(g->val.sublist);
		n += Count2(g->link);
	}
	return n;
}