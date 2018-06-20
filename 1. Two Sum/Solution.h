#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> temp_vector;
        for (int i = 0; i < nums.size(); i++) {
            int first = i;
            for (int j = i + 1; j < nums.size(); j++) {
                int second = j;
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    temp_vector.push_back(i);
                    temp_vector.push_back(j);
                    goto end;
                }
            }
        }
        end :
        return temp_vector;
    }
};