#include<iostream>
#define MaxSize 8
using namespace std;

typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

typedef struct snode
{
	char data;
	struct snode * next;
}LinkStrNode;

void StrAssign(SqString &s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

void StrCopy(SqString &s, SqString t)
{
}

void StrCopy(SqString &s, SqString t)
{
	int i;
	for (i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t)
{
	bool same = true; int i;
	if (s.length != t.length)
		same = false;
	else
		for(int i=0;i<s.length;i++)
			if (s.data[i] != t.data[i])
			{
				same = false;
				break;
			}
	return same;
}

int StrLength(SqString s)
{
	return s.length;
}

SqString Concat(SqString s, SqString t)
{
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
		str.data[i] = s.data[i];
	for (i = 0; i < t.length; i++)
		str.data[s.length + i] = t.data[i];
	return str;
}

SqString SubStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || j < 0 || i + j - 1>s.length)
		return str;
	for (k = i - 1; k < i + j - 1; k++)
		str.data[k - i + 1] = s.data[k];
	str.length = j;
	return str;
}

SqString InsStr(SqString s1, int i, SqString s2)
{
	int j;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1)
		return str;                //返回空串
	for (j = 0; j < i - 1; j++)
		str.data[j] = s1.data[j];
	for (j = 0; j < s2.length; j++)
		str.data[i + j - 1] = s2.data[j];
	for (j = i - 1; j < s1.length; j++)
		str.data[s2.length + j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

SqString DelStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++)
		str.data[i + k - 1] = t.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}

int Strcmp(SqString s, SqString t)             //按字典顺序比较两个串的大小
{
	int i, comlen;
	if (s.length < t.length)
		comlen = s.length;
	else
		comlen = t.length;
	for (i = 0; i < comlen; i++)
	{
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length)
		return -1;
	else if (s.length > t.length)
		return 1;
	else return -1;
}

void LongestString(SqString s, int &index, int &maxlen)
{
	int length, i = 1, start;
	index = 0, maxlen = 1;
	while (i < s.length)
	{
		start = i - 1;
		length = 1;
		while (i < s.length&&s.data[i] == s.data[i - 1])
		{
			i++;
			length++;
		}
		if (maxlen < length)
		{
			maxlen = length;
			index = start;
		}
		i++;
	}
}