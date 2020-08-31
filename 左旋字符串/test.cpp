#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string str1;
        int len = str.size();
        for (int i = 0; i < len - n; i++)
            str1[i] = str[i + n];

        for (int j = len - n; j < len; j++)
        {
            str1[j] = str[j - len + n];
        }
        return str1;
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.length() < n || str.length() < 0)
            return "";
        // char[] chars = str.toCharArray();
        reverse(str, 0, n - 1);
        reverse(str, n, str.length() - 1);
        reverse(str, 0, str.length() - 1);
        return str;
    }
    void reverse(string& str, int begin, int end) {
        while (begin < end) {
            char temp = str[begin];
            str[begin] = str[end];
            str[end] = temp;
            begin++;
            end--;
        }
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n > str.size()) return str;
        return str.substr(n) + str.substr(0, n);

    }
};