#include<iostream>
using namespace std;

int main()
{
    int x, y;
    while (cin >> x)
    {
        while (x)
        {
            if (x % 2 == 1)
                y++;
            x /= 2;
        }
    }
    cout << y << endl;
    return 0;
}