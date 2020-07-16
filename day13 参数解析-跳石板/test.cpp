//��������
//����һ���ַ���
//��������������ֽ��Ĳ�����ÿ������ռһ��

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		//��������
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;

			//�����˫���ţ���������ֱ����һ��˫���Ž���
			if (str[i] == '"')
			{
				do {
					i++;
				} while (str[i] != '"');
			}
		}
		cout << count + 1 << endl;


		//��flag��ʾ�Ƿ����˫���ţ�0��ʾ��
		//�����ı�flag��ֵ������˫���ſ���ʹ�临ԭ
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			//��˫���ţ�flagͨ������Ϊ0����һ��������flag��Ϊ1
			if (str[i] == '"')
				flag ^= 1;

			//˫���źͿո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];

			//˫�����еĿո��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];

			//����˫����֮��Ŀո�ͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;

	}
	return 0;
}



//��ʯ��
//��ǰ���Ϊk������ֻ����ǰ��k��һ��Լ��������1��k��
// N=4, M=24;
// 4->6->8->12->18->24
// 5

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int>& divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}

int Jump(int N, int M)
{
	//����ĵ����stepNum�Ĳ�������ʼNΪ1������N��NΪ1��
	vector<int>stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;

		//0��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue;

		divisorNum(i, divNum);

		for (int j = 0; j < divNum.size(); j++)
		{
			if ((divNum[j] + 1) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}

	if (stepNum[M] == 0)
		return -1;
	else
		return stepNum[M] - 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}