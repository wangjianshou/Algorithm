#include <stdio.h>
typedef int ElementType;
extern void PercDown(ElementType A[], int i, int N);
extern void Heapsort(ElementType A[], int N);
int main(void)
{
	ElementType A[6] = {99,66,9,88,8,6};
	int i;
	for(i=0; i < 6; i++)
		printf("Before Sorted A[%d]: %d\n", i, A[i]);
	HeapSort(A, 6);
	for(i=0; i < 6; i++)
		printf("Sorted A[%d]: %d\n", i, A[i]);
}
