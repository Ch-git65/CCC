#include<stdio.h>
int prime[10001];  //存储素数的数组
int primesize = 0; //记录素数的个数
int mark[10001];   //标记是否是素数

void init()
{
	for (int i = 2; i <= 10000; i++)
		mark[i] = false;  //初始化，所有数目前均为素数
	for (int i = 2; i <= 10000; i++)
	{
		if (false == mark[i])
		{
			prime[primesize++] = i; // 记录素数
			for (int j = i * i; j <= 10000; j += i)
			{
				mark[j] = true;
			}
		}
	}
}

int main()
{
	init();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		bool isOutPut = false;
		for (int i = 0; i < primesize; i++)
		{
			if (prime[i] < n && prime[i] % 10 == 1)
			{
				if (false == isOutPut)
				{
					isOutPut = true;
					printf("%d", prime[i]);
				}
				else
					printf(" %d", prime[i]);
			}
		}

		if (false == isOutPut)
			printf("-1\n");
		else
			printf("\n");
	}
	return 0;
}