//������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���
//ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
//���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
//���磬��kΪ18ʱ���������ܹ����뷽��35, 37������Ϊ3 + 5 + 3 + 7 = 18��
//���ǣ������ܽ��뷽��35, 38������Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
#include<iostream>
using namespace std;

class Solution {
public:

    int f(int x)
    {
        int a = 0;
        while (x)
        {
            a = a + x % 10;
            x /= 10;
        }
        return a;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        int ret = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (f(i) + f(j) <= threshold)
                    ++ret;
                else if (rows == 1 || cols == 1)
                    return ret;
            }
        }
        return ret;
    }
};