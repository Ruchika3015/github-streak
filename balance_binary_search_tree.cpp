class Solution {
public:
    vector<int> inorderVals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildBalanced(int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorderVals[mid]);

        root->left = buildBalanced(left, mid - 1);
        root->right = buildBalanced(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildBalanced(0, inorderVals.size() - 1);
    }
};
