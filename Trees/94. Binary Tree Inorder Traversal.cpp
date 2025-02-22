#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
//     vector<int> result;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return result;
//     }
// private:
//     void inorder(TreeNode* node) {
//         if (!node) return;
//         result.push_back(node->val);
//         inorder(node->left);
//         inorder(node->right);
//     }
// };

class Solution {
    vector<int> result;

public:
    vector<int> inorderTraversal(TreeNode* root) {

        TreeNode* temp = root;

        stack<TreeNode*> TreeStack;

        while(!TreeStack.empty() || temp!= NULL)
        {
            while (temp!= NULL)
            {
                TreeStack.push(temp);
                temp = temp->left;
            }

            temp = TreeStack.top();
            TreeStack.pop();

            result.push_back(temp->val);

            temp = temp->right;

        }


        return result;
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


// https://neetcode.io/solutions/binary-tree-inorder-traversal