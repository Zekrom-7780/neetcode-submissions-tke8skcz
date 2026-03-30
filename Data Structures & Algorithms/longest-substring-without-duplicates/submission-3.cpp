#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Optional: early return for empty string
        if (s.empty()) return 0;

        // Use 256 (extended ASCII) and index by unsigned char
        vector<int> present(256, 0);

        int i = 0, j = 0;
        int maxLen = 0;

        while (j < (int)s.size()) {
            unsigned char cj = static_cast<unsigned char>(s[j]);

            if (present[cj] == 0) {
                present[cj] = 1;
                maxLen = max(maxLen, j - i + 1);
                j++; 
            } else {
                unsigned char ci = static_cast<unsigned char>(s[i]);
                present[ci]--;
                i++;
            }
        }
        return maxLen;
    }
};