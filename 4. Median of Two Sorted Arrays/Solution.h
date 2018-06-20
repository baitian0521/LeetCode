#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
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
        bool finish1 = false, finish2 = false;
        while (start1 < len_1 || start2 < len_2) {
            bool isNums1 = false;
            int temp = -1;
            if (start1 == len_1) {
                finish1 = true;
            }
            if (start2 == len_2) {
                finish2 = true;
            }

            if (!finish1 && !finish2) {
                if (nums1[start1] < nums2[start2]) {
                    isNums1 = true;
                    temp = start1;
                    start1++;

                } else {
                    isNums1 = false;
                    temp = start2;
                    start2++;

                }
            }

            int value = 0;
            bool isValue = false;
            if (finish1) {
                int index = middle1 - cur + start2;
                value = nums2[index];
                isValue = true;
            } else if (finish2) {
                int index = middle1 - cur + start1;
                value = nums1[index];
                isValue = true;
            } else if (cur == middle1) {
                value = isNums1 ? nums1[temp] : nums2[temp];
                isValue = true;
            }
            if (isValue) {
                middle_vector.push_back(value);
                if (isTwo && middle_vector.size() < 2) {
                    middle1 += 1;
                } else {
                    break;
                }
            }
            if (!finish1 && !finish2)
                cur++;
        }
        if (isTwo) {
            back = ((double) middle_vector[0] + (double) middle_vector[1]) / 2;
        } else {
            back = middle_vector[0];
        }
        return back;
    }

    inline static void test_solution() {
        vector<int> nums1{1, 3};
        vector<int> nums2{2};
        Solution solution;
        double value = solution.findMedianSortedArrays(nums1, nums2);
        cout << value << endl;
    }
};