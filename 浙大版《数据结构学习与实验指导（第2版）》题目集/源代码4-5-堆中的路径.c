#include <stdio.h>
#include <stdlib.h>

#define MINDATA -10001  /* 比最小值还小的哨兵 */ 
typedef int ElementType;

typedef struct HNode *Heap; /* 堆的类型定义 */
struct HNode {
	ElementType *Data; /* 存储元素的数组 */
	int Size;          /* 堆中当前元素个数 */
	int Capacity;      /* 堆的最大容量 */
};
typedef Heap MinHeap; /* 最小堆 */

MinHeap CreateHeap( int MaxSize );
void Insert( MinHeap H, ElementType X );

int main()
{
	int N, M, i, j;
	ElementType X;
	MinHeap H;

	scanf("%d %d", &N, &M);
	H = CreateHeap( N ); /* 建立空堆 */
	for ( i=0; i<N; i++ ) {
		scanf("%d", &X);
		Insert(H, X); /* 逐一插入 */
	}
	for ( j=0; j<M; j++ ) { /* 逐一打印路径 */
		scanf("%d", &i);
		printf("%d", H->Data[i]); /* 首先输出起点H[i] */
		for ( i/=2; i>0; i/=2 ) /* 顺次访问H[i]的父结点 */
			printf(" %d", H->Data[i]);
		printf("\n");
	}
	return 0;
}

MinHeap CreateHeap( int MaxSize )
{ /* 创建容量为MaxSize的空的最大堆 */

	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MINDATA; /* 定义"哨兵"为小于堆中所有可能元素的值 */

	return H;
}

void Insert( MinHeap H, ElementType X )
{ /* 将元素X插入最小堆H，其中H->Data[0]已经定义为哨兵 */
    int i;
	for ( i=++H->Size; H->Data[i/2] > X; i/=2 )
        H->Data[i] = H->Data[i/2]; /* 上滤X */
	H->Data[i] = X; /* 将X插入 */
}

