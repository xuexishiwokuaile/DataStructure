#include<iostream>
#include"sqlist.cpp"

int main()
{
	SqList *L;
	ElemType e;
	std::cout << "顺序表的基本运算如下：\n";
	std::cout << "	(1)初始化顺序表：\n";
	InitList(L);
	std::cout << "	(2)依次插入a,b,c,d,e元素\n";
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("	(3)输出顺序表L:"); DispList(L);
	std::cout << "	(4)顺序表L长度:" << std::endl << ListLength(L);
	return 0;
}
