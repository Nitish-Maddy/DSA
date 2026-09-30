#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k)
{
    int n = nums.size();
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> f;
    f[0] = 1;   //Remainder 0 has already appeared once

    for(int i=0; i<n; i++)
    {
        sum += nums[i];
        int rem = sum % k;

        //handle negative remainder
        if(rem < 0) {
            rem = rem + k;
        }

        //Same remainder means Subarray sum is divisible by k
        ans += f[rem];
        f[rem]++;  //store the remainder
    }
    return ans;
} 

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int answer = subarraysDivByK(nums, k);
    cout << "Number of Subarrays Divisible by " << k << " = "
    << answer << endl;
    return 0; 
}