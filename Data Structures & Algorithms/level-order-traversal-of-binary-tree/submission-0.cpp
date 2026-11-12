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
    vector<vector<int>> result;

    void goFunction(TreeNode* root, int level){
        if(root){
            if(level==result.size()){
                vector<int> push = {root->val};
                result.push_back(push);
            } else{
                result[level].push_back(root->val);
            }
        } else{
            return;
        }

        if(root->left){
            goFunction(root->left, level+1);
        }

        if(root->right){
            goFunction(root->right, level+1);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        result.clear();

        goFunction(root, 0);

        return result;
    }
};
