#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
      vector<vector<int>> ans;
      int n = nums.size();
      sort(nums.begin(), nums.end());

      //Step 1.Fix the first number
      for (int i=0; i<n-3; i++)
      {
        //Step 2. Skip the duplicate numbers
        if (i > 0 && nums[i] == nums[i-1])
        continue;

        //Step 3. Fix the second number
        for (int j = i+1; j < n-2; j++)
        {
            //Step 4. Skip duplicate second numbers
            if (j > i + 1 && nums[j] == nums[j-1])
            continue;

            // Step 4. Two pointers
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
               
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
               
                if(sum == target) {
                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right]
                    });

                    //Skip duplicate the third numbers
                    while(left < right && nums[left] == nums[left+1])
                    left++;

                    //Skip duplicate fourth numbers
                    while(left < right && nums[right] == nums[right - 1])
                    right --;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else{
                    right--;
                }
            }
        }
      }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    long long target = 0;

    vector<vector<int>> result = s.fourSum(nums, target);

    for (auto quad : result) {
        cout << "[ ";
        for (int x : quad) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}