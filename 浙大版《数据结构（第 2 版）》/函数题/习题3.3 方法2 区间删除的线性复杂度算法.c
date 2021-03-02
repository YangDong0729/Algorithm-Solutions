List Delete(List L, ElementType minD, ElementType maxD) {
    int i, p;

    for (i = 0; i <= L->Last; i++)
        if ((L->Data[i] > minD) && (L->Data[i] < maxD))
            break;            /*找到第1个待删元素*/
    p = i;                    /* p指向最左边可以填充的空格 */
    for (; i <= L->Last; i++) /* i继续向右扫描 */
        if (!((L->Data[i] > minD) && (L->Data[i] < maxD)))
            /* 对每个应保留的元素 */
            L->Data[p++] = L->Data[i]; /* 将之存到最左边可以填充的空格 */
                                       /* p继续向右移动1格，指向下一个最左边可以填充的空格 */
    L->Last = p - 1;                   /* p最后指向表尾最后一个空格处 */

    return L;
}
