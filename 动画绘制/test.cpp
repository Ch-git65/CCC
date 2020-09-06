// һ��h* w����ʾ����Ҫ��������ʾһ��ͼ��ƽ�ƵĶ�����
// ͼ���СΪq* p����1 <= p, q, h, w <= 100)�� 
// ����ʾ��������ʾ������Ȼ��ͼ��Ҫ���Ǳ�����
// ͼ��ʼ��ʱ�����Ͻǵ�λ����(stx, sty)�������Ǹ�����ÿ��ͼ�������ƶ�dy��
// �����ƶ�dx����Ļ��ÿ����Ԫ��������ϴε��ַ���һ��������Ҫˢ�¡�
// ������ˢ�¼��Σ�
// T�����룬��֤dx��dy��ͬʱΪ0��


//��ʼ��Ļֻ�б���
// ....
// ....
// ....
// ....
//
//��һ�ε�ͼ��
// |\..
// /\..
// ....
// ....
//
//�ڶ��ε�ͼ��
// .o..
// /|\.
// ./\.
// ....
//
//�����ε�ͼ��
// ....
// ..o.
// ./|\
// ../\
//
//���Ĵε�ͼ��
// ....
// ....
// ...o
// ../|
//
//����ξͳ�ȥ��
// ....
// ....
// ....
// ....

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
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

const int N = 200;
char a[N][N];  //�汳��
char b[N][N];  //�涯��
char pre[N][N];//����һ����Ļ������
char c[N][N];  //�浱ǰ��Ļ����
int main(void)
{
	int T, w, h, p, q, dx, dy, stx, sty;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &w, &h);
		for (int i = 1; i <= h; ++i)  //���뱳��
			scanf("%s", a[i]+1);

		scanf("%d%d", &p, &p);
		for (int i = 1; i <= q; ++i)  //����ͼ��
			scanf("%s", b[i]+1);

		scanf("%d%d%d%d", &stx, &sty, &dy, &dx);
		int x1 = stx, x2 = stx + q - 1, y1 = sty, y2 = sty + p - 1;
		bool existx = true, existy = true;
		if ((x1 > h&& dx >= 0) || (x2 < 1 && dx <= 0))
			existx = false;
		if ((y1 > w&& dy >= 0) || (y2 < 1 && dy <= 0))
			existy = false;
		if (!existx && !existy)
		{
			puts("0");
			continue;
		}

		int flag = 0;
		int ans = 0;
		for (int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
				pre[i][j] = a[i][j];

		int nowx1 = stx, nowy1 = sty; //��¼ͼ�����ϽǵĽڵ�

		while (1)//ģ��
		{
			bool in = false;
			int xx1 = nowx1, xx2 = nowx1 + q - 1;
			int yy1 = nowy1, yy2 = nowy1 + p - 1;
			if ((xx1 > h || xx2 < 1) || (yy1 > w || yy2 < 1))
				in = false;
			else
				in = true;

			if (in)
				flag = true;
			else //������û����Ļ�ϳ��֣�֮ǰ���ֻ����˵���Ѿ�Զ����Ļ
			{
				if (flag)
					break;
				else
				{
					nowx1 += dx;
					nowy1 += dy;
					continue;
				}
			}

			for (int i = 1; i <= h; ++i)  //�Ȼ�����
				for (int j = 1; j <= w; ++j)
					c[i][j] = a[i][j];

			for (int i = 0; i < q; ++i)   //���ڱ����ϻ�ͼ
				for (int j = 0; j < p; ++j)
					if (i + nowx1 >= 1 && nowx1 <= h && j + nowx1 >= 1 && nowy1 <= w)
						c[i + nowx1][j + nowy1] = b[i + 1][j + 1];

			int cnt = 0;
			for (int i = 1; i <= h; ++i)
				for (int j = 1; j <= w; ++j)
				{
					if (c[i][j] != pre[i][j])
						++cnt;
					pre[i][j] = c[i][j];
				}

			ans += cnt;
			nowx1 += dx;
			nowy1 += dy;

		}
		printf("%d\n", ans);
	}
	return 0;
}
