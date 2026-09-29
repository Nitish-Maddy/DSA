#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    int sum = 0;  //current prefix sum
    int res = 0;  //Number of subarray whose sum is k

    unordered_map<int, int> f;
    //Prefix sum 0 has occurred once before we start
    f[0] = 1;

    for (int i = 0; i < n; i++)
    {
        //Add current element to prefix sum
        sum += nums[i];

        //We need an old prefix sum = current sum - k
        int ques = sum - k;

        //How many times has that prefix sum appeared?
        int freq = f[ques];

        //Every occurence creates one valid subarray
        res += freq;

        //Store the current prefix sum
        f[sum]++;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int answer = subarraySum(nums, k);
    cout << "Number of subarrays: " << answer << endl;
    return 0;
}