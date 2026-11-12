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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr) return true;

        if(!p and q) return false;

        if(p and !q) return false;

        if(p->val != q->val) return false;

        if(!q->right and !q->left and !p->right and !p->left) return true;

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
