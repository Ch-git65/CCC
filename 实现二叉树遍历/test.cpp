#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };
 

class Solution {
public:
    /**
     *
     * @param root TreeNode¿‡ the root of binary tree
     * @return int’˚–Õvector<vector<>>
     */

    void fun(TreeNode* root, vector<vector<int>>& ret)
    {
        if (root)
        {
            ret[0].push_back(root->val);
            fun(root->left, ret);
            ret[1].push_back(root->val);
            fun(root->right, ret);
            ret[2].push_back(root->val);
        }
    }

    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> result(3);
        fun(root, result);
        return result;
    }
};