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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool left_to_right = true;
        while(!q.empty()){
            int numberOfNodes = q.size();
            vector<int> temp;
            for(int i=0; i<numberOfNodes; i++){
                TreeNode* currentNode = q.front();q.pop();
                temp.push_back(currentNode->val);
                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }
            if(!left_to_right){
                reverse(temp.begin(),temp.end());
            }
            res.push_back(temp);
            left_to_right = !left_to_right;
        }
        return res;
    }
};