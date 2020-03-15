#include<iostream>
using namespace std;

typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

int SeqSearch(RecType R[], int n, KeyType k)         //À≥–Ú≤È’“
{
	int i = 0;
	while (i < n&&R[i].key != k)
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1;
}
