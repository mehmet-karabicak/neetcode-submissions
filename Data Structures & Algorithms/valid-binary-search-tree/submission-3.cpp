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
    bool checkValidity(TreeNode* root, int minConstraint, int maxConstraint){
        if(!root) return true;

        if(root->val <= minConstraint) return false;

        if(root->val >= maxConstraint) return false;

        return checkValidity(root->left, minConstraint, root->val) and checkValidity(root->right, root->val, maxConstraint);
    }

    bool isValidBST(TreeNode* root) {
        return checkValidity(root->left, -1000000001, root->val) and checkValidity(root->right, root->val, 1000000001);
    }
};
