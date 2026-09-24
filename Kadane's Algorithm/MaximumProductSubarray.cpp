#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaximumProductSubarray(vector<int> &nums)
{
    int n = nums.size();
    int minending = nums[0];
    int maxending = nums[0];
    int res = nums[0];

    for(int i = 1; i < n; i++)
    {
        int v1 = nums[i];
        int v2 = minending * nums[i];
        int v3 = maxending * nums[i];

        maxending = max(v1, max(v2, v3));
        minending = min(v1, min(v2, v3));
        res = max(res, max(maxending, minending));
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    int answer = MaximumProductSubarray(nums);
    cout << "Maximum Product Subarray = " << answer << endl;
    return 0;
}