List Delete(List L, ElementType minD, ElementType maxD) {
    int i, j;

    for (i = 0; i <= L->Last; i++)                        /* 扫描每个元素L->Data[i] */
        if ((L->Data[i] > minD) && (L->Data[i] < maxD)) { /* 如果要删除 */
            for (j = i + 1; j <= L->Last; j++)
                L->Data[j - 1] = L->Data[j]; /* 整体左移 */
            L->Last--;                       /* /* 更新表长L->Last */
            i--;                             /* 令i指向当前最后一个不删除的元素*/
        }

    return L;
}
