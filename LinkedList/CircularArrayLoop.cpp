#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    //Function to calculate the next index
    //The second % n handles negative results correctly in C++
      int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
      }

      bool circularArrayLoop(vector<int>& nums) 
      {
        int n = nums.size();

        //we iterate through each index as a potential start of a cycle
        for (int i = 0; i < n; i++) {
         // true = forward, false = backward
            bool forward = nums[i] > 0;
            int slow =  i;
            int fast = i;

            while(true) {
                //Move slow one step
                int nextSlow = nextIndex(nums, slow);

                //Direction changed
                if ((nums[nextSlow] > 0) != forward)
                break;

                slow = nextSlow;

                //Move fast one step
                int nextFast = nextIndex(nums, fast);

                //Direction changed
                if((nums[nextFast] > 0) != forward)
                break;

                //Move fast second step
                nextFast = nextIndex(nums, nextFast);

                //direction changed
                if((nums[nextFast] > 0) != forward)
                break;

                fast = nextFast;   //Move pointer


                //Cycle found
                if (slow == fast) {
                    //Cycle of length 1 is not allowed
                    if(slow == nextIndex(nums, slow))
                    break;

                    return true;
                }
            }
        }

          return false;

      }
};

int main () {
    Solution s;

    vector<int> nums = {2, -1, 1, 2, 2};

    if(s.circularArrayLoop(nums))
    cout << "true" << endl;
    else
    cout << "false" << endl;

    return 0;
}