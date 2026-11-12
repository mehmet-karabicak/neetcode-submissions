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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        return 1+(max(maxDepth(root->left), maxDepth(root->right)));
    }


    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(!root->left and !root->right) return true;

        if(!root->left){
            if(root->right->left or root->right->right){
                return false;
            }
        }

        if(!root->right){
            if(root->left->left or root->left->right){
                return false;
            }
        }        


        //return (isBalanced(root->left) and isBalanced(root->right));
        return abs(maxDepth(root->left)-maxDepth(root->right))<=1 and (isBalanced(root->left) and isBalanced(root->right));
    }
};
