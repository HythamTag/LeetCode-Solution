#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
private:
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        result.push_back(node->val);
        inorder(node->right);
    }
};

int main() {
    // Example binary tree:
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Output: 1 3 2
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}