#include "pch.h"
//#include <cstdio>
//#include <cstring>

//char change[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3' , '2' };
//int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//
//int main1031() {
//	int n;
//	scanf("%d", &n);
//	bool flag = true;
//	char str[20];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", str);
//		int j, last = 0;
//		for (j = 0; j < 17; j++) // for (int j = 0; j < 17; j++) // һ������int�� ѭ���ⲻ�ɶ�ȡѭ���е�j����
//		{
//			if (!(str[j] >= '0' and str[j] <= '9')) break;
//			last = last + (str[j] - '0')*w[j];
//		}
//		if (j<17)
//		{
//			flag = false;
//			printf("%s\n", str);
//		}
//		else {
//			if (change[last%11]!=str[17])
//			{
//				flag = false;
//				printf("%s\n", str);
//			}
//		}
//	}
//	if (flag==true)
//	{
//		printf("All passed\n");
//	}
//	return 0;
//}