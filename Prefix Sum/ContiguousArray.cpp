#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
       int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        unordered_map<int, int> f;
        int res = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0) {
                zero++;
            }
            else{
                one++;
            }

            int diff = zero - one;

            if(diff == 0) {
                res = max(res, i+1);
                continue;
            }
            if(f.find(diff) == f.end()) {
                f[diff] = i;
            }
            else {
                int idx = f[diff];
                int len = i - idx;
                res = max(len, res);
            }
        }
        return res;
       }
};

int main () {
    Solution obj;
    vector<int> nums = {0, 1, 0, 1, 1, 1, 0, 0};
    int answer = obj.findMaxLength(nums);
    cout << "Maximum Length = " << answer << endl;
    return 0;
}