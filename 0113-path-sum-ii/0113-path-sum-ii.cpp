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
    vector<vector<int>> res;
    void fn(TreeNode* r, int sum, vector<int> diary, int targetSum){
        if(r == nullptr) return;
        sum += r->val;
        diary.push_back(r->val);
        if(r->left == nullptr && r->right == nullptr){
            if(sum == targetSum){
                res.push_back(diary);
            }
            diary.pop_back();
            return ;
        }
        fn(r->left, sum, diary, targetSum);
        fn(r->right, sum, diary, targetSum);
        diary.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        fn(root,0,diary,targetSum);
        return res;
    }
};