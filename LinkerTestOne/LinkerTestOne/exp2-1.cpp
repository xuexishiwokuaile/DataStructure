#include<iostream>
#include"sqlist.cpp"

int main()
{
	SqList *L;
	ElemType e;
	std::cout << "˳���Ļ����������£�\n";
	std::cout << "	(1)��ʼ��˳���\n";
	InitList(L);
	std::cout << "	(2)���β���a,b,c,d,eԪ��\n";
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("	(3)���˳���L:"); DispList(L);
	std::cout << "	(4)˳���L����:" << std::endl << ListLength(L);
	return 0;
}
