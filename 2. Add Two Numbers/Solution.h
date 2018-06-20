
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *b = NULL;
        ListNode *back = NULL;
        int value = 0;
        int index = 0;
        bool isFrist = false;

        while (l1 != NULL && l2 != NULL) {
            int sum = (l1->val + l2->val) + index;
            value = sum % 10;
            sum / 10 == 1 ? index = 1 : index = 0;
            if (back == NULL) {
                back = new ListNode(value);
                b = back;
            } else {
                back->next = new ListNode(value);
                back = back->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = (l1->val + 0) + index;
            value = sum % 10;
            sum / 10 == 1 ? index = 1 : index = 0;
            back->next = new ListNode(value);
            back = back->next;
            l1 = l1->next;
        }

        while (l2 != NULL) {
            int sum = (l2->val + 0) + index;
            value = sum % 10;
            sum / 10 == 1 ? index = 1 : index = 0;
            back->next = new ListNode(value);
            back = back->next;
            l2 = l2->next;
        }
        if (index != 0) {
            back->next = new ListNode(index);
            back = back->next;
        }
        return b;
    }
};