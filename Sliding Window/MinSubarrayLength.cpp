#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minSubarrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {

        //Add the new element to the window
        sum += nums[right];

        // Window is valid, so try to make it smaller
        while (sum >= target) {

            //Current window length
            ans = min(ans, right - left + 1);

            //Remove left element
            sum -= nums[left];
            left++;
        }
    }
    //If no valid subarray was found
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubarrayLen(target, nums);

    cout << "Minimum subarray length = " << result << endl;
    return 0;
}