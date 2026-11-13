class Solution {
public:
    void inorder(TreeNode* root, int& k, int& cnt, int& result) {
        if (!root || cnt >= k) return;

        // 1. Traverse left subtree
        inorder(root->left, k, cnt, result);

        // 2. Visit current node
        cnt++;
        if (cnt == k) {
            result = root->val;
            return;
        }

        // 3. Traverse right subtree
        inorder(root->right, k, cnt, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int result = -1;
        inorder(root, k, cnt, result);
        return result;
    }
};