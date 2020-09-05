/*
 5 3
 1 2 3 4 5
 5
 left take 1
 right take 2
 left return 3
 right keep
 right take 4
 6
 left take 5
 right take 1
 left return 2
 right return 3
 left take 5
 left return 4
 10
 left take 1
 left keep
 left take 2
 left keep
 left take 3
 left keep
 left take 4
 left keep
 left take 5
 left keep
 */

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include "limits.h"
#include "math.h"
using namespace std;

int main(int argc, const char* argv[])
{
    int n, m;
    cin >> n >> m;

    //每个货物槽的原始价格
    int prices[10000];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    //n个货物槽，记录可能被放错的货物的价格
    vector<stack<int>> boxes;
    for (int i = 0; i < n; i++)
    {
        stack<int> st;
        boxes.push_back(st);
    }

    //m 进行个人操作
    int k, num;
    string hand, action;
    while (m--)
    {
        cin >> k;  //k次操作
        int left = -1, right = -1; //左右手货物的价格
        int p, totalprices = 0; //总价格
        while (k--)
        {
            cin >> hand >> action;
            if (action == "take")
            {
                cin >> num;
                if (boxes[num - 1].empty())
                    p = prices[num - 1];
                else
                {
                    p = boxes[num - 1].top();
                    boxes[num - 1].pop();
                }

                totalprices += p;

                if (hand == "left")
                    left = p;
                else
                    right = p;
            }

            else if (action == "return")
            {
                cin >> num;
                if (hand == "left")
                {
                    p = left;
                    left = -1;
                }
                else
                {
                    p = right;
                    right = 1;
                }
                boxes[num - 1].push(p);
                totalprices -= p;
            }

            else
            {
                if (hand == "left")
                    left = -1;
                else
                    right = -1;
            }
        }
        cout << totalprices << endl;
    }
    return 0;
}



//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<stack>
//#define maxn 101
//using namespace std;
//int cost[maxn];
//stack<int> sta[maxn];
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> cost[i];
//
//    while (m--)
//    {
//        int q;
//        cin >> q;
//        int totalCost = 0;
//        int left = -1, right = -1;
//        while (q--)
//        {
//            string a, b;
//            cin >> a >> b;
//            int actionType = 0;
//            bool side = (a == "left" ? 0 : 1);
//            if (b == "return")
//                actionType = 1;
//            else if (b == "keep")
//                actionType = 2;
//
//            if (actionType != 2)
//            {
//                int k;
//                cin >> k;
//                if (actionType == 0)
//                {
//                    int qu = -1;
//                    if (!sta[k].empty())
//                    {
//                        qu = sta[k].top();
//                        sta[k].pop();
//                    }
//                    else
//                        qu = k;
//
//                    if (side)
//                    {
//                        right = qu;
//                    }
//                    else
//                        left = qu;
//                }
//                else
//                {
//                    int fang = 0;
//
//                    if (side) {
//                        fang = right;
//                        right = -1;
//                     }
//                     else {
//                        fang = left;
//                        left = -1;
//                      }
//
//                     if (fang == k && sta[k].empty()) {
//                         continue;
//                      }
//                      else {
//                         sta[k].push(fang);
//                      }
//                 }
//             }
//             else {
//                int fang = 0;
//                if (side) {
//                    fang = right;
//                    right = -1;
//                }
//                else {
//                    fang = left;
//                    left = -1;
//                }
//                totalCost += cost[fang];
//            }
//         }
//        if (left != -1) {
//            totalCost += cost[left];
//        }
//        if (right != -1) {
//            totalCost += cost[right];
//        }
//       cout << totalCost << endl;
//    }
//    return 0;
//}