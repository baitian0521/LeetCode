#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    inline int lengthOfLongestSubstring(string s) {
        const char *head = s.c_str();
        int len = s.size();
        int max = 1;
        if(len == 0){
            max = 0;
            return  max;
        }

        int cur = 1;
        int start = 0;

        for (int i = 1; i < len; i++) {
            bool isEqual = false;
            for (int j = start; j < i; j++) {
                if (start < len && head[j] == head[i]) {
                    start = j + 1;
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                if (max < cur) {
                    max = cur;
                }
                cur = i - start + 1;
            } else {
                cur++;
            }
        }
        if (max < cur) {
            max = cur;
        }
        return max;
    }

    inline static void test_solution() {
        string b = "a";
        Solution solution;
        int value = solution.lengthOfLongestSubstring(b);
        cout << value << endl;
    }
};