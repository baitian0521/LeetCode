//
// Created by baitian0521 on 2018/6/20.
//

#pragma once

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode *getListNode(ListNode *head, int index) {
    ListNode *cur = head;
    ListNode *back = NULL;
    int temp_index = 0;
    while (cur != NULL) {
        if (temp_index == index) {
            back = cur;
            break;
        }
        temp_index++;
        cur = cur->next;
    }
    return back;
}

TreeNode *divide_array(int start, int end, ListNode *head) {

    TreeNode *node = NULL;
    int middle = (start + end + 1) / 2;
    if (start == end) {
        ListNode *cur = getListNode(head, start);
        node = new TreeNode(cur->val);
        return node;
    } else {
        ListNode *cur = getListNode(head, middle);
        node = new TreeNode(cur->val);
    }

    if (start <= middle - 1)
        node->left = divide_array(start, middle - 1, head);
    if (end >= middle + 1)
        node->right = divide_array(middle + 1, end, head);
    return node;
}

TreeNode *sortedListToBST(ListNode *head) {
    ListNode *curr = head;
    int length = 0;
    while (curr != NULL) { //获取长度
        curr = curr->next;
        length++;
    }
    TreeNode *back = NULL;
    if (length > 0)
        back = divide_array(0, length - 1, head); //递归
    return back;
}

//测试案例
void test_solution(){
    ListNode *head = new ListNode(-10);
    ListNode *cur = head;
    cur->next = new ListNode(-3);
    cur = cur->next;
    cur->next = new ListNode(0);
    cur = cur->next;
    cur->next = new ListNode(5);
    cur = cur->next;
    cur->next = new ListNode(9);
    sortedListToBST(head);
};