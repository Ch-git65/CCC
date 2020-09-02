#include<iostream>
using namespace std;

int fun(int a, int b)
{
    int temp;
    while (b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}

int main()
{
    int n, c;
    while (cin >> n >> c)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (c >= temp)
                c += temp;
            else
                c += fun(c, temp);
        }
        cout << c << endl;
    }
}