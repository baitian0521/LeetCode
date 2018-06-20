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
    vector<int> _vector;

    vector<int> postorderTraversal(TreeNode *root) {
        if (root == NULL) {
            return _vector;
        }
        if (root->left != NULL) {
            postorderTraversal(root->left);
        }
        if (root->right != NULL) {
            postorderTraversal(root->right);
        }
        _vector.push_back(root->val);
        return _vector;
    }
};