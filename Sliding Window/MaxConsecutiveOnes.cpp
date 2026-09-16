#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
   int longestOnes(vector<int>& nums, int k) {
    int low = 0;
    int high = 0;
    int zeros = 0;
    int ans = 0;

    while (high < nums.size()) {   // Keep moving high until it reaches the end of the array.
       if (nums[high] == 0){
        zeros++;
       }

       //If zeros become more than k
       // shrink the window from low
       while (zeros > k) {
        if(nums[low] == 0) {
            zeros--;
        }
        low++;
       }

       //Current valid window length
       ans = max(ans, high - low + 1);

       //Move high forward
       high++;
    }
    return ans;
   }
};

int main() {
    Solution obj;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << obj.longestOnes(nums, k);
    return 0;
}