
//class Solution
//{
//public:
//    vector<int> singleNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        vector<int> res;
//        int i = 0;
//        for (; i < nums.size() - 1; )
//        {
//            if (nums[i] == nums[i + 1])
//            {
//                i += 2;
//            }
//            else
//            {
//                res.push_back(nums[i]);
//                i += 1;
//            }
//        }
//        if (i < nums.size())
//        {
//            res.push_back(nums[i]);
//        }
//        return res;
//    }
//};


#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v) {
    // const����ʹ��const���������б�����ӡ
    vector<int>::const_iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
int main()
{
    // ʹ��push_back����4������
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // ʹ�õ��������б�����ӡ
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    // ʹ�õ����������޸�
    it = v.begin();
    while (it != v.end())
    {
        *it *= 2;
        ++it;
    }
    // ʹ�÷�����������б����ٴ�ӡ
    vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
    PrintVector(v);
    return 0;
}

#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int a[] = { 1, 2, 3, 4 };
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    // ʹ��find����3����λ�õ�iterator
    vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    // ɾ��posλ�õ����ݣ�����pos������ʧЧ��
    v.erase(pos);
    cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
    return 0;
}

#include <iostream>
using namespace std;
#include <vector>
int main()
{
    vector<int> v{ 1,2,3,4,5,6 };

    auto it = v.begin();

    // ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
    // v.resize(100, 8);

    // reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
    // v.reserve(100);

    // ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
    // v.insert(v.begin(), 0);
    // v.push_back(8);

 // ��vector���¸�ֵ�����ܻ�����ײ������ı�
    v.assign(100, 8);

    /*
    ����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
   ���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
   �ռ䣬�������������ʱ������
    �����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
   ��ֵ���ɡ�
    */
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}