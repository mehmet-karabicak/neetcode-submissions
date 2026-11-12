class Solution {
private:
    int maxDiameter = 0;

    int calculateHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // Diameter through the current node is left + right height
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        calculateHeight(root);
        return maxDiameter;
    }
};