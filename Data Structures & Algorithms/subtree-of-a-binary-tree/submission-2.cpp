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
    bool checkSubtree(TreeNode* root, TreeNode* subroot){
        if(!root and !subroot) return true;

        //if(!root->left and !root->right and !subroot->left and !subroot->right) return true;

        if(!root->left and subroot->left) return false;

        if(!root->right and subroot->right) return false;

        if(root->left and !subroot->left) return false;

        if(root->right and !subroot->right) return false;

        return (root->val == subroot->val) and checkSubtree(root->left, subroot->left) and checkSubtree(root->right, subroot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot) or checkSubtree(root, subRoot);
    }
};
