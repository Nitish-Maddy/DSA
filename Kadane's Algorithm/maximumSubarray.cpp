#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

   int maxSubArray(vector<int>& nums)
   {
    int n = nums.size();
    int bestending = nums[0];
    int ans = nums[0];

    for(int i = 0; i < n; i++) {
        int v1 = bestending + nums[i];
        int v2 = nums[i];

        bestending = max(v1, v2);
        ans = max(ans, bestending);
    }

    return ans;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, 5, -4};
    int answer = maxSubArray(nums);
    cout << "Maximum Subarray sum = " << answer << endl;
    return 0;
}