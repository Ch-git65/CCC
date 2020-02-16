#define _CRT_SECURE_NO_WARNINGS 1
//最大公约数，最小公倍数
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
// 9*9口诀
//#include<stdio.h>
//int main()
//{
//	int i, j, result;
//	for (i = 1; i < 9; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			result = i*j;
//			printf("%d*%d=%-3d", i ,j, result);//-3d表示左对齐，占三位
//		}
//		printf("\n");
//	}
//	return 0;
//}
// 一对兔子，从出生第三个月起每月生一对兔子，每月兔子的总数
//#include<stdio.h>
//int main()
//{
//	long f1, f2;
//	int i;
//	f1 = f2 = 1;
//	for (i = 1; i <= 20; i++)               //每个循环中输出2个月的数据
//	{
//		printf("%12d %12d", f1, f2);        //输出已知的两个月的兔子数
//		if (i % 2 == 0) printf("\n");
//		f1 = f1 + f2;                       //计算下个月的兔子数，放f1
// 		f2 = f1 + f2;                       //计算下两个月的兔子数，放f2
//	}
//	return 0;
//}

//判断101~200有多少个素数，并输出
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
//			if (m % i == 0)   break; //如果被整除，终止内循环
//			if (i >= k + 1)          //若i>=k+1，表明未被整除
//			{
//				n = n + 1;
//				printf("%d ", m); h++;   // h用来控制换行
//			}
//		    if (h % 10 == 0) printf("\n");	//m累计到10的倍数，换行	
//	}
//	printf("\n");
//	printf("%d\n", n);
//	return 0;
//}

//将一个4*4的数组逆时针90度后输出
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

//杨辉三角
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