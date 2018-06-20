//
// Created by baitian0521 on 2018/6/20.
//

#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> merge(queue<TreeNode *> &desk, queue<TreeNode *> &src) {
        vector<int> _vector;
        while (!src.empty()) {
            TreeNode *temp = src.front();
            src.pop();
            _vector.push_back(temp->val);
            desk.push(temp);
        }
        return _vector;
    }

    vector <vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> temp_vector;
        queue < TreeNode * > level_queue;
        queue < TreeNode * > temp_queue;
        if (root == NULL) {
            return temp_vector;
        }
        level_queue.push(root);
        vector<int> b;
        b.push_back(root->val);
        temp_vector.push_back(move(b));
        while (!level_queue.empty()) {
            TreeNode *note = level_queue.front();
            level_queue.pop();
            if (note->left != NULL) {
                temp_queue.push(note->left);
            }
            if (note->right != NULL) {
                temp_queue.push(note->right);
            }
            if (level_queue.empty()) {
                vector<int> t = merge(level_queue, temp_queue);
                if (!t.empty())
                    temp_vector.push_back(t);
            }
        }
        return temp_vector;
    }
};