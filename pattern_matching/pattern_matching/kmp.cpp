#include<iostream>
#define MaxSize 8
using namespace std;

typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

void GetNext(SqString t, int next[])
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++; k++;
			next[j] = k;
		}
		else k = next[k];
	}
}

int KMPIndex(SqString s, SqString t)
{
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);    //获得模式串的next
	while (i < s.length&&j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if (j >= t.length)
		return(i - t.length);
	else
		return(-1);
}