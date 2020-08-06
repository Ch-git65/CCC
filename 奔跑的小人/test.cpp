#include<cstdio>
#include<cstdlib>
#include<Windows.h>

int main()
{
	int a, b;
	a = 0;
	while (a <= 80)
	{
		system("cls");
		b = 1;
		while (b <= a)
		{
			printf(" ");
			b += 1;
		}
		printf(" 0\n");

		b = 1;
		while (b <= a)
		{
			printf(" ");
			b += 1;
		}
		printf("<H>\n");

		b = 1;
		while (b <= a)
		{
			printf(" ");
			b += 1;
		}
		printf("I I\n");

		Sleep(300);
		a += 1;
	}
	return 0;
}