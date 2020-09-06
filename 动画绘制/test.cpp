// 一个h* w的显示器，要在上面显示一个图像平移的动画。
// 图像大小为q* p。（1 <= p, q, h, w <= 100)。 
// 在显示器上面显示背景，然后图像要覆盖背景。
// 图像开始的时候左上角的位置在(stx, sty)（可能是负数）每次图像向右移动dy，
// 向左移动dx，屏幕的每个单元格，如果和上次的字符不一样，就需要刷新。
// 问最少刷新几次？
// T组输入，保证dx和dy不同时为0。


//开始屏幕只有背景
// ....
// ....
// ....
// ....
//
//第一次的图像：
// |\..
// /\..
// ....
// ....
//
//第二次的图像：
// .o..
// /|\.
// ./\.
// ....
//
//第三次的图像
// ....
// ..o.
// ./|\
// ../\
//
//第四次的图像
// ....
// ....
// ...o
// ../|
//
//第五次就出去了
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
char a[N][N];  //存背景
char b[N][N];  //存动画
char pre[N][N];//存上一次屏幕的内容
char c[N][N];  //存当前屏幕内容
int main(void)
{
	int T, w, h, p, q, dx, dy, stx, sty;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &w, &h);
		for (int i = 1; i <= h; ++i)  //输入背景
			scanf("%s", a[i]+1);

		scanf("%d%d", &p, &p);
		for (int i = 1; i <= q; ++i)  //输入图像
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

		int nowx1 = stx, nowy1 = sty; //记录图像左上角的节点

		while (1)//模拟
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
			else //如果这次没在屏幕上出现，之前出现会过，说明已经远离屏幕
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

			for (int i = 1; i <= h; ++i)  //先画背景
				for (int j = 1; j <= w; ++j)
					c[i][j] = a[i][j];

			for (int i = 0; i < q; ++i)   //再在背景上画图
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
