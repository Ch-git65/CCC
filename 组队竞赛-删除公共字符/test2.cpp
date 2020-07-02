//删除公共字符
#include <iostream>
#include <string>

using namespace std;
int main()
{
	//注意这里不能使用cin接收，因为cin遇到空格就结束了
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	//使用哈希映射思想先统计str2字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	//遍历str1， str1[i]映射hashtable对应位置为0，则表示这个字符在str2中没有出现过

	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

	cout << ret << endl;
	return 0;
}