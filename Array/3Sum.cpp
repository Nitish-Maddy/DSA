#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;

        // Step 1: Sort the input array
        sort(nums.begin(), nums.end());

        //Store the unique triplets in a set to avoid duplicates
        set<vector<int>> s;
        vector<vector<int>> output;

        //Step 2:Fix the first number
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            //Step 3: Two Pointer
            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                //Found a triplet
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                //Sum is too small
                else if (sum < target) {
                    j++;
                }
                //Sum is too large
                else {
                    k--;
                }
            }
        }
        //Step 4: Convert set into vector
        for (auto triplets : s) {
            output.push_back(triplets);
        }

        return output;
    }
};

int main() {
    //test input
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution obj;

    //Call the function
   vector<vector<int>> result = obj.threeSum(nums);

   //Print result
   cout << "Triplets whose sum is 0:"<< endl;

   for (auto triplet : result) {
    cout << "[";

    for (int x : triplet) {
        cout << x << " ";
    }
        cout << "]" << endl;
   }
   return 0;
}