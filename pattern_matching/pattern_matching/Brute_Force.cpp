#include<iostream>
#define MaxSize 8
using namespace std;

typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

int BF(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length&&j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return(i - j.length);
	else
		return(-1);
}