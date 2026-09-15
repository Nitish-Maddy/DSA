#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
   int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = -1;
    int right = -1;

    //Step 1: find the first wrong position from left
    for (int i=0; i<n-1; i++) {
      if (nums[i] > nums[i+1]) {
        left = i;
        break;
      }
    }
     //Already Sorted
      if (left == -1){
        return 0;
      };

      //Step 2: Find the first wrong position from right
      for (int i = n-1; i > 0; i--){
        if(nums[i] < nums[i - 1]) {
            right = i;
            break;
        }
      }

      //Step 3: find minimum and maximum
      //inside the initially unsorted part
      int mini = nums[left];
      int maxi = nums[left];

      for (int i = left; i <= right; i++) {
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
      }

      //Step 4: Expand the left if needed
       while (left > 0 && nums[left - 1] > mini) {
        left--;
       }

       //Step 5: Expand right if needed
       while (right < n-1 && nums[right + 1] < maxi) {
        right++;
       }
       return right - left + 1;
   }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout<< obj.findUnsortedSubarray(nums);
    return 0;
}