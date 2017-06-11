#include <stdio.h>
#include <stdlib.h>
#include "table.c"

int main(void)
{
	struct Node node;
	List list=&node;
	list = MakeEmpty(list);
	Insert(1, list, list);
	Insert(10, list, list);
	Insert(100, list, list);
	printList(list);
	Insert(66, list,Find(10, list));
	printList(list);
}
