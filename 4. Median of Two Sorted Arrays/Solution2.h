//
// Created by baitian0521 on 2018/6/20.
//

#pragma once
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        double back = 0;
        if (len_1 == 0 && len_2 == 0) {
            return back;
        }
        int middle1 = (len_1 + len_2) / 2;
        vector<int> middle_vector;
        bool isTwo = (len_1 + len_2) % 2 == 0 ? true : false;

        if (isTwo) {
            middle1 -= 1;
        }

        int start1 = 0;
        int start2 = 0;
        int cur = 0;
        bool isfinish = false;
        while (start1 < len_1 && start2 < len_2) {
            bool isNums1;
            int temp;
            if (nums1[start1] < nums2[start2]) {
                isNums1 = true;
                temp = start1;
                start1++;
            } else {
                isNums1 = false;
                temp = start2;
                start2++;
            }
            if (cur == middle1) {
                int value = isNums1 ? nums1[temp] : nums2[temp];
                middle_vector.push_back(value);
                if (isTwo && middle_vector.size() < 2) {
                    middle1 += 1;
                } else {
                    isfinish = true;
                    break;
                }
            }
            cur++;
        }
        int num = middle_vector.size();
        if (!isfinish) {
            while (start1 < len_1) {
                if (cur == middle1) {
                    int value = nums1[start1];
                    middle_vector.push_back(value);
                    if (isTwo && middle_vector.size() < 2) {
                        middle1 += 1;
                    } else {
                        break;
                    }
                }
                start1++;
                cur++;
            }

            while (start2 < len_2) {
                if (cur == middle1) {
                    int value = nums2[start2];
                    middle_vector.push_back(value);
                    if (isTwo && middle_vector.size() < 2) {
                        middle1 += 1;
                    } else {
                        break;
                    }
                }
                start2++;
                cur++;
            }
        }
        if (isTwo) {
            back = ((double) middle_vector[0] + (double) middle_vector[1]) / 2;
        } else {
            back = middle_vector[0];
        }
        return back;
    }
};