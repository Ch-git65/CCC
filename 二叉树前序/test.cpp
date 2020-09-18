#include <iostream>
#include <vector>
#include <stack>
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
     * @param root TreeNode¿‡
     * @return int’˚–Õvector
     */
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;

        while (p || !s.empty())
        {
            while (p)
            {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            }

            if (!s.empty())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};