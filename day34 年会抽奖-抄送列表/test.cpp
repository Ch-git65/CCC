//���齱
//�����˽�һ��д���Լ����ֵ�������������
//����������������ϣ�ÿ�˴���ȡһ������
//�����Լ����ּ���
//�����˻񽱸���

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long d[22] = { 0,0,1 };//��������
	long long f[22] = { 0,1,2 };//�׳�
	for (int i = 3; i <= 22; i++)
	{
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
		f[i] = i * f[i - 1];
	}
	int n;
	while (cin >> n)
	{
		printf("%.2f%%\n", 100.0*d[n]/f[n]);
	}
	return 0;
}




//�����б�
//Joe,Kewell,Leon
//Joe           monic
//Ignore        Important
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	string line;
	while (getline(std::cin, line))
	{
		std::vector<std::string> names;
		size_t pos = 0;
		while (pos < line.length())
		{
			if (line[pos] == '\"')
			{
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				pos = end + 2;
			}
			else
			{
				size_t end = line.find(",", pos + 1);
				if (end == -1)
				{
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1;
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(),line))
		{
			printf("Important\n");
		}
		else
		{
			printf("Ignore\n");
		}
	}
	return 0;
}