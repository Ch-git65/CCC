//给定一个数组arr，
//返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)。
// [2,3,4,5]
// 4

#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        int l = 0, r = 0;
        set<int> s;
        int res = 0;
        while (r < n)
        {
            if (!s.count(arr[r]))
            {
                s.insert(arr[r]);
                r++;
            }
            else
            {
                s.erase(arr[l]);
                l++;
            }
            res = res > s.size() ? res : s.size();
        }
        return res;
    }
};