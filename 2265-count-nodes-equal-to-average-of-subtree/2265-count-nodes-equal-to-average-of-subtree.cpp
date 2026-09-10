class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // {sum, count} of left subtree
        auto left = dfs(root->left);

        // {sum, count} of right subtree
        auto right = dfs(root->right);

        // Sum and count of current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Integer division automatically floors the average
        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};