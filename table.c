//链表
//typedef somthing ElementType;
typedef int ElementType;
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
void FatalError(char *);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeletList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

struct Node
{
  ElementType Element;
  Position Next;
};

void FatalError(char * str)
{
	printf(str);
}

List MakeEmpty(List L)
{
	L->Next = NULL;
	return L;
}

/* Return true if L is empty */
int IsEmpty(List L)
{
  return L->Next == NULL;
}

//Return true if P is the last position in list L
//Parameter L is unused in this implementation
int IsLast( Position P, List L)
{
  return P->Next == NULL;
}

//Return Position of X in L, NULL if not found.
Position Find(ElementType X, List L)
{
  Position P;
  P = L->Next;
  while(P != NULL && P->Element != X)
    P = P->Next;
  return P;
}

//Delete first occurrence of X from a list. Assume use a header node
void Delete(ElementType X, List L)
{
  Position P, TmpCell;
  P = FindPrevious(X, L);
  if(!IsLast(P, L))
	{
    TmpCell =  P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

Position FindPrevious(ElementType X, List L)
{
  Position P;
  P = L;
  while(P->Next != NULL && P->Next->Element != X)
    P = P->Next;
  return P;
}


//Insert (after legal position P); Parameter L is unused in this implementation
void Insert(ElementType X, List L, Position P)
{
  Position TmpCell;
  TmpCell =  (Position) malloc(sizeof(struct Node));
  if(TmpCell == NULL)
    FatalError("out of space");
  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}


void DeleteList(List L)
{
  Position P, Tmp;
  P = L->Next;
  L->Next = NULL;
  while(P != NULL)
	{
    Tmp = P->Next;
    free(P);
    P = Tmp;
  }
}


void printList(List L)
{
	while(!IsLast(L, L))
	{
		printf("%d\n", L->Next->Element);
		L = L->Next;
	}
}





