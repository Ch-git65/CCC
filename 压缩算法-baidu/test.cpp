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
            int j = i;  //������ǰѰ���롮����ƥ��ġ�����
            int k = 0;  //������¼ | ����λ��

            while (s[j] != '[')
            {
                if (s[j] == '|')
                    k = j;
                j--;
            }

            // stoi(str, 0, 2) ���ַ���str��0λ�ÿ�ʼ��ĩβ�Ķ�����ת��Ϊʮ����
            // substr(string, start, length) �����ַ�����һ���֣����ݣ�
            // instr()  .......(λ��)
            int len = stoi(s.substr(j + 1, k - j));

            string s1 = s.substr(k + 1, i - k - 1);
            string s2;

            for (int si = 0; si < len; si++) //��ʶ�𵽵��������ݽ��н���
                s2 += s1;

            s = s.replace(j, i - j + 1, s2);
            i = j; //�滻��i��ָ������ݱ仯�����滻���ֵ�ͷ��ʼ��Ѱ��

        }
        i++;
    }
    cout << s << endl;
}