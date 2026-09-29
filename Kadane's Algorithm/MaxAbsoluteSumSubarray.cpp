#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    public:
      int maxAbsoluteSum(vector<int> & nums) {
        int max_end = 0;
        int max_sum = INT_MIN;

        int min_end = 0;
        int min_sum = INT_MAX;

        for(int x : nums) {
            //Maximum Subarray sum
            max_end = max(x, max_end + x);
            max_sum = max(max_sum, max_end);

            //Minimum Subarrray sum
            min_end = min(x, min_end + x);
            min_sum = min(min_sum, min_end);
        }
        return max(abs(max_sum), abs(min_sum));
      }
};

int main() {
    Solution obj;
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << obj.maxAbsoluteSum(nums) << endl;
    return 0;
}