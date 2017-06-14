#include <stdio.h>
#define LeftChild(i) (2*(i)+1)
typedef int ElementType;
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;
    for(Tmp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if(Child != N-1 && A[Child] < A[Child+1])
            Child++;
        if(A[Child] > Tmp)
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void Swap(int * x, int * y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

OccurenceArray(ElementType A[], int N)
{
	int j;
	for(j = 0; j < N; j++)
		printf("A[%d]=%d\n", j, A[j]);
	printf("\n");
}

void HeapSort(ElementType A[], int N)
{
    ElementType tmp;
    int i, j;
    for(i = N/2; i >= 0; i--)
        PercDown(A, i, N);
		//OccurenceArray(A, N);
    for(i = N-1; i > 0; i--)
    {
			Swap(&A[0], &A[i]);
			printf("i=%d, After Swap, Before Rebuild Heap:\n", i);
			OccurenceArray(A, N);
      PercDown(A, 0, i);
			printf("i=%d, After Rebuild Heap:\n", i);
			OccurenceArray(A, N);
    }
}
