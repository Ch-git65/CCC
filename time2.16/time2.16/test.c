#define _CRT_SECURE_NO_WARNINGS 1
//���Լ������С������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m, n, i,t;
//	scanf("%d %d", &m, &n);
//	if (m > n)
//	{
//		t = m;
//		m = n;
//		n = t;
//	}
//	for (i = m; i > 0; i--)
//	{
//		if (m%i == 0 && n%i == 0)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}for (i = 1; i < m; i++)
//	{
//		if (n*i%m == 0)
//		{
//			printf("%d\n", n*i);
//			break;
//		}
//	}
//	return 0;
//}
// 9*9�ھ�
//#include<stdio.h>
//int main()
//{
//	int i, j, result;
//	for (i = 1; i < 9; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			result = i*j;
//			printf("%d*%d=%-3d", i ,j, result);//-3d��ʾ����룬ռ��λ
//		}
//		printf("\n");
//	}
//	return 0;
//}
// һ�����ӣ��ӳ�������������ÿ����һ�����ӣ�ÿ�����ӵ�����
//#include<stdio.h>
//int main()
//{
//	long f1, f2;
//	int i;
//	f1 = f2 = 1;
//	for (i = 1; i <= 20; i++)               //ÿ��ѭ�������2���µ�����
//	{
//		printf("%12d %12d", f1, f2);        //�����֪�������µ�������
//		if (i % 2 == 0) printf("\n");
//		f1 = f1 + f2;                       //�����¸��µ�����������f1
// 		f2 = f1 + f2;                       //�����������µ�����������f2
//	}
//	return 0;
//}

//�ж�101~200�ж��ٸ������������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m, i, k,h=0,n=0;
//	printf("\n");
//	for (m = 101; m < 201; m=m+2)
//	{
//		k = sqrt(m);
//		for (i = 2; i <= k; i++)		
//			if (m % i == 0)   break; //�������������ֹ��ѭ��
//			if (i >= k + 1)          //��i>=k+1������δ������
//			{
//				n = n + 1;
//				printf("%d ", m); h++;   // h�������ƻ���
//			}
//		    if (h % 10 == 0) printf("\n");	//m�ۼƵ�10�ı���������	
//	}
//	printf("\n");
//	printf("%d\n", n);
//	return 0;
//}

//��һ��4*4��������ʱ��90�Ⱥ����
//#include<stdio.h>
//int main()
//{
//	int a[4][4], b[4][4], i, j;
//	printf("input 16 numbers:");
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &a[i][j]);
//			b[3 - j][i] = a[i][j];
//		}
//		printf("arrayb:\n");
//		for (i = 0; i < 4; i++)
//		{
//			for (j = 0; j < 4; j++)
//			{
//				printf("%6d ", b[i][j]);
//			}
//		}
//	}
//	return 0;
//}

//�������
//#include<stdio.h>
//int main()
//{
//	int i, j, a[6][6];
//	for (i = 0; i < 6; i++)
//	{
//		a[i][i] = 1;
//		a[i][0] = 1;
//	}
//	for (i = 2; i < 6; i++)
//		for (j = 1; j <= i - 1; j++)
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//	        for (i = 0; i < 6; i++)
//			{
//		for (j = 0; j <= i; i++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}