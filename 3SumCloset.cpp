#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    public:
    int threeSumCloset(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n-2; i++) {

            int left = i+1;
            int right = n-1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                //Checks whether this sum closer to target than the previous closest sum
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }

                //Move the pointers based on the comparison of sum and target
                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = solution.threeSumCloset(nums, target);
    cout << "The closest sum is: " << result << endl;

    return 0;
}
