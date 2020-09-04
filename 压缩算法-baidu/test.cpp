#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ']')
        {
            int j = i;  //用来向前寻找与‘】’匹配的‘【’
            int k = 0;  //用来记录 | 所在位置

            while (s[j] != '[')
            {
                if (s[j] == '|')
                    k = j;
                j--;
            }

            // stoi(str, 0, 2) 将字符串str从0位置开始到末尾的二进制转换为十进制
            // substr(string, start, length) 返回字符串的一部分（内容）
            // instr()  .......(位置)
            int len = stoi(s.substr(j + 1, k - j));

            string s1 = s.substr(k + 1, i - k - 1);
            string s2;

            for (int si = 0; si < len; si++) //将识别到的括号内容进行解码
                s2 += s1;

            s = s.replace(j, i - j + 1, s2);
            i = j; //替换后i所指向的内容变化，从替换部分的头开始在寻找

        }
        i++;
    }
    cout << s << endl;
}