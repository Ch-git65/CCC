//Ҫ�� a[i] * a[i + 1] <= a[i + 1] * a[i + 2]
//��������ȥ�ֱ��жϣ���֤�˻�Ϊ���ķ���ߣ��˻�Ϊ���ķ��ұߡ�
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include "limits.h"
#include "math.h"
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main(int argc, const char* argv[])
{
	//����������
	int n, num;
	cin >> n;
	vector<int> posi;
	vector<int> nega;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num < 0)
			nega.push_back(num);
		else
			posi.push_back(num);
	}

	//�������࣬����������������
	//���� �� �� �������������򣬸������� +����....����������������
	if (posi.size() >= nega.size())
	{
		sort(posi.begin(), posi.end()); //����
		sort(nega.begin(), nega.end());
		int i = 0, j = nega.size() - 1;

		for (;i<nega.size(); i++,j--)
			cout << nega[i] << " " << posi[i] << " ";

		for (; i < posi.size(); i++)
			cout << posi[i] << " ";

		cout << endl;
	}
	else
	{
		//������������
		//���� �� �� ������������ �������� ����....������������
		sort(posi.begin(), posi.end(), cmp); // ����
		sort(nega.begin(), nega.end(), cmp);
		int i = 0, j = posi.size() - 1;
		for (; j < posi.size(); i++, j--)
			cout << posi[i] << " " << nega[j] << " ";

		for (; j < nega.size(); i++)
			cout << nega[i] << " ";

		cout << endl;
	}
	return 0;
}