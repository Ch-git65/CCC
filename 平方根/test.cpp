#include<iostream>
using namespace std;

class Solution {
public:
    /**
     *
     * @param x int整型
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if (x < 2)
            return x;

        int left = 1, right = x / 2;
        int mid, last_mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (x / mid > mid)
            {
                left = mid + 1;
                last_mid = mid;
            }

            else if (x / mid < mid)
                right = mid - 1;

            else
                return mid;
        }
        return last_mid;
    }
};