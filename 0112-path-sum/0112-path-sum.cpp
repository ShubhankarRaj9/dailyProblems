/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool res = false;
    void fun(TreeNode* r, int sum, int targetSum){
        if(r == nullptr) return ;
        // computation
        sum += r->val;
        // leaf
        if(r-> left == nullptr && r->right == nullptr){
            if(sum == targetSum) {
                res = true;
            }
            return;
        }
        // non-leaf
        fun(r->left,sum,targetSum);
        fun(r->right,sum,targetSum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        fun(root, 0, targetSum);
        return res;
    }
};