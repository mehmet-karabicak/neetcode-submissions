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
    void invert(TreeNode* root){
        if(!root) return;

        if(!root->left && !root->right) return;

        if(!root->left and root->right){
            root->left = root->right;

            root->right = nullptr;

            invert(root->left);

            return;
        }

        if(!root->right and root->left){
            root->right = root->left;

            root->left = nullptr;

            invert(root->right);

            return;
        }

        TreeNode* temp = root->left;

        root->left = root->right;
        root->right = temp;

        invert(root->left);
        invert(root->right);

        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);

        return root;
    }
};
