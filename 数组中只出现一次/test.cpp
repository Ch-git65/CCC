#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        map<int, int> m;
        vector<int> res;
        for (auto x : data)
            m[x]++;
        for (auto x : m)
        {
            if (x.second == 1)
                res.push_back(x.first);
        }
        *num1 = res[0], * num2 = res[1];
    }
};