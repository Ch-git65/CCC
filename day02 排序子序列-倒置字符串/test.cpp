//����������
// 6
// 1 2 3 2 2 1
// 2

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	//��һ��ֵ������Խ������
//	vector<int> a;
//	a.resize(n + 1);
//	a[n] = 0;
//
//	//��������
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//
//	i = 0;
//	int count = 0;
//	while (i < n)
//	{
//		//�ǵݼ�������
//		if (a[i] < a[i + 1])
//		{
//			while (i < n && a[i] <= a[i + 1])
//				i++;
//
//			count++;
//			i++;
//		}
//		else if (a[i] == a[i + 1])
//		{
//			i++;
//		}
//
//		else //�ǵ���������
//		{
//			while (i < n && a[i] >= a[i + 1])
//				i++;
//
//			count++;
//			i++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}


//�����ַ���
//I like beijing.
//bejing. like I
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1) {
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;
	return 0;
}