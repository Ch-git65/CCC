//�ռ����б�
// 3
// joe
// Quan,William
// Letender,Bruce
// joe,"Quan,William","Letender,Bruce"
#include<iostream>
#include<string>
#include<cstdio>
int main()
{
	int n;
	while (std::cin >> n)
	{
		std::cin.get();
		std::string name;
		for (int i = 0; i < n; i++)
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos)
			{
				quote = true;
			}

			if (quote)
			{
				putchar('\"');
			}

			std::cout << name;

			if (quote)
			{
				putchar('\"');
			}
			if (i == n - 1)
			{
				putchar('\n');

			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0;
}



//������
//ÿֻ���ӳ�������һ�죬ÿ���һ̥���ӣ�N����м�ֻ
#include<iostream>
#include<cstdio>
int main()
{
	long long n[91] = { 1,2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while (std::cin >> d)
	{
		printf("%11d\n", n[d-1]);
	}
}