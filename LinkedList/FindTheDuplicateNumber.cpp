#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
       int findDuplicate(vector<int>& nums) {
          int slow = nums[0];
          int fast = nums[0];

          while (true)
          {
            slow = nums[slow];
            fast = nums[nums[fast]];  // fast moves two step

            //Both pointers meet
            if (slow == fast) {
                break;
            }
          }

          //Find the starting point of cycle (meeting point)   
          slow = nums[0];

          while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
          }
           
          //The meeting point is the duplicate number
          return slow;
       }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    Solution obj;
    int answer = obj.findDuplicate(nums);
    cout << "Duplicate number = "<< answer << endl;
    return 0;
}