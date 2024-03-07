class Solution {
private:
    int res = -1;
public:
    int helper(TreeNode* h) {
      if (!h) return 0;

      int l = helper(h->left);
      int r = helper(h->right);

      res = max(res, l + r);

      return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
      helper(root);
      return res;
    }
};

// topics: binary tree
// time complexity: O(n), space complexity: O(n)
