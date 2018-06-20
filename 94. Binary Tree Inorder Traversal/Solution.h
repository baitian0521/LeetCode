#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> b;

    vector<int> inorderTraversal(TreeNode *root) {
        if (root == NULL) {
            return vector<int>{};
        }
        if (root->left != NULL) {
            inorderTraversal(root->left);
        }
        b.push_back(root->val);
        if (root->right != NULL) {
            inorderTraversal(root->right);
        }
        return b;
    }
};