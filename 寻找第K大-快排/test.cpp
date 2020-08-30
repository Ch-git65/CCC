#include<iostream>
#include<vector>
using namespace std;

class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quickfind(a, 0, n - 1, K);
    }
    int quickfind(vector<int>& a, int left, int right, int k)
    {
        int i = left, j = right;
        int mark = a[left];

        while (i < j)
        {
            while (i < j && a[j] >= mark)
                --j;

            if (i < j)
                a[i++] = a[j];

            while (i < j && a[i] <= mark)
                ++i;

            if (i < j)
                a[j--] = a[i];
        }
        a[i] = mark;

        int big_num = right - i;

        if (k - big_num - 1 == 0)
            return mark;
        else if (k - big_num - 1 > 0)
            return quickfind(a, left, i - 1, k - big_num - 1);
        else
            return quickfind(a, i + 1, right, k);
    }
};