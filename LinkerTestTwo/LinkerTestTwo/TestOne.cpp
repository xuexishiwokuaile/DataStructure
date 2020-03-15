#include<iostream>
#include<malloc.h>
#define MaxSize 50
using namespace std;

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++; i++;
	}
	L->length = k;
}

void delnode1(SqList *L, ElemType x)
{
	int k = 0, i;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}

void delnode2(SqList *&L, ElemType x)
{
	int k = 0, i = 0;
	while (i < L->length)
	{
		if (L->data[i] == x)
			k++;
		else
			L->data[i - k] = L->data[i];
		i++;
	}
	L->length -= k;
}

void partition1(SqList *&L)
{
	int i = 0, j = L->length - 1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (i<j&&L->data[j]>pivot)
			j--;
		while (i < j&&L->data[i] <= pivot)
			i++;
		if (i < j)
			swap(L->data[i], L->data[j]);
	}
	swap(L->data[0], L->data[i]);
}

void partition2(SqList *&L)                 //更高效
{
	int i = 0, j = L->length - 1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (j > i&&L->data[j] > pivot)
			j--;
		L->data[i] = L->data[j];
		while (i < j&&L->data[i] <= pivot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = pivot;
}

void move1(SqList *&L)                 //思路：j从右到左找奇数元素，i从左到右找偶数元素，并将两者交换
{
	int i = 0, j = L->length - 1;
	ElemType pilot = L->data[0];
	while (i < j)
	{
		while (i < j&&L->data[j] % 2 == 0)
			j--;
		while (i < j&&L->data[i] % 2 != 0)
			i++;
		if (i < j)
			swap(L->data[i], L->data[j]);
	}	
}

void move2(SqList *&L)
{
	int i = -1, j;                  //用i来建立一个存放奇数的区间
	for (j = 0; j < L->length; j++)
	{
		if (L->data[j] % 2 == 1)          //为奇数
		{
			i++;
			if (i != j)
				swap(L->data[i], L->data[j]);
		}
	}
}

int main()
{
	SqList *L;
	ElemType a[10] = { 2,3,5,4,1,0,3,4,6,0 };
	CreateList(L, a, 6);
	//delnode2(L, 3);
	partition2(L);
	for (int i = 0; i < L->length; i++)
	{
		cout << L->data[i] << endl;
	}
	system("pause");
	return 0;
}