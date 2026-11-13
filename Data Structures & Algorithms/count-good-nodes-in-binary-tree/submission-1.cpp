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
    int count = 0;

    void goodFunction(TreeNode* root, int largestInPath){
        if(!root) return;

        if(root->val >= largestInPath){
            count++;
            largestInPath = root->val;
        }

        goodFunction(root->left, largestInPath);

        goodFunction(root->right, largestInPath);
    }

    int goodNodes(TreeNode* root) {
        goodFunction(root, root->val);

        return count;
    }
};
