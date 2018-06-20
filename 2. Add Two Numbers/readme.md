解题思路:
循环遍历ListNode l1和listNode l2，和一个右边
依次相加每一个值:l1->val + l2->val +index，遍历自己的listNode,当l1或者l2遍历结束跳出循环，继续遍历l1或者l2的循环l1->val+index。