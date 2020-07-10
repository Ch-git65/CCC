#include<stdio.h>
int prime[10001];  //�洢����������
int primesize = 0; //��¼�����ĸ���
int mark[10001];   //����Ƿ�������

void init()
{
	for (int i = 2; i <= 10000; i++)
		mark[i] = false;  //��ʼ����������Ŀǰ��Ϊ����
	for (int i = 2; i <= 10000; i++)
	{
		if (false == mark[i])
		{
			prime[primesize++] = i; // ��¼����
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