//ɾ�������ַ�
#include <iostream>
#include <string>

using namespace std;
int main()
{
	//ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ�����
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	//ʹ�ù�ϣӳ��˼����ͳ��str2�ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	//����str1�� str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���str2��û�г��ֹ�

	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

	cout << ret << endl;
	return 0;
}