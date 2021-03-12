#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1001
typedef int ElementType;
#define Swap(a,b)  a ^= b, b ^= a, a ^= b;
/* 通过连续三次异或运算交换a与b */

/*-----顺序表的定义-----*/ 
typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef PtrToLNode List;
/*-----顺序表的定义结束-----*/ 
typedef List Tree; /* 用顺序表定义树 */

int NCA( int p1, int p2 )
{
    while (p1 != p2) {
    	/* 先保证p1在p2上面 */
        if ( p1 > p2 ) { Swap(p1, p2) }
        while ( p2 > p1 ) p2/=2; /* p2向上追赶p1 */
    }
    return p1;
}

int main()
{
    int N;
    int p1, p2, p;
    Tree T = (Tree)malloc(sizeof(struct LNode)); 
    
    /* 读入树 */
    T->Data[0] = 0; T->Last = 0;
    scanf("%d", &N);
    for ( T->Last=1; T->Last<=N; T->Last++ )
		scanf("%d", &T->Data[T->Last]);
	T->Last--;
	
    scanf("%d %d", &p1, &p2);
    if (!T->Data[p1]) printf("ERROR: T[%d] is NULL\n", p1);
    else if (!T->Data[p2]) printf("ERROR: T[%d] is NULL\n", p2);
    else {
         p = NCA( p1, p2 );
         printf("%d %d\n", p, T->Data[p]);
    }

    return 0;
}

